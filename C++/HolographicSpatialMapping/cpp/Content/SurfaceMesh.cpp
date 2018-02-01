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

#include "pch.h"

#include <ppltasks.h>

#include "Common\DirectXHelper.h"
#include "Common\StepTimer.h"
#include "GetDataFromIBuffer.h"
#include "SurfaceMesh.h"
#include "BasicLoader.h"

using namespace WindowsHolographicCodeSamples;
using namespace DirectX;
using namespace Windows::Perception::Spatial;
using namespace Windows::Perception::Spatial::Surfaces;
using namespace Windows::Foundation::Numerics;
using namespace WindowsHolographicCodeSamples;

using namespace Concurrency;
using namespace DX;
using namespace Windows::Foundation::Collections;
using namespace Windows::ApplicationModel::Resources::Core;
using namespace Platform;


SurfaceMesh::SurfaceMesh() 
{
	ReleaseDeviceDependentResources();
	//XMStoreFloat4x4(&mScaleMatrix, XMMatrixScaling(scale, scale, scale));

	//CreateDeviceDependentResources(m_deviceResources->GetD3DDevice());

	for (UINT i = 0; i < NUMBER_OF_TEXTURES_CUBES; i++)
		m_textureReady[i] = false;
};

SurfaceMesh::~SurfaceMesh()
{
    ReleaseDeviceDependentResources();
}

void SurfaceMesh::UpdateSurface(SpatialSurfaceMesh^ surfaceMesh)
{
    m_surfaceMesh   = surfaceMesh;
    m_updateNeeded  = true;
}

void SurfaceMesh::UpdateDeviceBasedResources(ID3D11Device* device)
{
    ReleaseDeviceDependentResources();
    CreateDeviceDependentResources(device);
		
}

// Spatial Mapping surface meshes each have a transform. This transform is updated every frame.
void SurfaceMesh::UpdateTransform(
    ID3D11DeviceContext* context,
    DX::StepTimer const& timer,
    SpatialCoordinateSystem^ baseCoordinateSystem
    )
{
    if (m_surfaceMesh == nullptr)
    {
        // Not yet ready.
        m_isActive = false;
    }

    // If the surface is active this frame, we need to update its transform.
    XMMATRIX transform;
    if (m_isActive)
    {
        // In this example, new surfaces are treated differently by highlighting them in a different
        // color. This allows you to observe changes in the spatial map that are due to new meshes,
        // as opposed to mesh updates.
        if (m_colorFadeTimeout > 0.f)
        {
            m_colorFadeTimer += static_cast<float>(timer.GetElapsedSeconds());
            if (m_colorFadeTimer < m_colorFadeTimeout)
            {
                float colorFadeFactor = min(1.f, m_colorFadeTimeout - m_colorFadeTimer);
                m_constantBufferData.colorFadeFactor = XMFLOAT4(colorFadeFactor, colorFadeFactor, colorFadeFactor, 1.f);
            }
            else
            {
                m_constantBufferData.colorFadeFactor = XMFLOAT4(0.f, 0.f, 0.f, 0.f);
                m_colorFadeTimer = m_colorFadeTimeout = -1.f;
            }
        }

		

        // The transform is updated relative to a SpatialCoordinateSystem. In the SurfaceMesh class, we
        // expect to be given the same SpatialCoordinateSystem that will be used to generate view
        // matrices, because this class uses the surface mesh for rendering.
        // Other applications could potentially involve using a SpatialCoordinateSystem from a stationary
        // reference frame that is being used for physics simulation, etc.
        auto tryTransform = m_surfaceMesh->CoordinateSystem->TryGetTransformTo(baseCoordinateSystem);
        if (tryTransform != nullptr)
        {
            // If the transform can be acquired, this spatial mesh is valid right now and
            // we have the information we need to draw it this frame.
            transform = XMLoadFloat4x4(&tryTransform->Value);
            m_lastActiveTime = static_cast<float>(timer.GetTotalSeconds());

        }
        else
        {
            // If the transform is not acquired, the spatial mesh is not valid right now
            // because its location cannot be correlated to the current space.
            m_isActive = false;
        }
    }

    if (!m_isActive)
    {
        // If for any reason the surface mesh is not active this frame - whether because
        // it was not included in the observer's collection, or because its transform was
        // not located - we don't have the information we need to update it.
        return;
    }

    // Set up a transform from surface mesh space, to world space.
    XMMATRIX scaleTransform = XMMatrixScalingFromVector(XMLoadFloat3(&m_surfaceMesh->VertexPositionScale));
    XMStoreFloat4x4(
        &m_constantBufferData.modelToWorld,
        XMMatrixTranspose(scaleTransform * transform)
        );

    // Surface meshes come with normals, which are also transformed from surface mesh space, to world space.
    XMMATRIX normalTransform = transform;
    // Normals are not translated, so we remove the translation component here.
    normalTransform.r[3] = XMVectorSet(0.f, 0.f, 0.f, XMVectorGetW(normalTransform.r[3]));
    XMStoreFloat4x4(
        &m_constantBufferData.normalToWorld,
        XMMatrixTranspose(normalTransform)
        );

    if (!m_loadingComplete)
    {
        // If loading is not yet complete, we cannot actually update the graphics resources.
        // This return is intentionally placed after the surface mesh updates so that this
        // code may be copied and re-used for CPU-based processing of surface data.
        return;
    }

    context->UpdateSubresource(
        m_modelTransformBuffer.Get(),
        0,
        NULL,
        &m_constantBufferData,
        0,
        0
        );
}

