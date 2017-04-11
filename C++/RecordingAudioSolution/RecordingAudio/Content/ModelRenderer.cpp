//********************************************************* 
// 
// Copyright (c) Microsoft. All rights reserved. 
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF 
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY 
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR 
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT. 
// 
//********************************************************* 

#include "pch.h"
#include "ModelRenderer.h"
#include "..\Common\DirectXHelper.h"

#include "../../Library/Utility.h"
#include "../../Library/VertexDeclarations.h"
#include "../../Library/ColorHelper.h"
#include "../../Library/MatrixHelper.h"
//#include "Model.h"
#include "../../Library/Mesh.h"
#include "../../Library/Model.h"

using namespace RecordingAudio;
using namespace Library;
using namespace Concurrency;
using namespace DirectX;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Numerics;
using namespace Windows::UI::Input::Spatial;


// Loads vertex and pixel shaders from files and instantiates the cube geometry.
ModelRenderer::ModelRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources, const std::wstring& filename, bool useRelativePath) :
	m_deviceResources(deviceResources), m_filename(filename), m_useRelativePath(useRelativePath)
{
	CreateDeviceDependentResources();

}

// This function uses a SpatialPointerPose to position the world-locked hologram
// two meters in front of the user's heading.
void ModelRenderer::PositionHologram(SpatialPointerPose^ pointerPose)
{
	if (pointerPose != nullptr)
	{
		// Get the gaze direction relative to the given coordinate system.
		m_headPosition = pointerPose->Head->Position;
		m_headDirection = pointerPose->Head->ForwardDirection;
		m_up = pointerPose->Head->UpDirection;
		
		PositionHologram(m_headPosition, m_headDirection);
	}
}

void ModelRenderer::SetColorFilter(DirectX::XMFLOAT4 color)
{
	m_filterColorData = color;
}

// This function uses a point and a vector to position the world-locked hologram
// two meters in front of the user's heading.
void ModelRenderer::PositionHologram(float3 headPosition, float3 headDirection)
{
	// The hologram is positioned two meters along the user's gaze direction.
	static const float distanceFromUser = 2.0f; // meters
	const float3 gazeAtTwoMeters = headPosition + (distanceFromUser * headDirection);

	// This will be used as the translation component of the hologram's
	// model transform.
	SetPosition(gazeAtTwoMeters);
}

// Called once per frame. Rotates the cube, and calculates and sets the model matrix
// relative to the position transform indicated by hologramPositionTransform.
void ModelRenderer::Update(const DX::StepTimer& timer)
{
	
	
	// Rotate the cube.
	// Convert degrees to radians, then convert seconds to rotation angle.
	const float    radiansPerSecond = XMConvertToRadians(m_degreesPerSecond);
	const double   relativeRotation = timer.GetTotalSeconds() * radiansPerSecond;
	double totalRotation = m_rotationOffset;
	switch (m_pauseState)
	{
	case PauseState::Unpaused:
		//totalRotation += relativeRotation;
		break;

	case PauseState::Pausing:
		//m_rotationOffset += relativeRotation;
		m_pauseState = PauseState::Paused;
	case PauseState::Paused:
		//totalRotation = m_rotationOffset;
		break;

	case PauseState::Unpausing:
		//m_rotationOffset -= relativeRotation;
		m_pauseState = PauseState::Unpaused;
		break;
	}
	const float    radians = static_cast<float>(fmod(totalRotation, XM_2PI));
	const XMMATRIX modelRotation = XMMatrixRotationY(-radians);

	// Position the cube.
	const XMMATRIX modelTranslation = XMMatrixTranslationFromVector(XMLoadFloat3(&m_position));


	// Multiply to get the transform matrix.
	// Note that this transform does not enforce a particular coordinate system. The calling
	// class is responsible for rendering this content in a consistent manner.
	const XMMATRIX modelTransform = XMMatrixMultiply(modelRotation, modelTranslation);

	
	// Store the normal transform.
	XMStoreFloat4x4(&m_modelConstantBufferData.normal,  XMMatrixTranspose(modelRotation));

	// The view and projection matrices are provided by the system; they are associated
	// with holographic cameras, and updated on a per-camera basis.
	// Here, we provide the model transform for the sample hologram. The model transform
	// matrix is transposed to prepare it for the shader.
	XMStoreFloat4x4(&m_modelConstantBufferData.model,  XMMatrixTranspose(modelTransform));

	// Loading is asynchronous. Resources must be created before they can be updated.
	if (!m_loadingComplete)
	{
		return;
	}

	if (!m_modelLoaded)
	{
		return;
	}

	// Use the D3D device context to update Direct3D device-based resources.
	const auto context = m_deviceResources->GetD3DDeviceContext();

	// Update the model transform buffer for the hologram.
	context->UpdateSubresource(
		m_modelConstantBuffer.Get(),
		0,
		nullptr,
		&m_modelConstantBufferData,
		0,
		0
	);
}

