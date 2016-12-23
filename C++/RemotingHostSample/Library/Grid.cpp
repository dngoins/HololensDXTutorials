#include "Grid.h"
#include "Game.h"
#include "GameException.h"
#include "Camera.h"
#include "VectorHelper.h"
#include "MatrixHelper.h"
#include "Utility.h"
#include "VertexDeclarations.h"

namespace Library
{
	RTTI_DEFINITIONS(Grid)

	const UINT Grid::DefaultSize = 16;
	const UINT Grid::DefaultScale = 16;
	const XMFLOAT4 Grid::DefaultColor = XMFLOAT4(0.961f, 0.871f, 0.702f, 1.0f);

	Grid::Grid(Game& game, Camera& camera)
		: DrawableGameComponent(game), mVertexShader(nullptr), mPixelShader(nullptr), mInputLayout(nullptr), mVertexBuffer(nullptr),
		  mVertexCBufferPerObject(nullptr), mVertexCBufferPerObjectData(),
		  mPosition(Vector3Helper::Zero), mSize(DefaultSize), mScale(DefaultScale), mColor(DefaultColor), mWorldMatrix(MatrixHelper::Identity)
	{
		mCamera = &camera;
	}

	Grid::Grid(Game& game, Camera& camera, UINT size, UINT scale, const XMFLOAT4& color)
		: DrawableGameComponent(game), mVertexShader(nullptr), mPixelShader(nullptr), mInputLayout(nullptr), mVertexBuffer(nullptr),
		  mVertexCBufferPerObject(nullptr), mVertexCBufferPerObjectData(),
		  mPosition(Vector3Helper::Zero), mSize(size), mScale(scale), mColor(color), mWorldMatrix(MatrixHelper::Identity)
	{
		mCamera = &camera;
	}
	
	Grid::~Grid()
	{
		ReleaseObject(mVertexCBufferPerObject)
		ReleaseObject(mVertexBuffer)
		ReleaseObject(mInputLayout)
		ReleaseObject(mPixelShader)
		ReleaseObject(mVertexShader)
	}

	const XMFLOAT3& Grid::Position() const
	{
		return mPosition;
	}

	const XMFLOAT4 Grid::Color() const
	{
		return mColor;
	}

	const UINT Grid::Size() const
	{
		return mSize;
	}

	const UINT Grid::Scale() const
	{
		return mScale;
	}

	void Grid::SetPosition(const XMFLOAT3& position)
	{
		mPosition = position;

		XMMATRIX translation = XMMatrixTranslation(mPosition.x, mPosition.y, mPosition.z);
		XMStoreFloat4x4(&mWorldMatrix, translation);
	}

	void Grid::SetPosition(float x, float y, float z)
	{
		mPosition.x = x;
		mPosition.y = y;
		mPosition.z = z;
		
		XMMATRIX translation = XMMatrixTranslation(mPosition.x, mPosition.y, mPosition.z);
		XMStoreFloat4x4(&mWorldMatrix, translation);
	}

	void Grid::SetColor(const XMFLOAT4& color)
	{
		mColor = color;
		InitializeGrid();
	}

	void Grid::SetSize(UINT size)
	{
		mSize = size;
		InitializeGrid();
	}

	void Grid::SetScale(UINT scale)
	{
		mScale = scale;
		InitializeGrid();
	}