// Does an indexed, instanced draw call after setting the IA stage to use the mesh's geometry, and
// after setting up the constant buffer for the surface mesh.
// The caller is responsible for the rest of the shader pipeline.
void SurfaceMesh::Draw(ID3D11Device* device, ID3D11DeviceContext* context, bool usingVprtShaders, bool isStereo, UINT index)
{	
    if (m_updateNeeded)
    {
        ReleaseVertexResources();
        CreateVertexResources(device);
        m_updateNeeded = false;
    }

    if (!m_loadingComplete)
    {
        CreateDeviceDependentResources(device);
    }

    if (!m_isActive)
    {
        // Mesh is not active this frame, and should not be drawn.
        return;
    }

	
    // The vertices are provided in {vertex, normal, coordinate} format	
	UINT strides[] = {  m_vertexStride, m_normalStride  , m_coordinateStride};

	UINT offsets[] = { 0  , 0, 0};

	ID3D11Buffer* buffers[] = { m_vertexPositions.Get(), m_vertexNormals.Get() , m_vertexCoords.Get() };

    context->IASetVertexBuffers(
        0,
        ARRAYSIZE(buffers),
        buffers,
        strides,
        offsets
        );

    context->IASetIndexBuffer(
        m_triangleIndices.Get(),
        m_indexFormat,
        0
        );

    context->VSSetConstantBuffers(
        0,
        1,
        m_modelTransformBuffer.GetAddressOf()
        );

    if (!usingVprtShaders)
    {
        context->GSSetConstantBuffers(
            0,
            1,
            m_modelTransformBuffer.GetAddressOf()
            );
    }

	//if(m_textureSampler != NULL)
	context->PSSetSamplers(0, 1, m_textureSampler.GetAddressOf());

	UINT _index = index;
	if (_index >= NUMBER_OF_TEXTURES_CUBES)
	{
		_index = 0;
	}
	context->PSSetShaderResources(0, 1, m_colorTexture[_index].GetAddressOf());
		
    context->PSSetConstantBuffers(
        0,
        1,
        m_modelTransformBuffer.GetAddressOf()
        );

    context->DrawIndexedInstanced(
        m_indexCount,       // Index count per instance.
        isStereo ? 2 : 1,   // Instance count.
        0,                  // Start index location.
        0,                  // Base vertex location.
        0                   // Start instance location.
        );
}

void SurfaceMesh::CreateDirectXBuffer(
    ID3D11Device* device,
    D3D11_BIND_FLAG binding,
    IBuffer^ buffer,
    ID3D11Buffer** target
    )
{
    auto length = buffer->Length;

    CD3D11_BUFFER_DESC bufferDescription(buffer->Length, binding);
    D3D11_SUBRESOURCE_DATA bufferBytes = { GetDataFromIBuffer(buffer), 0, 0 };
    device->CreateBuffer(&bufferDescription, &bufferBytes, target);
}

byte* SurfaceMesh::GetPointerToPixelData(IBuffer^ buffer)
{
	// Cast to Object^, then to its underlying IInspectable interface.

	Platform::Object^ obj = buffer;
	ComPtr<IInspectable> insp(reinterpret_cast<IInspectable*>(obj));

	// Query the IBufferByteAccess interface.
	ComPtr<IBufferByteAccess> bufferByteAccess;
	DX::ThrowIfFailed(insp.As(&bufferByteAccess));

	// Retrieve the buffer data.
	byte* pixels = nullptr;
	DX::ThrowIfFailed(bufferByteAccess->Buffer(&pixels));

	return pixels;

}

