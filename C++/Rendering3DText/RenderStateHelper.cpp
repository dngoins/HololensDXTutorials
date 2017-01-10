#include "pch.h"
#include "RenderStateHelper.h"

namespace DisplayingText
{
	RenderStateHelper::RenderStateHelper(ID3D11DeviceContext3* const deviceContext) : mDeviceContext(deviceContext), mRasterizerState(nullptr), mBlendState(nullptr), mBlendFactor(new FLOAT[4]), mSampleMask(UINT_MAX), mDepthStencilState(nullptr), mStencilRef(UINT_MAX)
	{
	}


	RenderStateHelper::~RenderStateHelper()
	{
		ReleaseObject(mRasterizerState);
		ReleaseObject(mBlendState);
		ReleaseObject(mDepthStencilState);
		ReleaseObject(mDeviceContext);
		DeleteObjects(mBlendFactor);
	}

	void RenderStateHelper::ResetAll(ID3D11DeviceContext3* const deviceContext)
	{
		deviceContext->RSSetState(nullptr);
		deviceContext->OMSetBlendState(nullptr, nullptr, UINT_MAX);
		deviceContext->OMSetDepthStencilState(nullptr, UINT_MAX);
	}

	ID3D11RasterizerState* RenderStateHelper::RasterizerState()
	{
		return mRasterizerState;
	}

	ID3D11BlendState* RenderStateHelper::BlendState()
	{
		return mBlendState;
	}

	ID3D11DepthStencilState* RenderStateHelper::DepthStencilState()
	{
		return mDepthStencilState;
	}

	void RenderStateHelper::SaveRasterizerState()
	{
		ReleaseObject(mRasterizerState);
		mDeviceContext->RSGetState(&mRasterizerState);
	}

	void RenderStateHelper::RestoreRasterizerState() const
	{
		mDeviceContext->RSSetState(mRasterizerState);
	}

	void RenderStateHelper::SaveBlendState()
	{
		ReleaseObject(mBlendState);
		mDeviceContext->OMGetBlendState(&mBlendState, mBlendFactor, &mSampleMask);
	}

	void RenderStateHelper::RestoreBlendState() const
	{
		mDeviceContext->OMSetBlendState(mBlendState, mBlendFactor, mSampleMask);
	}

	void RenderStateHelper::SaveDepthStencilState()
	{
		ReleaseObject(mDepthStencilState);
		mDeviceContext->OMGetDepthStencilState(&mDepthStencilState, &mStencilRef);
	}

	void RenderStateHelper::RestoreDepthStencilState() const
	{
		mDeviceContext->OMSetDepthStencilState(mDepthStencilState, mStencilRef);
	}

	void RenderStateHelper::SaveAll()
	{
		SaveRasterizerState();
		SaveBlendState();
		SaveDepthStencilState();
	}

	void RenderStateHelper::RestoreAll() const
	{
		RestoreRasterizerState();
		RestoreBlendState();
		RestoreDepthStencilState();
	}
}