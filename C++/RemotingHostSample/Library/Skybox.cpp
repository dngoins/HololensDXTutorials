#include "Skybox.h"
#include "Game.h"
#include "GameException.h"
#include  "VertexDeclarations.h"
#include "Camera.h"
#include "MatrixHelper.h"
#include "Model.h"
#include "Mesh.h"
#include "Utility.h"
#include "DDSTextureLoader.h"
#include "RasterizerStates.h"

namespace Library
{
	RTTI_DEFINITIONS(Skybox)

	Skybox::Skybox(Game& game, Camera& camera, const std::wstring& cubeMapFileName, float scale)
		: DrawableGameComponent(game, camera), mCubeMapFileName(cubeMapFileName), mVertexShader(nullptr), mInputLayout(nullptr), mPixelShader(nullptr),
		  mVertexBuffer(nullptr), mIndexBuffer(nullptr), mVertexCBufferPerObject(nullptr), mVertexCBufferPerObjectData(),
		  mSkyboxTexture(nullptr), mTrilinearSampler(nullptr), mIndexCount(0),
		  mWorldMatrix(MatrixHelper::Identity), mScaleMatrix(MatrixHelper::Identity)
	{
		XMStoreFloat4x4(&mScaleMatrix, XMMatrixScaling(scale, scale, scale));
	}

	Skybox::~Skybox()
	{		
		ReleaseObject(mTrilinearSampler)
		ReleaseObject(mSkyboxTexture)
		ReleaseObject(mVertexCBufferPerObject)
		ReleaseObject(mIndexBuffer)
		ReleaseObject(mVertexBuffer)
		ReleaseObject(mPixelShader)
		ReleaseObject(mInputLayout)
		ReleaseObject(mVertexShader)
	}

	void Skybox::Initialize()
	{
		SetCurrentDirectory(Utility::ExecutableDirectory().c_str());

		// Load a compiled vertex shader
		std::vector<char> compiledVertexShader;
		Utility::LoadBinaryFile(L"Content\\Effects\\SkyboxVertexShader.cso", compiledVertexShader);
		ThrowIfFailed(mGame->Direct3DDevice()->CreateVertexShader(&compiledVertexShader[0], compiledVertexShader.size(), nullptr, &mVertexShader), "ID3D11Device::CreatedVertexShader() failed.");

		// Load a compiled pixel shader
		std::vector<char> compiledPixelShader;
		Utility::LoadBinaryFile(L"Content\\Effects\\SkyboxPixelShader.cso", compiledPixelShader);
		ThrowIfFailed(mGame->Direct3DDevice()->CreatePixelShader(&compiledPixelShader[0], compiledPixelShader.size(), nullptr, &mPixelShader), "ID3D11Device::CreatedPixelShader() failed.");

		// Create an input layout
		D3D11_INPUT_ELEMENT_DESC inputElementDescriptions[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};

		ThrowIfFailed(mGame->Direct3DDevice()->CreateInputLayout(inputElementDescriptions, ARRAYSIZE(inputElementDescriptions), &compiledVertexShader[0], compiledVertexShader.size(), &mInputLayout), "ID3D11Device::CreateInputLayout() failed.");

		// Load the model
		std::unique_ptr<Model> model = std::make_unique<Model>("Content\\Models\\Sphere.obj", true);

		// Create vertex and index buffers for the model
		Mesh* mesh = model->Meshes().at(0);
		CreateVertexBuffer(mGame->Direct3DDevice(), *mesh, &mVertexBuffer);
		mesh->CreateIndexBuffer(mGame->Direct3DDevice(),&mIndexBuffer);
		mIndexCount = mesh->Indices().size();

		ThrowIfFailed(DirectX::CreateDDSTextureFromFile(mGame->Direct3DDevice(), mCubeMapFileName.c_str(), nullptr, &mSkyboxTexture), "CreateDDSTextureFromFile() failed.");

		// Create constant buffer
		D3D11_BUFFER_DESC constantBufferDesc;
		ZeroMemory(&constantBufferDesc, sizeof(constantBufferDesc));
		constantBufferDesc.ByteWidth = sizeof(mVertexCBufferPerObjectData);
		constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		ThrowIfFailed(mGame->Direct3DDevice()->CreateBuffer(&constantBufferDesc, nullptr, &mVertexCBufferPerObject), "ID3D11Device::CreateBuffer() failed.");

		// Create a texture sampler
		D3D11_SAMPLER_DESC samplerDesc;
		ZeroMemory(&samplerDesc, sizeof(samplerDesc));
		samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
		samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
		samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

		ThrowIfFailed(mGame->Direct3DDevice()->CreateSamplerState(&samplerDesc, &mTrilinearSampler), "ID3D11Device::CreateSamplerState() failed.");
	}

