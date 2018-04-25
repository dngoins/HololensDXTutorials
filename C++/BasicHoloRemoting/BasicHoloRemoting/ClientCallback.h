#pragma once
#include <wrl.h>
#include <HolographicStreamer.h>
#include <Microsoft.Perception.Simulation.h>
#include <vector>

using namespace Microsoft;
using namespace Microsoft::Holographic;

class ClientCallback
	: public WRL::RuntimeClass<
	WRL::RuntimeClassFlags<WRL::ClassicCom>,
	IHolographicStreamerClientCallback,
	WRL::FtmBase>
{
public:
	HRESULT RuntimeClassInitialize()
	{		
		return S_OK;
	}

	//!\brief Called when connection has been established
	STDMETHODIMP Connected() override
	{
		return S_OK;
	}

	//!\brief Called when the connection has been terminated
	STDMETHODIMP Disconnected(_In_ HolographicStreamerConnectionFailureReason failureReason) override
	{
		return S_OK;
	}

	//!\brief Called when a new application data channel has been established
	STDMETHODIMP DataChannelCreated(_In_ IHolographicStreamerDataChannel* channel, _In_ UINT8 channelId) override
	{
		return S_OK;
	}

private:
	
};

