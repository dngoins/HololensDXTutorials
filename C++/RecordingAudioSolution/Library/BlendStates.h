#pragma once

#include "Common.h"

namespace MatMeshModLibrary
{
	class BlendStates
	{
	public:
		static ID3D11BlendState* AlphaBlending;
		static ID3D11BlendState* MultiplicativeBlending;		

		static void Initialize(ID3D11Device* direct3DDevice);
		static void Release();

		BlendStates() = delete;
		BlendStates(const BlendStates& rhs) = delete;
		BlendStates& operator=(const BlendStates& rhs) = delete;
	};
}
