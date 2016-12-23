#pragma once

#include "Common.h"
#include "DrawableGameComponent.h"

namespace Library
{
	class Mesh;

	class ProxyModel : public DrawableGameComponent
	{
		RTTI_DECLARATIONS(ProxyModel, DrawableGameComponent)

	public:
		ProxyModel(Game& game, Camera& camera, const std::string& modelFileName, float scale = 1.0f);
		~ProxyModel();

		ProxyModel() = delete;
		ProxyModel(const ProxyModel& rhs) = delete;
		ProxyModel& operator=(const ProxyModel& rhs) = delete;

		const XMFLOAT3& Position() const;
        const XMFLOAT3& Direction() const;
        const XMFLOAT3& Up() const;
        const XMFLOAT3& Right() const;

		XMVECTOR PositionVector() const;
        XMVECTOR DirectionVector() const;
        XMVECTOR UpVector() const;
        XMVECTOR RightVector() const;

		bool& DisplayWireframe();

		void SetPosition(FLOAT x, FLOAT y, FLOAT z);
        void SetPosition(FXMVECTOR position);
        void SetPosition(const XMFLOAT3& position);

		void ApplyRotation(CXMMATRIX transform);
        void ApplyRotation(const XMFLOAT4X4& transform);

		virtual void Initialize() override;
		virtual void Update(const GameTime& gameTime) override;		
		virtual void Draw(const GameTime& gameTime) override;

	private:
		struct VertexCBufferPerObject
		{
			XMFLOAT4X4 WorldViewProjection;

			VertexCBufferPerObject() : WorldViewProjection() { }

			VertexCBufferPerObject(const XMFLOAT4X4& wvp) : WorldViewProjection(wvp) { }
		};

		void CreateVertexBuffer(ID3D11Device* device, const Mesh& mesh, ID3D11Buffer** vertexBuffer) const;

		std::string mModelFileName;
		ID3D11VertexShader* mVertexShader;
		ID3D11PixelShader* mPixelShader;
		ID3D11InputLayout* mInputLayout;
		ID3D11Buffer* mVertexBuffer;
		ID3D11Buffer* mIndexBuffer;
		UINT mIndexCount;
		ID3D11Buffer* mVertexCBufferPerObject;
		VertexCBufferPerObject mVertexCBufferPerObjectData;
        
		XMFLOAT4X4 mWorldMatrix;
		XMFLOAT4X4 mScaleMatrix;

		bool mDisplayWireframe;
		XMFLOAT3 mPosition;
		XMFLOAT3 mDirection;
        XMFLOAT3 mUp;
        XMFLOAT3 mRight;
	};
}