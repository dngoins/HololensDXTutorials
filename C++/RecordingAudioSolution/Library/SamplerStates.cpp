#include "SamplerStates.h"
#include "GameException.h"

namespace Library
{
	ID3D11SamplerState* SamplerStates::TrilinearWrap = nullptr;
	ID3D11SamplerState* SamplerStates::TrilinearMirror = nullptr;
	ID3D11SamplerState* SamplerStates::TrilinearClamp = nullptr;
	ID3D11SamplerState* SamplerStates::TrilinerBorder = nullptr;
	ID3D11SamplerState* SamplerStates::DepthMap = nullptr;

	XMVECTORF32 SamplerStates::BorderColor = { 0.0f, 0.0f, 0.0f, 1.0f };

	void SamplerStates::Initialize(ID3D11Device* direct3DDevice)
	{
		assert(direct3DDevice != nullptr);

		D3D11_SAMPLER_DESC samplerStateDesc;
		ZeroMemory(&samplerStateDesc, sizeof(samplerStateDesc));
		samplerStateDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		samplerStateDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		samplerStateDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		samplerStateDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		
		ThrowIfFailed(direct3DDevice->CreateSamplerState(&samplerStateDesc, &TrilinearWrap), "ID3D11Device::CreateSamplerState() failed.");
		
		ZeroMemory(&samplerStateDesc, sizeof(samplerStateDesc));
		samplerStateDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		samplerStateDesc.AddressU = D3D11_TEXTURE_ADDRESS_MIRROR;
		samplerStateDesc.AddressV = D3D11_TEXTURE_ADDRESS_MIRROR;
		samplerStateDesc.AddressW = D3D11_TEXTURE_ADDRESS_MIRROR;

		ThrowIfFailed(direct3DDevice->CreateSamplerState(&samplerStateDesc, &TrilinearMirror), "ID3D11Device::CreateSamplerState() failed.");

		ZeroMemory(&samplerStateDesc, sizeof(samplerStateDesc));
		samplerStateDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		samplerStateDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
		samplerStateDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
		samplerStateDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

		ThrowIfFailed(direct3DDevice->CreateSamplerState(&samplerStateDesc, &TrilinearClamp), "ID3D11Device::CreateSamplerState() failed.");

		ZeroMemory(&samplerStateDesc, sizeof(samplerStateDesc));
		samplerStateDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		samplerStateDesc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
		samplerStateDesc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
		samplerStateDesc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
		memcpy(samplerStateDesc.BorderColor, reinterpret_cast<FLOAT*>(&BorderColor), sizeof(FLOAT) * 4);

		ThrowIfFailed(direct3DDevice->CreateSamplerState(&samplerStateDesc, &TrilinerBorder), "ID3D11Device::CreateSamplerState() failed.");

		ZeroMemory(&samplerStateDesc, sizeof(samplerStateDesc));
		samplerStateDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		samplerStateDesc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
		samplerStateDesc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
		samplerStateDesc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
		memcpy(samplerStateDesc.BorderColor, reinterpret_cast<FLOAT*>(&BorderColor), sizeof(FLOAT) * 4);

		ThrowIfFailed(direct3DDevice->CreateSamplerState(&samplerStateDesc, &DepthMap), "ID3D11Device::CreateSamplerState() failed.");
	}

	void SamplerStates::Release()
	{
		ReleaseObject(TrilinearWrap)
		ReleaseObject(TrilinearMirror)
		ReleaseObject(TrilinearClamp)
		ReleaseObject(TrilinerBorder)
		ReleaseObject(DepthMap)
	}
}