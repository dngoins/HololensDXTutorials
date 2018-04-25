#pragma once
#include <wrl.h>
#include <HolographicStreamer.h>
#include <Microsoft.Perception.Simulation.h>
#include <vector>

using namespace Microsoft;
using namespace Microsoft::Holographic;


class FrameGeneratedCallbackWrapper
	: public WRL::RuntimeClass<
	WRL::RuntimeClassFlags<WRL::ClassicCom>,
	IPerceptionSimulationFrameGeneratedCallback,
	WRL::FtmBase>
{
public:
	HRESULT RuntimeClassInitialize()
	{
		//
		return S_OK;
	}

	STDMETHODIMP FrameGenerated(_In_ IPerceptionSimulationFrame* frame) override
	{
		return S_OK;
	}

private:

};