// Renders one frame using the vertex and pixel shaders.
// On devices that do not support the D3D11_FEATURE_D3D11_OPTIONS3::
// VPAndRTArrayIndexFromAnyShaderFeedingRasterizer optional feature,
// a pass-through geometry shader is also used to set the render 
// target array index.
void ModelRenderer::Render(bool isStereo)
{
	// Loading is asynchronous. Resources must be created before drawing can occur.
	if (!m_loadingComplete)
	{
		return;
	}

	if (!m_modelLoaded)
	{
		return;
	}
	const auto context = m_deviceResources->GetD3DDeviceContext();

	// Each vertex is one instance of the VertexPositionColor struct.
	const UINT stride = sizeof(Library::VertexPositionColor);
	const UINT offset = 0;
	context->IASetVertexBuffers(
		0,
		1,
		m_vertexBuffer.GetAddressOf(),
		&stride,
		&offset
	);
	context->IASetIndexBuffer(
		m_indexBuffer.Get(),
		DXGI_FORMAT_R32_UINT, // Each index is one 16-bit unsigned integer (short).
		0
	);

	D3D11_RASTERIZER_DESC rasterizerStateDesc;
	ZeroMemory(&rasterizerStateDesc, sizeof(rasterizerStateDesc));
	rasterizerStateDesc.FillMode = D3D11_FILL_SOLID;
	rasterizerStateDesc.CullMode = D3D11_CULL_NONE;
	rasterizerStateDesc.DepthClipEnable = true;
	ID3D11RasterizerState* DisabledCulling = nullptr;
	m_deviceResources->GetD3DDevice()->CreateRasterizerState(&rasterizerStateDesc, &DisabledCulling);
	context->RSSetState(DisabledCulling);

	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	context->IASetInputLayout(m_inputLayout.Get());

	// Attach the vertex shader.
	context->VSSetShader(
		m_vertexShader.Get(),
		nullptr,
		0
	);
	// Apply the model constant buffer to the vertex shader.
	context->VSSetConstantBuffers(
		0,
		1,
		m_modelConstantBuffer.GetAddressOf()
	);

	if (!m_usingVprtShaders)
	{
		// On devices that do not support the D3D11_FEATURE_D3D11_OPTIONS3::
		// VPAndRTArrayIndexFromAnyShaderFeedingRasterizer optional feature,
		// a pass-through geometry shader is used to set the render target 
		// array index.
		context->GSSetShader(
			m_geometryShader.Get(),
			nullptr,
			0
		);
	}

	/*context->UpdateSubresource(
		m_filterColorBuffer.Get(),
		0,
		nullptr,
		&m_filterColorData,
		0,
		0
	);*/
	/*context->PSSetConstantBuffers(2, 1, m_filterColorBuffer.GetAddressOf());*/

	// Attach the pixel shader.
	context->PSSetShader(
		m_pixelShader.Get(),
		nullptr,
		0
	);

	// Draw the objects.
	context->DrawIndexedInstanced(
		m_indexCount,       // Index count per instance.
		isStereo ? 2 : 1,   // Instance count.
		0,                  // Start index location.
		0,                  // Base vertex location.
		0                   // Start instance location.
	);
}

