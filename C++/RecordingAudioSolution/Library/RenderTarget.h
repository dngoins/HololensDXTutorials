#pragma once

#include "Common.h"

namespace MatMeshModLibrary
{
	class RenderTarget : public RTTI
	{
		RTTI_DECLARATIONS(RenderTarget, RTTI)

	public:
		RenderTarget();
		virtual ~RenderTarget();

		RenderTarget(const RenderTarget& rhs) = delete;
		RenderTarget& operator=(const RenderTarget& rhs) = delete;

		virtual void Begin() = 0;
		virtual void End() = 0;

	protected:
		struct RenderTargetData
		{
			UINT ViewCount;
			ID3D11RenderTargetView** RenderTargetViews;
			ID3D11DepthStencilView* DepthStencilView;
			D3D11_VIEWPORT Viewport;

			RenderTargetData(UINT viewCount, ID3D11RenderTargetView** renderTargetViews, ID3D11DepthStencilView* depthStencilView, const D3D11_VIEWPORT& viewport)
				: ViewCount(viewCount), RenderTargetViews(renderTargetViews), DepthStencilView(depthStencilView), Viewport(viewport) { }
		};

		void Begin(ID3D11DeviceContext* deviceContext, UINT viewCount, ID3D11RenderTargetView** renderTargetViews, ID3D11DepthStencilView* depthStencilView, const D3D11_VIEWPORT& viewport);
		void End(ID3D11DeviceContext* deviceContext);

	private:
		static std::stack<RenderTargetData> sRenderTargetStack;
	};
}