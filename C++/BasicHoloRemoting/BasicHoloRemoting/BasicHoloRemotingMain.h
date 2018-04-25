#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Content\Sample3DSceneRenderer.h"
#include "Content\SampleFpsTextRenderer.h"

#include <wrl.h>

#include <HolographicStreamer.h>
#include <Microsoft.Perception.Simulation.h>







#include <windows.graphics.h>
#include <windows.graphics.holographic.h>
#include <windows.perception.h>
#include <windows.perception.spatial.h>
#include <windows.perception.spatial.surfaces.h>

using namespace Microsoft::WRL;
using namespace BasicHoloRemoting;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Concurrency;
using namespace Microsoft::Holographic;
using namespace std;


using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Graphics::Holographic;
using namespace ABI::Windows::Graphics;
using namespace ABI::Windows::Perception;
using namespace ABI::Windows::Perception::Spatial;
using namespace ABI::Windows::Perception::Spatial::Surfaces;

// Renders Direct2D and 3D content on the screen.
namespace BasicHoloRemoting
{
	class BasicHoloRemotingMain : public DX::IDeviceNotify
	{
	public:
		BasicHoloRemotingMain(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		~BasicHoloRemotingMain();
		void CreateWindowSizeDependentResources();
		void Update();
		bool Render();

		// IDeviceNotify
		virtual void OnDeviceLost();
		virtual void OnDeviceRestored();
		
		//taken from helper class w/o C++/CX
		void CreateStreamer(ID3D11Device* device)
		{
			ComPtr<ClientCallback> spClientCallback;
			MakeAndInitialize<ClientCallback>(&spClientCallback, this);
			CreateHolographicStreamerClient(spClientCallback.Get(),	device,	IID_PPV_ARGS(&m_streamerClient));
		}

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// TODO: Replace with your own content renderers.
		std::unique_ptr<Sample3DSceneRenderer> m_sceneRenderer;
		std::unique_ptr<SampleFpsTextRenderer> m_fpsTextRenderer;

		// Rendering loop timer.
		DX::StepTimer m_timer;
		WRL::ComPtr<IHolographicStreamerClient> m_streamerClient;

	};
}