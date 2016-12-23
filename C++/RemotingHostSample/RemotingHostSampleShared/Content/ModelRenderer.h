//********************************************************* 
// 
// Copyright (c) Microsoft. All rights reserved. 
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF 
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY 
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR 
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT. 
// 
//********************************************************* 

#pragma once

#include "..\Common\DeviceResources.h"
#include "..\Common\DeviceResourcesWindowed.h"
#include "..\Common\StepTimer.h"
#include "ShaderStructures.h"


namespace Library
{
	class Mesh;
}


namespace RemotingHostSample
{
	// This sample renderer instantiates a basic rendering pipeline.
	class ModelRenderer
	{
	public:
		ModelRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources, const std::wstring& filename, bool useRelativePath);
		void CreateWindowSizeDependentResources();
		void CreateDeviceDependentResources();
		void ReleaseDeviceDependentResources();
		void Update(const DX::StepTimer& timer);
		void SetColorFilter(DirectX::XMFLOAT4 color);
		void Render(bool isStereo);

		// Repositions the sample hologram.
		void PositionHologram(Windows::UI::Input::Spatial::SpatialPointerPose^ pointerPose);

		// Repositions the sample hologram, using direct measures.
		void PositionHologram(Windows::Foundation::Numerics::float3 pos, Windows::Foundation::Numerics::float3 dir);

		// Property accessors.
		void SetPosition(Windows::Foundation::Numerics::float3 pos) { m_position = pos; }
		Windows::Foundation::Numerics::float3 GetPosition() { return m_position; }

		void Pause() { m_pauseState = PauseState::Pausing; }
		void Unpause() { m_pauseState = PauseState::Unpausing; }
		bool IsLoaded() { return m_modelLoaded; }
	

	private:

		void CreateVertexBuffer(ID3D11Device* device, const Library::Mesh& mesh, ID3D11Buffer** vertexBuffer) const;

		
	private:
		enum class PauseState
		{
			Unpaused = 0,
			Pausing,
			Paused,
			Unpausing,
		};

		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources>            m_deviceResources;

		// Direct3D resources for cube geometry.
		Microsoft::WRL::ComPtr<ID3D11InputLayout>       m_inputLayout;
		Microsoft::WRL::ComPtr<ID3D11Buffer>            m_vertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>            m_indexBuffer;
		Microsoft::WRL::ComPtr<ID3D11VertexShader>      m_vertexShader;
		Microsoft::WRL::ComPtr<ID3D11GeometryShader>    m_geometryShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader>       m_pixelShader;
		Microsoft::WRL::ComPtr<ID3D11Buffer>            m_modelConstantBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>            m_filterColorBuffer;

		// System resources for cube geometry.
		ModelConstantBuffer                             m_modelConstantBufferData;
		uint32                                          m_indexCount = 0;
		DirectX::XMFLOAT4                               m_filterColorData = { 1, 1, 1, 1 };

		// Variables used with the rendering loop.
		bool                                            m_loadingComplete = false;
		float                                           m_degreesPerSecond = 45.f;
		Windows::Foundation::Numerics::float3           m_position = { 0.f, 0.f, -2.f };
		PauseState                                      m_pauseState = PauseState::Unpaused;
		double                                          m_rotationOffset = 0;

		// If the current D3D Device supports VPRT, we can avoid using a geometry
		// shader just to set the render target array index.
		bool                                            m_usingVprtShaders = false;

		std::wstring m_filename;
		bool m_modelLoaded = false;
		bool m_useRelativePath = true;

		Platform::String ^ m_modelFileName;

		// Get the gaze direction relative to the given coordinate system.
		Windows::Foundation::Numerics::float3 m_headPosition = { 1.f, 1.f, 1.f };
		Windows::Foundation::Numerics::float3 m_headDirection = { 1.f, 1.f, 1.f };
		Windows::Foundation::Numerics::float3 m_up = { 0.f, 1.f, 0.f };

	};
}
