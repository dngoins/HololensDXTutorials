#include "pch.h"
#include "Utility.h"

using namespace WinRT_AudioRecording;
using namespace Platform;

using namespace winrt;
using namespace Microsoft::WRL;

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
		
	// Configure user based properties
	CAPTUREDEVICEPROPS props;
	props.IsLowLatency = true;
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

