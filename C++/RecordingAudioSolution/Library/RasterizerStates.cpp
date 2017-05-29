#include "RasterizerStates.h"
#include "GameException.h"

namespace MatMeshModLibrary
{
	ID3D11RasterizerState* RasterizerStates::BackCulling = nullptr;
	ID3D11RasterizerState* RasterizerStates::FrontCulling = nullptr;
	ID3D11RasterizerState* RasterizerStates::DisabledCulling = nullptr;
	ID3D11RasterizerState* RasterizerStates::Wireframe = nullptr;

	void RasterizerStates::Initialize(ID3D11Device* direct3DDevice)
	{
		assert(direct3DDevice != nullptr);

		D3D11_RASTERIZER_DESC rasterizerStateDesc;
		ZeroMemory(&rasterizerStateDesc, sizeof(rasterizerStateDesc));
		rasterizerStateDesc.FillMode = D3D11_FILL_SOLID;
		rasterizerStateDesc.CullMode = D3D11_CULL_BACK;
		rasterizerStateDesc.DepthClipEnable = true;
		
		ThrowIfFailed(direct3DDevice->CreateRasterizerState(&rasterizerStateDesc, &BackCulling), "ID3D11Device::CreateRasterizerState() failed.");
		
		ZeroMemory(&rasterizerStateDesc, sizeof(rasterizerStateDesc));
		rasterizerStateDesc.FillMode = D3D11_FILL_SOLID;
		rasterizerStateDesc.CullMode = D3D11_CULL_BACK;
		rasterizerStateDesc.FrontCounterClockwise = true;
		rasterizerStateDesc.DepthClipEnable = true;

		ThrowIfFailed(direct3DDevice->CreateRasterizerState(&rasterizerStateDesc, &FrontCulling), "ID3D11Device::CreateRasterizerState() failed.");

		ZeroMemory(&rasterizerStateDesc, sizeof(rasterizerStateDesc));
		rasterizerStateDesc.FillMode = D3D11_FILL_SOLID;
		rasterizerStateDesc.CullMode = D3D11_CULL_NONE;
		rasterizerStateDesc.DepthClipEnable = true;

		ThrowIfFailed(direct3DDevice->CreateRasterizerState(&rasterizerStateDesc, &DisabledCulling), "ID3D11Device::CreateRasterizerState() failed.");

		ZeroMemory(&rasterizerStateDesc, sizeof(rasterizerStateDesc));
		rasterizerStateDesc.FillMode = D3D11_FILL_WIREFRAME;
		rasterizerStateDesc.CullMode = D3D11_CULL_NONE;
		rasterizerStateDesc.DepthClipEnable = true;

		ThrowIfFailed(direct3DDevice->CreateRasterizerState(&rasterizerStateDesc, &Wireframe), "ID3D11Device::CreateRasterizerState() failed.");
	}

	void RasterizerStates::Release()
	{
		ReleaseObject(BackCulling)
		ReleaseObject(FrontCulling)
		ReleaseObject(DisabledCulling)
		ReleaseObject(Wireframe)
	}
}