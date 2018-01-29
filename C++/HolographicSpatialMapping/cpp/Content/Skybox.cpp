//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

//*********************************************************

#include "pch.h"


#include "Common\DirectXHelper.h"
#include "Skybox.h"
#include "WICTextureLoader.h"
#include "BasicLoader.h"

using namespace WindowsHolographicCodeSamples;

using namespace Concurrency;
using namespace DX;
using namespace Windows::Foundation::Collections;
using namespace Windows::Foundation::Numerics;
using namespace Windows::Perception::Spatial;
using namespace Windows::Perception::Spatial::Surfaces;
using namespace Windows::ApplicationModel::Resources::Core;
using namespace DirectX;
using namespace Platform;

Skybox::Skybox(const std::shared_ptr<DX::DeviceResources>& deviceResources, float scale) :
	m_deviceResources(deviceResources), mVertexCBufferPerObjectData(), mVertexCBufferPerObject(nullptr)
{
	XMStoreFloat4x4(&mScaleMatrix, XMMatrixScaling(scale, scale, scale));

   CreateDeviceDependentResources();

	for (UINT i = 0; i < NUMBER_OF_TEXTURES; i++)
		m_textureReady[i] = false;
};

// Called once per frame, rotates the cube and calculates the model and view matrices.
void Skybox::Update(
    DX::StepTimer const& timer,
    SpatialCoordinateSystem^ coordinateSystem
    )
{
	
   
    const float timeElapsed = static_cast<float>(timer.GetTotalSeconds());

    // Update meshes as needed, based on the current coordinate system.
    // Also remove meshes that are inactive for too long.
	float4x4 translation = coordinateSystem->TryGetTransformTo(coordinateSystem)->Value;
	XMFLOAT4X4 xmTranslation = XMFLOAT4X4(translation.m11, translation.m12, translation.m13, translation.m14, translation.m21, translation.m22, translation.m23, translation.m24, translation.m31, translation.m32, translation.m33, translation.m34, translation.m41, translation.m42, translation.m43, translation.m44);
	XMMATRIX xmTransMat = XMMatrixMultiply( XMLoadFloat4x4(&mScaleMatrix) , XMLoadFloat4x4(&xmTranslation));
	
	XMStoreFloat4x4(&mWorldMatrix, xmTransMat );

	

}

// Renders one frame using the vertex, geometry, and pixel shaders.
void Skybox::Render(bool isStereo, bool useWireframe, UINT index)
{
    // Loading is asynchronous. Only draw geometry after it's loaded.
    if (!m_loadingComplete && !m_textureReady[index])
    {
        return;
    }

    auto context = m_deviceResources->GetD3DDeviceContext();

    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    context->IASetInputLayout(m_inputLayout.Get());

    // Attach our vertex shader.
    context->VSSetShader(
        m_vertexShader.Get(),
        nullptr,
        0
        );

    // The constant buffer is per-mesh, and will be set for each one individually.

    //if (!m_usingVprtShaders)
    //{
    //    // Attach the passthrough geometry shader.
    //    context->GSSetShader(
    //        m_geometryShader.Get(),
    //        nullptr,
    //        0
    //        );
    //}


    if (useWireframe)
    {
        // Use a wireframe rasterizer state.
        m_deviceResources->GetD3DDeviceContext()->RSSetState(m_wireframeRasterizerState.Get());

        // Attach a pixel shader to render a solid color wireframe.
        context->PSSetShader(
            m_colorPixelShader.Get(),
            nullptr,
            0
        );
    }
    else
    {
        // Use the default rasterizer state.
        m_deviceResources->GetD3DDeviceContext()->RSSetState(m_defaultRasterizerState.Get());


        // Attach a pixel shader that can do lighting.
        context->PSSetShader(
            m_lightingPixelShader.Get(),
            nullptr,
            0
        );
		

	}

	XMMATRIX worldMatrix = XMLoadFloat4x4(&mWorldMatrix);
	XMStoreFloat4x4(&mVertexCBufferPerObjectData.WorldViewProjection, XMMatrixTranspose(worldMatrix));
	context->UpdateSubresource(mVertexCBufferPerObject.Get(), 0, nullptr, &mVertexCBufferPerObjectData, 0, 0);
	context->VSSetConstantBuffers(0, 1, mVertexCBufferPerObject.GetAddressOf());

	//if(m_colorTexture != NULL)
	context->PSSetShaderResources(0, 1, m_colorTexture[0].GetAddressOf());

	//if(m_textureSampler != NULL)
	context->PSSetSamplers(0, 1, m_textureSampler.GetAddressOf());

	context->RSSetState(m_defaultRasterizerState.Get());
	   
	context->DrawIndexed(1, 0, 0);

	context->RSSetState(nullptr);
}

