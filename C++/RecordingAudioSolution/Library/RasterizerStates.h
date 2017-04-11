#pragma once

#include "Common.h"

namespace Library
{
	class RasterizerStates
	{
	public:
		static ID3D11RasterizerState* BackCulling;
		static ID3D11RasterizerState* FrontCulling;
		static ID3D11RasterizerState* DisabledCulling;
		static ID3D11RasterizerState* Wireframe;

		static void Initialize(ID3D11Device* direct3DDevice);
		static void Release();

		RasterizerStates() = delete;
		RasterizerStates(const RasterizerStates& rhs) = delete;
		RasterizerStates& operator=(const RasterizerStates& rhs) = delete;
	};
}
