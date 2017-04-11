#pragma once

#include "Common.h"

namespace Library
{
	class SamplerStates
	{
	public:
		static ID3D11SamplerState* TrilinearWrap;
		static ID3D11SamplerState* TrilinearMirror;
		static ID3D11SamplerState* TrilinearClamp;
		static ID3D11SamplerState* TrilinerBorder;
		static ID3D11SamplerState* DepthMap;

		static XMVECTORF32 BorderColor;

		static void Initialize(ID3D11Device* direct3DDevice);
		static void Release();

		SamplerStates() = delete;
		SamplerStates(const SamplerStates& rhs) = delete;
		SamplerStates& operator=(const SamplerStates& rhs) = delete;
	};
}