void SurfaceMesh::CreateVertexResources(ID3D11Device* device)
{
	if (m_surfaceMesh == nullptr)
	{
		// Not yet ready.
		m_isActive = false;
		return;
	}

	m_indexCount = m_surfaceMesh->TriangleIndices->ElementCount;

	if (m_indexCount < 3)
	{
		// Not enough indices to draw a triangle.
		m_isActive = false;
		return;
	}

	

	// First, we acquire the raw data buffers.
	Windows::Storage::Streams::IBuffer^ positions = m_surfaceMesh->VertexPositions->Data;
	Windows::Storage::Streams::IBuffer^ normals = m_surfaceMesh->VertexNormals->Data;
	Windows::Storage::Streams::IBuffer^ indices = m_surfaceMesh->TriangleIndices->Data;
		
	// Finally, we cache properties for the buffers we just created.
	m_vertexStride = m_surfaceMesh->VertexPositions->Stride;
	m_normalStride = m_surfaceMesh->VertexNormals->Stride;
	m_indexFormat = static_cast<DXGI_FORMAT>(m_surfaceMesh->TriangleIndices->Format);

	auto textureStride = sizeof(float2);
	m_coordinateStride = textureStride;
	
	//auto pixelFormat = m_surfaceMesh->VertexPositions->Format;
	//auto normalFormat = m_surfaceMesh->VertexNormals->Format;

	//std::vector<VertexPositionNormalTexture> vertices;
	auto verticesCount = m_surfaceMesh->VertexPositions->ElementCount;
	float fwidth = sqrtf((float)verticesCount);
	UINT width =  (UINT)((fwidth - 1.0f) );
	UINT height =  width;
	

	std::vector<float2> textureCoords;

	
	//auto numberOfRows = verticesCount / textureStride;
	for (UINT y = 0; y < height; y++)
	{
		for (UINT x = 0; x < width; x++)
		{
			textureCoords.push_back(float2((x / (fwidth*m_scaleFactor)) , (y / (fwidth * m_scaleFactor) ) ));
		}
	}

	auto numOfVertices = (UINT)(verticesCount / m_normalStride);
	BYTE * ptrNormals = (BYTE *)normals;
	BYTE * ptrPositions = (BYTE *)positions;


//	for (UINT i = 0; i < verticesCount; i++)
//	{
	//	auto fred = (float) *ptrNormals;
	//	ptrNormals++;
	//	auto fgreen = (float)*ptrNormals;
	//	ptrNormals++;
	//	auto fblue = (float)*ptrNormals;
	//	ptrNormals++;
	//	auto fAlpha = (float)*ptrNormals;
	//	ptrNormals++;
	//	
	//	XMFLOAT3 normal = XMFLOAT3(fred, fgreen, fblue);

		//auto fX = (float)*ptrPositions;
		//ptrPositions++;
		//auto fY = (float)*ptrPositions;
		//ptrPositions++;
		//auto fZ = (float)*ptrPositions;
		//ptrPositions++;
		//auto fW = (float)*ptrPositions;
		//ptrPositions++;
	//	
	//	XMFLOAT3 position = XMFLOAT3(fX, fY, fZ);

	//	XMFLOAT2 texture;
	//	texture.x = textureCoords.at(i).x;
	//	texture.y = textureCoords.at(i).y;

	//	vertices.push_back(VertexPositionNormalTexture(XMFLOAT3(position.x, position.y, position.z), XMFLOAT3(normal.x, normal.y, normal.z), XMFLOAT2(texture)));

//	}

	D3D11_BUFFER_DESC vertexBufferDesc;
	ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));
	//vertexBufferDesc.ByteWidth = sizeof(VertexPositionNormalTexture) * vertices.size();
	vertexBufferDesc.ByteWidth = sizeof(float2) * textureCoords.size();
	//	vertexBufferDesc.StructureByteStride = textureStride;
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA vertexSubResourceData;
	ZeroMemory(&vertexSubResourceData, sizeof(vertexSubResourceData));
	vertexSubResourceData.pSysMem = &textureCoords[0];
	DX::ThrowIfFailed(device->CreateBuffer(&vertexBufferDesc, &vertexSubResourceData, m_vertexCoords.GetAddressOf()));

	//vertices.reserve(verticesCount);
	//byte* ptrPositions = GetPointerToPixelData(positions);

	//byte* ptrNormals = GetPointerToPixelData(normals);

	
	//Concurrency::create_task(dw->FlushAsync());
	//dw->FlushAsync();
	

	// Then, we create Direct3D device buffers with the mesh data provided by HoloLens.
	CreateDirectXBuffer(device, D3D11_BIND_VERTEX_BUFFER, positions, m_vertexPositions.GetAddressOf());
	CreateDirectXBuffer(device, D3D11_BIND_VERTEX_BUFFER, normals, m_vertexNormals.GetAddressOf());
	CreateDirectXBuffer(device, D3D11_BIND_INDEX_BUFFER, indices, m_triangleIndices.GetAddressOf());
	
	
}

