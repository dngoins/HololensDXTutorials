#pragma once

#include "pch.h"
#include "WASAPICapture.h"
#include "DeviceState.h"
#include <windows.graphics.h>
#include <windows.graphics.holographic.h>
#include <windows.foundation.h>

using namespace Platform;

namespace WinRT_AudioRecording
{
	public ref class Utility sealed 
    {

	private:
		//members
		std::wstring fileName;
		bool m_IsMFLoaded;
		DeviceStateChangedEvent^    m_StateChangedEvent;
		ComPtr<WASAPICapture>       m_spCapture;
		//ComInit						comStart;
		
		
		//methods
		void InitializeAudio();
		void InitializeCapture();
		void _startCapture();
		void _stopCapture();
		~Utility();
		void UpdateMediaControlUI(DeviceState deviceState);

    public:
		//members


		//methods
        Utility( Platform::String ^ _fileName);		
		void StartCapture();
		void StopCapture();
		void OnStateChangedEvent(Platform::Object ^sender, WinRT_AudioRecording::DeviceStateChangedEventArgs ^e);

	};
}