	void Skybox::Update(const GameTime& gameTime)
	{
		const XMFLOAT3& position = mCamera->Position();

		XMStoreFloat4x4(&mWorldMatrix, XMLoadFloat4x4(&mScaleMatrix) * XMMatrixTranslation(position.x, position.y, position.z));
	}

	void Skybox::Draw(const GameTime& gameTime)
	{
		ID3D11DeviceContext* direct3DDeviceContext = mGame->Direct3DDeviceContext();
		direct3DDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		direct3DDeviceContext->IASetInputLayout(mInputLayout);

		UINT stride = sizeof(VertexPosition);
		UINT offset = 0;
		direct3DDeviceContext->IASetVertexBuffers(0, 1, &mVertexBuffer, &stride, &offset);
		direct3DDeviceContext->IASetIndexBuffer(mIndexBuffer, DXGI_FORMAT_R32_UINT, 0);

		direct3DDeviceContext->VSSetShader(mVertexShader, nullptr, 0);
		direct3DDeviceContext->PSSetShader(mPixelShader, nullptr, 0);

		XMMATRIX worldMatrix = XMLoadFloat4x4(&mWorldMatrix);
		XMMATRIX wvp = worldMatrix * mCamera->ViewProjectionMatrix();
		XMStoreFloat4x4(&mVertexCBufferPerObjectData.WorldViewProjection, XMMatrixTranspose(wvp));

		direct3DDeviceContext->UpdateSubresource(mVertexCBufferPerObject, 0, nullptr, &mVertexCBufferPerObjectData, 0, 0);
		direct3DDeviceContext->VSSetConstantBuffers(0, 1, &mVertexCBufferPerObject);

		direct3DDeviceContext->PSSetShaderResources(0, 1, &mSkyboxTexture);
		direct3DDeviceContext->PSSetSamplers(0, 1, &mTrilinearSampler);

		direct3DDeviceContext->RSSetState(RasterizerStates::DisabledCulling);
		direct3DDeviceContext->DrawIndexed(mIndexCount, 0, 0);
		direct3DDeviceContext->RSSetState(nullptr);
	}

	void Skybox::CreateVertexBuffer(ID3D11Device* device, const Mesh& mesh, ID3D11Buffer** vertexBuffer) const
	{
		const std::vector<XMFLOAT3>& sourceVertices = mesh.Vertices();
		std::vector<XMFLOAT3>* textureCoordinates = mesh.TextureCoordinates().at(0);
		assert(textureCoordinates->size() == sourceVertices.size());
		const std::vector<XMFLOAT3>& normals = mesh.Normals();
		assert(normals.size() == sourceVertices.size());

		std::vector<VertexPosition> vertices;
		vertices.reserve(sourceVertices.size());
		for (UINT i = 0; i < sourceVertices.size(); i++)
		{
			XMFLOAT3 position = sourceVertices.at(i);
			vertices.push_back(VertexPosition(XMFLOAT4(position.x, position.y, position.z, 1.0f)));
		}

		D3D11_BUFFER_DESC vertexBufferDesc;
		ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));
		vertexBufferDesc.ByteWidth = sizeof(VertexPosition) * vertices.size();
		vertexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA vertexSubResourceData;
		ZeroMemory(&vertexSubResourceData, sizeof(vertexSubResourceData));
		vertexSubResourceData.pSysMem = &vertices[0];
		ThrowIfFailed(mGame->Direct3DDevice()->CreateBuffer(&vertexBufferDesc, &vertexSubResourceData, vertexBuffer), "ID3D11Device::CreateBuffer() failed.");
	}
}