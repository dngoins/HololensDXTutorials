#pragma once

namespace RecordingAudio
{
	struct VertexPosition
	{
		XMFLOAT4 Position;

		VertexPosition() { }

		VertexPosition(const XMFLOAT4& position)
			: Position(position) { }
	};

	struct VertexPositionColor3
	{
		XMFLOAT3 Position;
		XMFLOAT3 Color;

		VertexPositionColor3() { }

		VertexPositionColor3(const XMFLOAT3& position, const XMFLOAT3& color)
			: Position(position), Color(color) { }
	};

	struct Vertex_Position_Color
	{
		XMFLOAT4 Position;
		XMFLOAT4 Color;

		Vertex_Position_Color() { }

		Vertex_Position_Color(const XMFLOAT4& position, const XMFLOAT4& color)
			: Position(position), Color(color) { }
	};

	struct VertexPositionNormalColor3
	{
		XMFLOAT3 Position;
		XMFLOAT3 Normal;
		XMFLOAT3 Color;

		VertexPositionNormalColor3() { }

		VertexPositionNormalColor3(const XMFLOAT3& position, const XMFLOAT3& normal, const XMFLOAT3& color)
			: Position(position), Normal(normal), Color(color) { }
	};

	struct VertexPositionTexture
	{
		XMFLOAT4 Position;
		XMFLOAT2 TextureCoordinates;

		VertexPositionTexture() { }

		VertexPositionTexture(const XMFLOAT4& position, const XMFLOAT2& textureCoordinates)
			: Position(position), TextureCoordinates(textureCoordinates) { }
	};

	struct VertexPositionSize
	{
		XMFLOAT4 Position;
		XMFLOAT2 Size;

		VertexPositionSize() { }

		VertexPositionSize(const XMFLOAT4& position, const XMFLOAT2& size)
			: Position(position), Size(size) { }
	};

	struct VertexPositionNormal
	{
		XMFLOAT4 Position;
		XMFLOAT3 Normal;

		VertexPositionNormal() { }

		VertexPositionNormal(const XMFLOAT4& position, const XMFLOAT3& normal)
			: Position(position), Normal(normal) { }
	};

	struct VertexPositionTextureNormal
	{
		XMFLOAT4 Position;
		XMFLOAT2 TextureCoordinates;
		XMFLOAT3 Normal;

		VertexPositionTextureNormal() { }

		VertexPositionTextureNormal(const XMFLOAT4& position, const XMFLOAT2& textureCoordinates, const XMFLOAT3& normal)
			: Position(position), TextureCoordinates(textureCoordinates), Normal(normal) { }
	};

	struct VertexPositionTextureNormalTangent
	{
		XMFLOAT4 Position;
		XMFLOAT2 TextureCoordinates;
		XMFLOAT3 Normal;
		XMFLOAT3 Tangent;

		VertexPositionTextureNormalTangent() { }

		VertexPositionTextureNormalTangent(const XMFLOAT4& position, const XMFLOAT2& textureCoordinates, const XMFLOAT3& normal, const XMFLOAT3& tangent)
			: Position(position), TextureCoordinates(textureCoordinates), Normal(normal), Tangent(tangent) { }
	};

    // Constant buffer used to send hologram position transform to the shader pipeline.
    struct ModelConstantBuffer
    {
        DirectX::XMFLOAT4X4 model;
    };

    // Assert that the constant buffer remains 16-byte aligned (best practice).
    static_assert((sizeof(ModelConstantBuffer) % (sizeof(float) * 4)) == 0, "Model constant buffer size must be 16-byte aligned (16 bytes is the length of four floats).");


    // Used to send per-vertex data to the vertex shader.
    struct VertexPositionColor
    {
        DirectX::XMFLOAT3 pos;
        DirectX::XMFLOAT3 color;
    };


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

	namespace Mesh
	{
		// Constant buffer used to send hologram position transform to the shader pipeline.
		struct ModelConstantBuffer
		{
			DirectX::XMFLOAT4X4 model;
			DirectX::XMFLOAT4X4 normal; // Normal transform matrix.
		};

		// Assert that the constant buffer remains 16-byte aligned (best practice).
		static_assert((sizeof(ModelConstantBuffer) % (sizeof(float) * 4)) == 0, "Model constant buffer size must be 16-byte aligned (16 bytes is the length of four floats).");

		// Constant buffer used to send hologram position transform to the shader pipeline.
		struct SpatialModelConstantBuffer
		{
			DirectX::XMFLOAT4X4 modelToWorld;
		};

		// Assert that the constant buffer remains 16-byte aligned (best practice).
		// If shader structure members are not aligned to a 4-float boundary, data may
		// not show up where it is expected by the time it is read by the shader.
		static_assert((sizeof(SpatialModelConstantBuffer) % (sizeof(float) * 4)) == 0, "Model constant buffer size must be 16-byte aligned (16 bytes is the length of four floats).");

		// Constant buffer used to send hologram position and normal transforms to the shader pipeline.
		struct ModelNormalConstantBuffer
		{
			DirectX::XMFLOAT4X4 modelToWorld;
			DirectX::XMFLOAT4X4 normalToWorld;
			DirectX::XMFLOAT4   colorFadeFactor;
		};

		// Assert that the constant buffer remains 16-byte aligned (best practice).
		// If shader structure members are not aligned to a 4-float boundary, data may
		// not show up where it is expected by the time it is read by the shader.
		static_assert((sizeof(ModelNormalConstantBuffer) % (sizeof(float) * 4)) == 0, "Model/normal constant buffer size must be 16-byte aligned (16 bytes is the length of four floats).");


		// Constant buffer used to send the view-projection matrices to the shader pipeline.
		struct ViewProjectionConstantBuffer
		{
			DirectX::XMFLOAT4   cameraPosition;
			DirectX::XMFLOAT4   lightPosition;
			DirectX::XMFLOAT4X4 viewProjection[2];
		};

		// Assert that the constant buffer remains 16-byte aligned (best practice).
		static_assert((sizeof(ViewProjectionConstantBuffer) % (sizeof(float) * 4)) == 0, "View/projection constant buffer size must be 16-byte aligned (16 bytes is the length of four floats).");


		// Used to send per-vertex data to the vertex shader.
		struct VertexPositionNormalColor
		{
			DirectX::XMFLOAT3 pos;
			DirectX::XMFLOAT3 normal; // Normal.
			DirectX::XMFLOAT3 color;
		};

		// Used to send per-vertex data to the vertex shader.
		struct VertexPositionColor
		{
			DirectX::XMFLOAT3 pos;
			DirectX::XMFLOAT3 color;
		};

		struct VertexPositionNormalTexture
		{
			DirectX::XMFLOAT3 pos;
			DirectX::XMFLOAT3 normal;
			DirectX::XMFLOAT2 texture;

			VertexPositionNormalTexture() {}

			VertexPositionNormalTexture(const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& normal, const DirectX::XMFLOAT2& texture) : pos(position), normal(normal), texture(texture) { }
		};


	}
}