	void Grid::Initialize()
	{
		SetCurrentDirectory(Utility::ExecutableDirectory().c_str());

		// Load a compiled vertex shader
		std::vector<char> compiledVertexShader;
		Utility::LoadBinaryFile(L"Content\\Effects\\BasicVS.cso", compiledVertexShader);
		ThrowIfFailed(mGame->Direct3DDevice()->CreateVertexShader(&compiledVertexShader[0], compiledVertexShader.size(), nullptr, &mVertexShader), "ID3D11Device::CreatedVertexShader() failed.");

		// Load a compiled pixel shader
		std::vector<char> compiledPixelShader;
		Utility::LoadBinaryFile(L"Content\\Effects\\BasicPS.cso", compiledPixelShader);
		ThrowIfFailed(mGame->Direct3DDevice()->CreatePixelShader(&compiledPixelShader[0], compiledPixelShader.size(), nullptr, &mPixelShader), "ID3D11Device::CreatedPixelShader() failed.");

		// Create an input layout
		D3D11_INPUT_ELEMENT_DESC inputElementDescriptions[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};

		ThrowIfFailed(mGame->Direct3DDevice()->CreateInputLayout(inputElementDescriptions, ARRAYSIZE(inputElementDescriptions), &compiledVertexShader[0], compiledVertexShader.size(), &mInputLayout), "ID3D11Device::CreateInputLayout() failed.");

		// Create constant buffers
		D3D11_BUFFER_DESC constantBufferDesc;
		ZeroMemory(&constantBufferDesc, sizeof(constantBufferDesc));
		constantBufferDesc.ByteWidth = sizeof(mVertexCBufferPerObjectData);
		constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		ThrowIfFailed(mGame->Direct3DDevice()->CreateBuffer(&constantBufferDesc, nullptr, &mVertexCBufferPerObject), "ID3D11Device::CreateBuffer() failed.");

		InitializeGrid();
	}

	void Grid::Draw(const GameTime& gameTime)
	{
		ID3D11DeviceContext* direct3DDeviceContext = mGame->Direct3DDeviceContext();
		direct3DDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
		direct3DDeviceContext->IASetInputLayout(mInputLayout);

		UINT stride = sizeof(VertexPositionColor);
		UINT offset = 0;
		direct3DDeviceContext->IASetVertexBuffers(0, 1, &mVertexBuffer, &stride, &offset);

		direct3DDeviceContext->VSSetShader(mVertexShader, nullptr, 0);
		direct3DDeviceContext->PSSetShader(mPixelShader, nullptr, 0);
		
		XMMATRIX worldMatrix = XMLoadFloat4x4(&mWorldMatrix);
		XMMATRIX wvp = worldMatrix * mCamera->ViewProjectionMatrix();
		XMStoreFloat4x4(&mVertexCBufferPerObjectData.WorldViewProjection, XMMatrixTranspose(wvp));

		direct3DDeviceContext->UpdateSubresource(mVertexCBufferPerObject, 0, nullptr, &mVertexCBufferPerObjectData, 0, 0);
		direct3DDeviceContext->VSSetConstantBuffers(0, 1, &mVertexCBufferPerObject);
		
		direct3DDeviceContext->Draw((mSize + 1) * 4, 0);
	}

	void Grid::InitializeGrid()
	{
		ReleaseObject(mVertexBuffer);

		ID3D11Device* direct3DDevice = GetGame()->Direct3DDevice();
		int length = 4 * (mSize + 1);
		int size = sizeof(VertexPositionColor) * length;
		std::unique_ptr<VertexPositionColor[]> vertexData(new VertexPositionColor[length]);		
		VertexPositionColor* vertices = vertexData.get();

		float adjustedScale = mScale * 0.1f;
		float maxPosition = mSize * adjustedScale / 2;

        for (unsigned int i = 0, j = 0; i < mSize + 1; i++, j = 4 * i)
        {
            float position = maxPosition - (i * adjustedScale);

            // Vertical line
			vertices[j] = VertexPositionColor(XMFLOAT4(position, 0.0f, maxPosition, 1.0f), mColor);
            vertices[j + 1] = VertexPositionColor(XMFLOAT4(position, 0.0f, -maxPosition, 1.0f), mColor);

            // Horizontal line
            vertices[j + 2] = VertexPositionColor(XMFLOAT4(maxPosition, 0.0f, position, 1.0f), mColor);
            vertices[j + 3] = VertexPositionColor(XMFLOAT4(-maxPosition, 0.0f, position, 1.0f), mColor);
        }

		D3D11_BUFFER_DESC vertexBufferDesc;
		ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));
		vertexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
		vertexBufferDesc.ByteWidth = size;
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA vertexSubResourceData;
		ZeroMemory(&vertexSubResourceData, sizeof(vertexSubResourceData));
		vertexSubResourceData.pSysMem = vertices;		
		
		ThrowIfFailed(direct3DDevice->CreateBuffer(&vertexBufferDesc, &vertexSubResourceData, &mVertexBuffer), "ID3D11Device::CreateBuffer() failed");
	}
}