void SurfaceMesh::CreateDeviceDependentResources(ID3D11Device* device)
{	
    CreateVertexResources(device);
	CreateCubeResources(device);
    // Create a constant buffer to control mesh position.
    CD3D11_BUFFER_DESC constantBufferDesc(sizeof(ModelNormalConstantBuffer), D3D11_BIND_CONSTANT_BUFFER);
    DX::ThrowIfFailed(
        device->CreateBuffer(
            &constantBufferDesc,
            nullptr,
            &m_modelTransformBuffer
            )
        );

    m_loadingComplete = true;
}

void SurfaceMesh::CreateCubeResources(ID3D11Device* device)
{
//	auto m_usingVprtShaders = m_deviceResources->GetDeviceSupportsVprt();

	// Load a texture from resource	
	std::wstring textureName[NUMBER_OF_TEXTURES_CUBES];

	//memory is a concern here 512 works fine 1024 - yields out of memory sometimes depending on apps running
	textureName[0] = L"Content\\Textures\\NuwaupianHoldingFire512.dds";
	Platform::String ^ pfstrTextureName = ref new String(textureName[0].data());
	BasicLoader loader0(device);

	auto loadTextureTask0 = loader0.LoadTextureCubeAsync(pfstrTextureName, m_texture[0].GetAddressOf(), m_colorTexture[0].GetAddressOf());

	loadTextureTask0.then([this]() {
		m_textureReady[0] = true;
	});

	//textureName[1] = L"Content\\Textures\\marble512.dds";
	// pfstrTextureName = ref new String(textureName[1].data());
	//
	//auto loadTextureTask1 = loader0.LoadTextureCubeAsync(pfstrTextureName, m_texture[1].GetAddressOf(), m_colorTexture[1].GetAddressOf());

	//loadTextureTask1.then([this]() {
	//	m_textureReady[1] = true;
	//});

	/*textureName[2] = L"Content\\Textures\\stone512.dds";
	pfstrTextureName = ref new String(textureName[2].data());
	
	auto loadTextureTask2 = loader0.LoadTextureCubeAsync(pfstrTextureName, m_texture[2].GetAddressOf(), m_colorTexture[2].GetAddressOf());

	loadTextureTask2.then([this]() {
		m_textureReady[2] = true;
	});
*/
	/*textureName[3] = L"Content\\Textures\\matrixmapLarge.dds";
	pfstrTextureName = ref new String(textureName[3].data());
	
	auto loadTextureTask3 = loader0.LoadTextureCubeAsync(pfstrTextureName, m_texture[3].GetAddressOf(), m_colorTexture[3].GetAddressOf());

	loadTextureTask3.then([this]() {
		m_textureReady[3] = true;
	});*/


	D3D11_SAMPLER_DESC samplerDesc;
	ZeroMemory(&samplerDesc, sizeof(samplerDesc));
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	
	DX::ThrowIfFailed(device->CreateSamplerState(&samplerDesc, &m_textureSampler));
}

void SurfaceMesh::ReleaseVertexResources()
{
    m_vertexPositions.Reset();
    m_vertexNormals.Reset();
    m_triangleIndices.Reset();
	m_vertexCoords.Reset();
}

void SurfaceMesh::ReleaseDeviceDependentResources()
{
    ReleaseVertexResources();

    m_modelTransformBuffer.Reset();
	m_textureSampler.Reset();
	
	m_vertexPositions.Reset();
	m_vertexNormals.Reset();
	m_vertexCoords.Reset();
	m_triangleIndices.Reset();
	
	for (UINT i = 0; i < NUMBER_OF_TEXTURES_CUBES; i++)
	{
		m_texture[i].Reset();
		m_colorTexture[i].Reset();
	}

    
}
