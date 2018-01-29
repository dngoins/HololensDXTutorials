//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#pragma once

#include "Common\DeviceResources.h"
#include "ShaderStructures.h"

#define NUMBER_OF_TEXTURES_CUBES 1

using namespace Windows::Storage::Streams;

namespace WindowsHolographicCodeSamples
{
    class SurfaceMesh final
    {
    public:
		SurfaceMesh();
        ~SurfaceMesh();

        void UpdateSurface(Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh^ surface);
        void UpdateDeviceBasedResources(ID3D11Device* device);
        void UpdateTransform(
            ID3D11DeviceContext* context,
            DX::StepTimer const& timer,
            Windows::Perception::Spatial::SpatialCoordinateSystem^ baseCoordinateSystem
            );

        void Draw(ID3D11Device* device, ID3D11DeviceContext* context, bool usingVprtShaders, bool isStereo, UINT index=0);

        void CreateVertexResources(ID3D11Device* device);
        void CreateDeviceDependentResources(ID3D11Device* device);
        void ReleaseVertexResources();
        void ReleaseDeviceDependentResources();

        const bool&  GetIsActive()       const          { return m_isActive;            }
        const float& GetLastActiveTime() const          { return m_lastActiveTime;      }

        void SetIsActive(const bool& isActive)          { m_isActive = isActive;        }
        void SetColorFadeTimer(const float& duration)   { m_colorFadeTimeout = duration; m_colorFadeTimer = 0.f; }

		
    private:
		byte* GetPointerToPixelData(IBuffer^ buffer);
		void CreateCubeResources(ID3D11Device* device);

        void CreateDirectXBuffer(
            ID3D11Device* device,
            D3D11_BIND_FLAG binding,
            Windows::Storage::Streams::IBuffer^ buffer,
            ID3D11Buffer** target
            );

        Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh^ m_surfaceMesh = nullptr;



		bool m_textureReady[NUMBER_OF_TEXTURES_CUBES];
						
        Microsoft::WRL::ComPtr<ID3D11Buffer>				m_vertexPositions;
        Microsoft::WRL::ComPtr<ID3D11Buffer>				m_vertexNormals;
		Microsoft::WRL::ComPtr<ID3D11Buffer>				m_vertexCoords;
        Microsoft::WRL::ComPtr<ID3D11Buffer>				m_triangleIndices;
        Microsoft::WRL::ComPtr<ID3D11Buffer>				m_modelTransformBuffer;
		Microsoft::WRL::ComPtr<ID3D11SamplerState>			m_textureSampler;
		Microsoft::WRL::ComPtr<ID3D11Texture2D>				m_texture[NUMBER_OF_TEXTURES_CUBES];
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	m_colorTexture[NUMBER_OF_TEXTURES_CUBES];
		
        ModelNormalConstantBuffer							m_constantBufferData;

        unsigned int										m_vertexStride = 0;
        unsigned int										m_normalStride = 0;
		unsigned int										m_coordinateStride = 0;

        DXGI_FORMAT  m_indexFormat  = DXGI_FORMAT_UNKNOWN;

        bool   m_loadingComplete    = false;
        bool   m_updateNeeded       = false;
        bool   m_isActive           = false;
        float  m_lastActiveTime     = -1.f;
        float  m_colorFadeTimer     = -1.f;
        float  m_colorFadeTimeout   = -1.f;
        uint32 m_indexCount         = 0;
		float	m_scaleFactor		= 1.f;
				
    };
}
