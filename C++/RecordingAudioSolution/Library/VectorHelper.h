#pragma once

#include "Common.h"

namespace Library
{
	class Vector2Helper
	{
	public:
		static const XMFLOAT2 Zero;
		static const XMFLOAT2 One;

		static std::string ToString(const XMFLOAT2& vector);

		Vector2Helper() = delete;
		Vector2Helper(const Vector2Helper& rhs) = delete;
		Vector2Helper& operator=(const Vector2Helper& rhs) = delete;		
	};

	class Vector3Helper
	{
	public:
		static const XMFLOAT3 Zero;
		static const XMFLOAT3 One;
		static const XMFLOAT3 Forward;
		static const XMFLOAT3 Backward;
		static const XMFLOAT3 Up;
		static const XMFLOAT3 Down;
		static const XMFLOAT3 Right;
		static const XMFLOAT3 Left;

		static std::string ToString(const XMFLOAT3& vector);

		Vector3Helper() = delete;
		Vector3Helper(const Vector3Helper& rhs) = delete;
		Vector3Helper& operator=(const Vector3Helper& rhs) = delete;		
	};

	class Vector4Helper
	{
	public:
		static const XMFLOAT4 Zero;
		static const XMFLOAT4 One;

		static std::string ToString(const XMFLOAT4& vector);

		Vector4Helper() = delete;
		Vector4Helper(const Vector3Helper& rhs) = delete;
		Vector4Helper& operator=(const Vector3Helper& rhs) = delete;		
	};
}