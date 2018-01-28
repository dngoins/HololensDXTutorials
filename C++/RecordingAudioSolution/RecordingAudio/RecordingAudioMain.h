#pragma once

//
// Comment out this preprocessor definition to disable all of the
// sample content.
//
// To remove the content after disabling it:
//     * Remove the unused code from your app's Main class.
//     * Delete the Content folder provided with this template.
//
#define DRAW_SAMPLE_CONTENT

#include "Common\DeviceResources.h"
#include "Common\StepTimer.h"

#ifdef DRAW_SAMPLE_CONTENT
#include "Content\SpinningCubeRenderer.h"
#include "Content\SpatialInputHandler.h"
#endif

//#include "Content\ModelRenderer.h"

#include "WASAPICapture.h"

#define OSC_START_X  100
#define OSC_START_Y  100
#define OSC_X_LENGTH 700
#define OSC_TOTAL_HEIGHT 200


// Updates, renders, and presents holographic content using Direct3D.
namespace RecordingAudio
{
	public enum class NotifyType
	{
		StatusMessage,
		ErrorMessage
	};

    class RecordingAudioMain : public DX::IDeviceNotify
    {
    public:
        RecordingAudioMain(const std::shared_ptr<DX::DeviceResources>& deviceResources);
        ~RecordingAudioMain();

        // Sets the holographic space. This is our closest analogue to setting a new window
        // for the app.
        void SetHolographicSpace(Windows::Graphics::Holographic::HolographicSpace^ holographicSpace);

        // Starts the holographic frame and updates the content.
        Windows::Graphics::Holographic::HolographicFrame^ Update();

        // Renders holograms, including world-locked content.
        bool Render(Windows::Graphics::Holographic::HolographicFrame^ holographicFrame);

        // Handle saving and loading of app state owned by AppMain.
        void SaveAppState();
        void LoadAppState();

        // IDeviceNotify
        virtual void OnDeviceLost();
        virtual void OnDeviceRestored();
		void OnDeviceStateChange(Platform::Object^ sender, DeviceStateChangedEventArgs^ e);


    private:
        // Asynchronously creates resources for new holographic cameras.
        void OnCameraAdded(
            Windows::Graphics::Holographic::HolographicSpace^ sender,
            Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs^ args);

        // Synchronously releases resources for holographic cameras that are no longer
        // attached to the system.
        void OnCameraRemoved(
            Windows::Graphics::Holographic::HolographicSpace^ sender,
            Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs^ args);

        // Used to notify the app when the positional tracking state changes.
        void OnLocatabilityChanged(
            Windows::Perception::Spatial::SpatialLocator^ sender,
            Platform::Object^ args);

        // Clears event registration state. Used when changing to a new HolographicSpace
        // and when tearing down AppMain.
        void UnregisterHolographicEventHandlers();
		void InitializeAudio();
		void InitializeCapture(Platform::Object^ sender, Platform::Object^ e);
		void StopCapture(Platform::Object^ sender, Platform::Object^ e);
		void StartCapture(Platform::Object^ sender, Platform::Object^ e);
		void UpdateMediaControlUI(DeviceState deviceState);
		
		// UI Helpers
		void ShowStatusMessage(Platform::String^ str, NotifyType messageType);


#ifdef DRAW_SAMPLE_CONTENT
        // Renders a colorful holographic cube that's 20 centimeters wide. This sample content
        // is used to demonstrate world-locked rendering.
        std::unique_ptr<SpinningCubeRenderer>                           m_spinningCubeRenderer;

		//std::unique_ptr<ModelRenderer>                               m_modelRenderer;

        // Listens for the Pressed spatial input event.
        std::shared_ptr<SpatialInputHandler>                            m_spatialInputHandler;
#endif

        // Cached pointer to device resources.
        std::shared_ptr<DX::DeviceResources>                            m_deviceResources;

        // Render loop timer.
        DX::StepTimer                                                   m_timer;

        // Represents the holographic space around the user.
        Windows::Graphics::Holographic::HolographicSpace^               m_holographicSpace;

        // SpatialLocator that is attached to the primary camera.
        Windows::Perception::Spatial::SpatialLocator^                   m_locator;

        // A reference frame attached to the holographic camera.
        Windows::Perception::Spatial::SpatialStationaryFrameOfReference^ m_referenceFrame;

        // Event registration tokens.
        Windows::Foundation::EventRegistrationToken                     m_cameraAddedToken;
        Windows::Foundation::EventRegistrationToken                     m_cameraRemovedToken;
        Windows::Foundation::EventRegistrationToken                     m_locatabilityChangedToken;
	
		Windows::UI::Core::CoreDispatcher^              m_CoreDispatcher;
		Windows::UI::Xaml::Shapes::Polyline^            m_Oscilloscope;

		Windows::Foundation::EventRegistrationToken     m_deviceStateChangeToken;
		Windows::Foundation::EventRegistrationToken     m_plotDataReadyToken;

		int                         m_DiscontinuityCount;
		Platform::Boolean           m_IsMFLoaded;
		Platform::Boolean           m_IsLowLatency;

		DeviceStateChangedEvent^    m_StateChangedEvent;
		ComPtr<WASAPICapture>       m_spCapture;
		
	public:
		Platform::Boolean			m_showRecording;

    };
}
