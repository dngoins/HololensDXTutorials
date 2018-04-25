#include "pch.h"
#include "Utility.h"


using namespace WinRT_AudioRecording;
using namespace Platform;

using namespace winrt;
using namespace Microsoft::WRL;

using namespace Platform;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Foundation::Numerics;
using namespace ABI::Windows::Graphics::Holographic;
using namespace ABI::Windows::Globalization;

using namespace std::placeholders;


Utility::Utility( Platform::String ^ _fileName) : fileName(_fileName->Begin(), _fileName->End()),
	m_IsMFLoaded(false)
{
	InitializeAudio();
	InitializeCapture();
}

Utility::~Utility()
{
	m_StateChangedEvent = nullptr;

	if (m_spCapture)
		m_spCapture.Reset();
	m_spCapture = nullptr;

	if (m_IsMFLoaded)
	{
		auto hr = MFShutdown();
		if (!SUCCEEDED(hr))
		{
			TRACE(L"Failed to properly shut down MediaFoundation %d\n", hr);
			//ThrowIfFailed(hr);
		}
		m_IsMFLoaded = false;
	}
}

void Utility::InitializeAudio()
{
	// Initialize MF
	HRESULT hr = MFStartup(MF_VERSION, MFSTARTUP_LITE);
	if (SUCCEEDED(hr))
	{
		m_IsMFLoaded = true;
	}
	else
	{
		TRACE(L"Failed to start Media Foundation %d\n", hr);
		ThrowIfFailed(hr);
	}
	TRACE(L"MediaFoundation is Initialized\n");
}

void Utility::InitializeCapture()
{
	HRESULT hr = S_OK;
	if (m_spCapture)
	{
		m_spCapture = nullptr;
	}

	// Create a new WASAPI capture instance
	m_spCapture = Make<WASAPICapture>();

	if (nullptr == m_spCapture)
	{
		TRACE(L"Failed to create WASAPI Capture\n");
		ThrowIfFailed(E_OUTOFMEMORY);		
	}

	// Get a pointer to the device event interface
	m_StateChangedEvent = m_spCapture->GetDeviceStateEvent();

	if (nullptr == m_StateChangedEvent)
	{
		TRACE(L"Failed to create Device State listener\n");
		ThrowIfFailed(E_FAIL);
	}

	auto token = m_StateChangedEvent->StateChangedEvent += ref new WinRT_AudioRecording::DeviceStateChangedHandler(this, &WinRT_AudioRecording::Utility::OnStateChangedEvent);

	

	// Configure user based properties
	CAPTUREDEVICEPROPS props;
	props.IsLowLatency = false;
	hr = m_spCapture->SetProperties(props);
	if (!SUCCEEDED(hr))
	{	
		TRACE(L"Failed to set properties on WASAPI Capture device %d\n", hr);
		ThrowIfFailed(hr);
	}
	// Perform the initialization
	hr = m_spCapture->InitializeAudioDeviceAsync();
	if (!SUCCEEDED(hr))
	{
		TRACE(L"Failed to Initialize Audio Device %d\n", hr);
		ThrowIfFailed(hr);
	}

	TRACE(L"Audio Device and Audio Capture initialized\n");
}

void Utility::StartCapture()
{
	if (m_spCapture)
	{
		_startCapture();
	}
	else
	{
		InitializeAudio();
		InitializeCapture();
		_startCapture();
	}
}

void Utility::_startCapture()
{
	_ASSERT(m_spCapture);
	auto hr = m_spCapture->StartCaptureAsync();
	if (!SUCCEEDED(hr))
	{
		TRACE(L"Failed to start capturing sounds %d\n", hr);
		ThrowIfFailed(hr);
	}
	TRACE(L"Microphone is listening\n");
}

void Utility::StopCapture()
{
	if (m_spCapture)
	{
		_stopCapture();
	}
	else
	{
		InitializeAudio();
		InitializeCapture();
		_stopCapture();
	}
}

void Utility::_stopCapture()
{
	_ASSERT(m_spCapture);
	auto hr = m_spCapture->StopCaptureAsync();
	if (!SUCCEEDED(hr))
	{
		TRACE(L"Failed to stop capturing %d\n", hr);
		ThrowIfFailed(hr);
	}
	TRACE(L"Capture has stopped\n"); 

	hr = m_spCapture->FinishCaptureAsync();
	if (!SUCCEEDED(hr))
	{
		TRACE(L"Failed to flush capture %d\n", hr);
		//ThrowIfFailed(hr);
	}
	TRACE(L"Capture has flushed\n");

}


void WinRT_AudioRecording::Utility::OnStateChangedEvent(Platform::Object ^sender, WinRT_AudioRecording::DeviceStateChangedEventArgs ^e)
{		
	// Handle state specific messages
	switch (e->State)
	{
	case DeviceState::DeviceStateInitialized:
		//m_spCapture->StartCaptureAsync();
		TRACE(L"Device is Initialized and ready...\n");
		break;

	case DeviceState::DeviceStateCapturing:	
		TRACE(L"Capture Started (minimum latency) \n");			
		break;

	case DeviceState::DeviceStateDiscontinuity:
	{
		TRACE(L"Discontinuity...\n");
	}
	break;

	case DeviceState::DeviceStateFlushing:
		TRACE(L"Device state flushing\n");
		break;

	case DeviceState::DeviceStateStopped:
		// For the stopped state, completely tear down the audio device
		m_spCapture = nullptr;
		m_spCapture.Reset();
		
		TRACE(L"Device stopped\n");
		break;

	case DeviceState::DeviceStateInError:
		HRESULT hr = e->hr;
				
		m_spCapture = nullptr;
		m_spCapture.Reset();

		//wchar_t hrVal[11];
		//swprintf_s(hrVal, 11, L"0x%08x\0", hr);
		//String^ strHRVal = ref new String(hrVal);

		// Specifically handle a couple of known errors
		switch (hr)
		{
		case __HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND):
			TRACE(L"ERROR: File Not Found (%d)\n Check the Sound control panel for an active recording device.\n", hr);
			break;

		case AUDCLNT_E_RESOURCES_INVALIDATED:
			TRACE(L"ERROR: Endpoint Lost Access To Resources (%d)\n", hr);			
			break;

		case E_ACCESSDENIED:
			TRACE(L"ERROR: Access Denied (%d)\nCheck 'Settings->Permissions' for access to Microphone.\n", hr);			
			break;

		default:
			TRACE(L"Error: %d\n", hr);
			break;
			
		}
	}
}

void WinRT_AudioRecording::Utility::UpdateMediaControlUI(DeviceState deviceState)
{
	switch (deviceState)
	{
	case DeviceState::DeviceStateCapturing:
		//btnStartCapture->IsEnabled = false;
		//btnStopCapture->IsEnabled = true;
		//toggleMinimumLatency->IsEnabled = false;
		break;

	case DeviceState::DeviceStateStopped:
		//btnStartCapture->IsEnabled = true;
		//btnStopCapture->IsEnabled = false;
		//toggleMinimumLatency->IsEnabled = true;
		break;

	case DeviceState::DeviceStateInitialized:
	case DeviceState::DeviceStateStarting:
	case DeviceState::DeviceStateStopping:
	case DeviceState::DeviceStateFlushing:
	case DeviceState::DeviceStateInError:
		//btnStartCapture->IsEnabled = false;
		//btnStopCapture->IsEnabled = false;
		break;
	}
}