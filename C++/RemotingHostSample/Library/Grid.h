#pragma once

#include "Common.h"
#include "DrawableGameComponent.h"

namespace Library
{
	class Grid : public DrawableGameComponent
	{
		RTTI_DECLARATIONS(Grid, DrawableGameComponent)

	public:
		Grid(Game& game, Camera& camera);
		Grid(Game& game, Camera& camera, UINT size, UINT scale, const XMFLOAT4& color);
		~Grid();

		Grid() = delete;
		Grid(const Grid& rhs) = delete;
		Grid& operator=(const Grid& rhs) = delete;

		const XMFLOAT3& Position() const;
		const XMFLOAT4 Color() const;
		const UINT Size() const;
		const UINT Scale() const;

		void SetPosition(const XMFLOAT3& position);
		void SetPosition(float x, float y, float z);
		void SetColor(const XMFLOAT4& color);
		void SetSize(UINT size);
		void SetScale(UINT scale);

		virtual void Initialize() override;
		virtual void Draw(const GameTime& gameTime) override;

	private:
		struct VertexCBufferPerObject
		{
			XMFLOAT4X4 WorldViewProjection;

			VertexCBufferPerObject() : WorldViewProjection() { }

			VertexCBufferPerObject(const XMFLOAT4X4& wvp) : WorldViewProjection(wvp) { }
		};

		void InitializeGrid();

		static const UINT DefaultSize;
		static const UINT DefaultScale;
		static const XMFLOAT4 DefaultColor;

		ID3D11VertexShader* mVertexShader;
		ID3D11PixelShader* mPixelShader;
		ID3D11InputLayout* mInputLayout;
		ID3D11Buffer* mVertexBuffer;
		ID3D11Buffer* mVertexCBufferPerObject;
		VertexCBufferPerObject mVertexCBufferPerObjectData;
	
		XMFLOAT3 mPosition;
		UINT mSize;
		UINT mScale;
		XMFLOAT4 mColor;
		XMFLOAT4X4 mWorldMatrix;
	};
}