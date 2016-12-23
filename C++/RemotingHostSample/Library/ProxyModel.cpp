#include "ProxyModel.h"
#include "Game.h"
#include "GameException.h"
#include "Camera.h"
#include "MatrixHelper.h"
#include "VectorHelper.h"
#include "ColorHelper.h"
#include "Model.h"
#include "Mesh.h"
#include "Utility.h"
#include "RasterizerStates.h"
#include "VertexDeclarations.h"

namespace Library
{
	RTTI_DEFINITIONS(ProxyModel)

	ProxyModel::ProxyModel(Game& game, Camera& camera, const std::string& modelFileName, float scale)
		: DrawableGameComponent(game, camera),
		  mModelFileName(modelFileName), mVertexShader(nullptr), mPixelShader(nullptr), mInputLayout(nullptr),
		  mVertexBuffer(nullptr), mIndexBuffer(nullptr), mIndexCount(0),
		  mVertexCBufferPerObject(nullptr), mVertexCBufferPerObjectData(),		  
		  mWorldMatrix(MatrixHelper::Identity), mScaleMatrix(MatrixHelper::Identity), mDisplayWireframe(true),
		  mPosition(Vector3Helper::Zero), mDirection(Vector3Helper::Forward), mUp(Vector3Helper::Up), mRight(Vector3Helper::Right)
	{
		XMStoreFloat4x4(&mScaleMatrix, XMMatrixScaling(scale, scale, scale));
	}

	ProxyModel::~ProxyModel()
	{
		ReleaseObject(mVertexCBufferPerObject)
		ReleaseObject(mIndexBuffer)
		ReleaseObject(mVertexBuffer)
		ReleaseObject(mInputLayout)
		ReleaseObject(mPixelShader)
		ReleaseObject(mVertexShader)		
	}

	const XMFLOAT3& ProxyModel::Position() const
    {
        return mPosition;
    }

    const XMFLOAT3& ProxyModel::Direction() const
    {
        return mDirection;
    }
    
    const XMFLOAT3& ProxyModel::Up() const
    {
        return mUp;
    }

    const XMFLOAT3& ProxyModel::Right() const
    {
        return mRight;
    }

    XMVECTOR ProxyModel::PositionVector() const
    {
        return XMLoadFloat3(&mPosition);
    }

    XMVECTOR ProxyModel::DirectionVector() const
    {
        return XMLoadFloat3(&mDirection);
    }

    XMVECTOR ProxyModel::UpVector() const
    {
        return XMLoadFloat3(&mUp);
    }
    
    XMVECTOR ProxyModel::RightVector() const
    {
        return XMLoadFloat3(&mRight);
    }

	bool& ProxyModel::DisplayWireframe()
	{
		return mDisplayWireframe;
	}

	void ProxyModel::SetPosition(FLOAT x, FLOAT y, FLOAT z)
    {
        XMVECTOR position = XMVectorSet(x, y, z, 1.0f);
        SetPosition(position);
    }

    void ProxyModel::SetPosition(FXMVECTOR position)
    {
        XMStoreFloat3(&mPosition, position);
    }

    void ProxyModel::SetPosition(const XMFLOAT3& position)
    {
        mPosition = position;
    }

	void ProxyModel::ApplyRotation(CXMMATRIX transform)
    {
        XMVECTOR direction = XMLoadFloat3(&mDirection);
        XMVECTOR up = XMLoadFloat3(&mUp);
        
        direction = XMVector3TransformNormal(direction, transform);
        direction = XMVector3Normalize(direction);

        up = XMVector3TransformNormal(up, transform);
        up = XMVector3Normalize(up);

        XMVECTOR right = XMVector3Cross(direction, up);
        up = XMVector3Cross(right, direction);

        XMStoreFloat3(&mDirection, direction);
        XMStoreFloat3(&mUp, up);
        XMStoreFloat3(&mRight, right);
    }

    void ProxyModel::ApplyRotation(const XMFLOAT4X4& transform)
    {
        XMMATRIX transformMatrix = XMLoadFloat4x4(&transform);
        ApplyRotation(transformMatrix);
    }

	void ProxyModel::Initialize()
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

		// Load a model
		std::unique_ptr<Model> model(new Model( mModelFileName, true));

		Mesh* mesh = model->Meshes().at(0);
		CreateVertexBuffer(mGame->Direct3DDevice(), *mesh, &mVertexBuffer);
		mesh->CreateIndexBuffer(mGame->Direct3DDevice(), &mIndexBuffer);
		mIndexCount = mesh->Indices().size();
	}

	void ProxyModel::Update(const GameTime& gameTime)
	{
		XMMATRIX worldMatrix = XMMatrixIdentity();
		MatrixHelper::SetForward(worldMatrix, mDirection);
		MatrixHelper::SetUp(worldMatrix, mUp);
		MatrixHelper::SetRight(worldMatrix, mRight);
		MatrixHelper::SetTranslation(worldMatrix, mPosition);

		XMStoreFloat4x4(&mWorldMatrix, XMLoadFloat4x4(&mScaleMatrix) * worldMatrix);
	}

	void ProxyModel::Draw(const GameTime& gameTime)
	{
		ID3D11DeviceContext* direct3DDeviceContext = mGame->Direct3DDeviceContext();			
		direct3DDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		direct3DDeviceContext->IASetInputLayout(mInputLayout);

		UINT stride = sizeof(VertexPositionColor);
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

		if (mDisplayWireframe)
		{
			mGame->Direct3DDeviceContext()->RSSetState(RasterizerStates::Wireframe);
			direct3DDeviceContext->DrawIndexed(mIndexCount, 0, 0);
			mGame->Direct3DDeviceContext()->RSSetState(nullptr);
		}
		else
		{
			direct3DDeviceContext->DrawIndexed(mIndexCount, 0, 0);
		}
	}

	void ProxyModel::CreateVertexBuffer(ID3D11Device* device, const Mesh& mesh, ID3D11Buffer** vertexBuffer) const
	{
		const std::vector<XMFLOAT3>& sourceVertices = mesh.Vertices();

		std::vector<VertexPositionColor> vertices;
		vertices.reserve(sourceVertices.size());
		if (mesh.VertexColors().size() > 0)
		{
			std::vector<XMFLOAT4>* vertexColors = mesh.VertexColors().at(0);
			assert(vertexColors->size() == sourceVertices.size());

			for (UINT i = 0; i < sourceVertices.size(); i++)
			{
				XMFLOAT3 position = sourceVertices.at(i);
				XMFLOAT4 color = vertexColors->at(i);
				vertices.push_back(VertexPositionColor(XMFLOAT4(position.x, position.y, position.z, 1.0f), color));
			}
		}
		else
		{
			XMFLOAT4 color = XMFLOAT4(reinterpret_cast<const float*>(&ColorHelper::White));
			for (UINT i = 0; i < sourceVertices.size(); i++)
			{
				XMFLOAT3 position = sourceVertices.at(i);
				vertices.push_back(VertexPositionColor(XMFLOAT4(position.x, position.y, position.z, 1.0f), color));
			}
		}

		D3D11_BUFFER_DESC vertexBufferDesc;
		ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));
		vertexBufferDesc.ByteWidth = sizeof(VertexPositionColor) * vertices.size();
		vertexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA vertexSubResourceData;
		ZeroMemory(&vertexSubResourceData, sizeof(vertexSubResourceData));
		vertexSubResourceData.pSysMem = &vertices[0];
		ThrowIfFailed(device->CreateBuffer(&vertexBufferDesc, &vertexSubResourceData, vertexBuffer), "ID3D11Device::CreateBuffer() failed.");
	}
}