void ModelRenderer::CreateDeviceDependentResources()
{
	m_usingVprtShaders = m_deviceResources->GetDeviceSupportsVprt();

	// On devices that do support the D3D11_FEATURE_D3D11_OPTIONS3::
	// VPAndRTArrayIndexFromAnyShaderFeedingRasterizer optional feature
	// we can avoid using a pass-through geometry shader to set the render
	// target array index, thus avoiding any overhead that would be 
	// incurred by setting the geometry shader stage.
	std::wstring vertexShaderFileName = m_usingVprtShaders ? L"VprtModelVertexShader.cso" : L"ModelVertexShader.cso";

	// Load shaders asynchronously.
	task<std::vector<byte>> loadVSTask = DX::ReadDataAsync(vertexShaderFileName);
	task<std::vector<byte>> loadPSTask = DX::ReadDataAsync(L"ModelPixelShader.cso");

	task<std::vector<byte>> loadGSTask;
	if (!m_usingVprtShaders)
	{
		// Load the pass-through geometry shader.
		loadGSTask = DX::ReadDataAsync(L"ModelGeometryShader.cso");
	}

	// After the vertex shader file is loaded, create the shader and input layout.
	task<void> createVSTask = loadVSTask.then([this](const std::vector<byte>& fileData)
	{
		DX::ThrowIfFailed(
			m_deviceResources->GetD3DDevice()->CreateVertexShader(
				&fileData[0],
				fileData.size(),
				nullptr,
				&m_vertexShader
			)
		);

		static const D3D11_INPUT_ELEMENT_DESC vertexDesc[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR",   0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		
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
	task<void> createPSTask = loadPSTask.then([this](const std::vector<byte>& fileData)
	{
		DX::ThrowIfFailed(
			m_deviceResources->GetD3DDevice()->CreatePixelShader(
				&fileData[0],
				fileData.size(),
				nullptr,
				&m_pixelShader
			)
		);

		const CD3D11_BUFFER_DESC constantBufferDesc(sizeof(ModelConstantBuffer), D3D11_BIND_CONSTANT_BUFFER);
		DX::ThrowIfFailed(
			m_deviceResources->GetD3DDevice()->CreateBuffer(
				&constantBufferDesc,
				nullptr,
				&m_modelConstantBuffer
			)
		);

		/*const CD3D11_BUFFER_DESC filterColorBufferDesc(sizeof(XMFLOAT4), D3D11_BIND_CONSTANT_BUFFER);
		DX::ThrowIfFailed(m_deviceResources->GetD3DDevice()->CreateBuffer(
			&filterColorBufferDesc,
			nullptr,
			&m_filterColorBuffer)
		);*/
	});

	task<void> createGSTask;
	if (!m_usingVprtShaders)
	{
		// After the pass-through geometry shader file is loaded, create the shader.
		createGSTask = loadGSTask.then([this](const std::vector<byte>& fileData)
		{
			DX::ThrowIfFailed(
				m_deviceResources->GetD3DDevice()->CreateGeometryShader(
					&fileData[0],
					fileData.size(),
					nullptr,
					&m_geometryShader
				)
			);
		});
	}

	// Once all shaders are loaded, create the mesh.
	task<void> shaderTaskGroup = m_usingVprtShaders ? (createPSTask && createVSTask) : (createPSTask && createVSTask && createGSTask);
	task<void> createCubeTask = shaderTaskGroup.then([this]()
	{


		// Load mesh vertices. Each vertex has a position and a color.
		// Note that the cube size has changed from the default DirectX app
		// template. Windows Holographic is scaled in meters, so to draw the
		
		//"Content\\Models\\mondeo_vignale_estate.lwo2.ply"
		// Load the model
	
			
		
	});

	task<std::vector<byte>> loadModelTask;
	if (m_useRelativePath)
	{
		loadModelTask = DX::ReadDataAsync(m_filename);
	}
	else
	{
		loadModelTask = DX::ReadFullPathDataAsync(m_filename);
	}
	 

	task<void> createModelTask = loadModelTask.then([this](const std::vector<byte>& fileData)
	{
		std::unique_ptr<Library::Model> model = std::make_unique<Library::Model>(LPVOID(&fileData[0]), fileData.size(), false);

	

		// Create vertex and index buffers for the model
		Library::Mesh* mesh = model->Meshes().at(0);
		CreateVertexBuffer(m_deviceResources->GetD3DDevice(), *mesh, &m_vertexBuffer);
		mesh->CreateIndexBuffer(m_deviceResources->GetD3DDevice(), &m_indexBuffer);
		m_indexCount = mesh->Indices().size();
		m_modelLoaded = true;

			
	});

	createModelTask.then([](task<void> t)
	{
		try
		{
			t.get();

		}
		catch(std::exception e)
		{
			std::string whatString(e.what());
			std::wstring whatw;
			whatw.assign(whatString.begin(), whatString.end());
			OutputDebugString(whatw.data());
		}

	}
	);
	

	// Once the cube is loaded, the object is ready to be rendered.
	createCubeTask.then([this]()
	{
		m_loadingComplete = true;
	});
}

void ModelRenderer::CreateVertexBuffer(ID3D11Device* device, const Library::Mesh& mesh, ID3D11Buffer** vertexBuffer) const
{
	const std::vector<XMFLOAT3>& sourceVertices = mesh.Vertices();

	std::vector<Library::VertexPositionColor> vertices;
	vertices.reserve(sourceVertices.size());
	if (mesh.VertexColors().size() > 0)
	{
		std::vector<XMFLOAT4>* vertexColors = mesh.VertexColors().at(0);
		assert(vertexColors->size() == sourceVertices.size());

		for (UINT i = 0; i < sourceVertices.size(); i++)
		{
			XMFLOAT3 position = sourceVertices.at(i);
			XMFLOAT4 color4 = vertexColors->at(i);
			//XMFLOAT3 color = { color4.w, color4.x, color4.y };

			vertices.push_back(Library::VertexPositionColor(XMFLOAT4(position.x, position.y, position.z, 1.0f),  color4));
		}
	}
	else
	{
		for (UINT i = 0; i < sourceVertices.size(); i++)
		{
			XMFLOAT3 position = sourceVertices.at(i);
			XMFLOAT4 color4 = Library::ColorHelper::RandomColor();
			//XMFLOAT3 color = { color4.w, color4.x, color4.y };

			vertices.push_back(Library::VertexPositionColor(XMFLOAT4(position.x, position.y, position.z, 1.0f),color4));
		}
	}

	D3D11_BUFFER_DESC vertexBufferDesc;
	ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));
	vertexBufferDesc.ByteWidth = sizeof(Library::VertexPositionColor) * vertices.size();
	vertexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA vertexSubResourceData;
	ZeroMemory(&vertexSubResourceData, sizeof(vertexSubResourceData));
	vertexSubResourceData.pSysMem = &vertices[0];
	device->CreateBuffer(&vertexBufferDesc, &vertexSubResourceData, vertexBuffer);
	//, "ID3D11Device::CreateBuffer() failed.");
}

void ModelRenderer::ReleaseDeviceDependentResources()
{
	m_loadingComplete = false;
	m_usingVprtShaders = false;
	m_vertexShader.Reset();
	m_inputLayout.Reset();
	m_pixelShader.Reset();
	m_geometryShader.Reset();
	m_modelConstantBuffer.Reset();
	m_vertexBuffer.Reset();
	m_indexBuffer.Reset();
	m_filterColorBuffer.Reset();
}

void ModelRenderer::CreateWindowSizeDependentResources()
{
}