void Skybox::CreateDeviceDependentResources()
{
    m_usingVprtShaders = m_deviceResources->GetDeviceSupportsVprt();

    // On devices that do support the D3D11_FEATURE_D3D11_OPTIONS3::
    // VPAndRTArrayIndexFromAnyShaderFeedingRasterizer optional feature
    // we can avoid using a pass-through geometry shader to set the render
    // target array index, thus avoiding any overhead that would be
    // incurred by setting the geometry shader stage.
    std::wstring vertexShaderFileName = m_usingVprtShaders ? L"ms-appx:///SkyboxVS.cso" : L"ms-appx:///SkyboxVS.cso";

	
    // Load shaders asynchronously.
    task<std::vector<byte>> loadVSTask = DX::ReadDataAsync(vertexShaderFileName);
    task<std::vector<byte>> loadLightingPSTask = DX::ReadDataAsync(L"ms-appx:///SkyboxPS.cso");
    task<std::vector<byte>> loadWireframePSTask = DX::ReadDataAsync(L"ms-appx:///SkyboxPS.cso");
	
    //task<std::vector<byte>> loadGSTask;
    //if (!m_usingVprtShaders)
    //{
    //    // Load the pass-through geometry shader.
    //    loadGSTask = DX::ReadDataAsync(L"ms-appx:///SurfaceGeometryShader.cso");
    //}

	// Load a texture from resource	
	std::wstring textureName[NUMBER_OF_TEXTURES];
	
	textureName[0] = L"Content\\Textures\\nuwaupian_holding_fire3.dds";
	Platform::String ^ pfstrTextureName = ref new String(textureName[0].data());
	BasicLoader loader0(m_deviceResources->GetD3DDevice());

	auto loadTextureTask0 = loader0.LoadTextureCubeAsync(pfstrTextureName, m_texture[0].GetAddressOf(), m_colorTexture[0].GetAddressOf());

	loadTextureTask0.then([this]() {
		m_textureReady[0] = true;
	});

	D3D11_BUFFER_DESC constantBufferDesc;
	ZeroMemory(&constantBufferDesc, sizeof(constantBufferDesc));
	constantBufferDesc.ByteWidth = sizeof(mVertexCBufferPerObjectData);
	constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	
	ThrowIfFailed(m_deviceResources->GetD3DDevice()->CreateBuffer(&constantBufferDesc, nullptr, mVertexCBufferPerObject.GetAddressOf()));


	D3D11_SAMPLER_DESC samplerDesc;
	ZeroMemory(&samplerDesc, sizeof(samplerDesc));
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW =  D3D11_TEXTURE_ADDRESS_WRAP;
	

	DX::ThrowIfFailed(m_deviceResources->GetD3DDevice()->CreateSamplerState(&samplerDesc, &m_textureSampler));

    // After the vertex shader file is loaded, create the shader and input layout.
    auto createVSTask = loadVSTask.then([this](const std::vector<byte>& fileData) {
        DX::ThrowIfFailed(
            m_deviceResources->GetD3DDevice()->CreateVertexShader(
                &fileData[0],
                fileData.size(),
                nullptr,
                &m_vertexShader
                )
            );

        static const D3D11_INPUT_ELEMENT_DESC vertexDesc [] =
        {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
        };

        DX::ThrowIfFailed(
            m_deviceResources->GetD3DDevice()->CreateInputLayout(
                vertexDesc,
                ARRAYSIZE(vertexDesc),
                &fileData[0],
                fileData.size(),
                &m_inputLayout
                )
            );
    });

    // After the pixel shader file is loaded, create the shader and constant buffer.
    auto createLightingPSTask = loadLightingPSTask.then([this](const std::vector<byte>& fileData) {
        DX::ThrowIfFailed(
            m_deviceResources->GetD3DDevice()->CreatePixelShader(
                &fileData[0],
                fileData.size(),
                nullptr,
                &m_lightingPixelShader
                )
            );
    });

    // After the pixel shader file is loaded, create the shader and constant buffer.
    auto createWireframePSTask = loadWireframePSTask.then([this](const std::vector<byte>& fileData) {
        DX::ThrowIfFailed(
            m_deviceResources->GetD3DDevice()->CreatePixelShader(
                &fileData[0],
                fileData.size(),
                nullptr,
                &m_colorPixelShader
            )
        );
    });

    //task<void> createGSTask;
    //if (!m_usingVprtShaders)
    //{
    //    // After the pass-through geometry shader file is loaded, create the shader.
    //    createGSTask = loadGSTask.then([this](const std::vector<byte>& fileData)
    //    {
    //        DX::ThrowIfFailed(
    //            m_deviceResources->GetD3DDevice()->CreateGeometryShader(
    //                &fileData[0],
    //                fileData.size(),
    //                nullptr,
    //                &m_geometryShader
    //                )
    //            );
    //    });
    //}

    // Once all shaders are loaded, create the mesh.
    task<void> shaderTaskGroup = m_usingVprtShaders ?
        (createLightingPSTask && createWireframePSTask && createVSTask) :
		(createLightingPSTask && createWireframePSTask && createVSTask); // && createGSTask);

   
    auto createRasterizerStates = shaderTaskGroup.then([this] {

        // Create a default rasterizer state descriptor.
        D3D11_RASTERIZER_DESC rasterizerDesc = CD3D11_RASTERIZER_DESC(D3D11_DEFAULT);
		rasterizerDesc.AntialiasedLineEnable = true;
		rasterizerDesc.CullMode = D3D11_CULL_NONE;
		rasterizerDesc.FillMode = D3D11_FILL_SOLID;
		rasterizerDesc.DepthClipEnable = true;

        // Create the default rasterizer state.
        m_deviceResources->GetD3DDevice()->CreateRasterizerState(&rasterizerDesc, m_defaultRasterizerState.GetAddressOf());

        // Change settings for wireframe rasterization.
        rasterizerDesc.AntialiasedLineEnable = true;
        rasterizerDesc.CullMode = D3D11_CULL_NONE;
        rasterizerDesc.FillMode = D3D11_FILL_WIREFRAME;

        // Create a wireframe rasterizer state.
        m_deviceResources->GetD3DDevice()->CreateRasterizerState(&rasterizerDesc, m_wireframeRasterizerState.GetAddressOf());
    });

    // Once the cube is loaded, the object is ready to be rendered.
    createRasterizerStates.then([this]() {
        m_loadingComplete = true;
    });
}

void Skybox::ReleaseDeviceDependentResources()
{
    m_loadingComplete = false;

    m_vertexShader.Reset();
    m_inputLayout.Reset();
    m_geometryShader.Reset();
    m_lightingPixelShader.Reset();
    m_colorPixelShader.Reset();

    m_defaultRasterizerState.Reset();
    m_wireframeRasterizerState.Reset();
	mVertexCBufferPerObject.Reset();

  
}
