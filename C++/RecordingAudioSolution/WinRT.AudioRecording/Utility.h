#pragma once

#include "pch.h"
#include "WASAPICapture.h"
#include "DeviceState.h"

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

    public:
		//members


		//methods
        Utility( Platform::String ^ _fileName);
		
		void StartCapture();
		void StopCapture();
		

    };
}
