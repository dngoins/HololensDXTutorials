#pragma once

#include "Common.h"

namespace MatMeshModLibrary
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

	struct VertexPositionColor
    {
        XMFLOAT4 Position;
        XMFLOAT4 Color;

        VertexPositionColor() { }

		VertexPositionColor(const XMFLOAT4& position, const XMFLOAT4& color)
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
}
