#pragma once

#include "Common.h"

namespace Library
{
	class MathHelper
	{
	public:
		static float Clamp(float value, float min, float max);
		static float Saturate(float value);
		static UINT Saturate(UINT value);
	};

	inline float MathHelper::Clamp(float value, float min, float max)
	{
		return value < min ? min : (value > max ? max : value);
	}

	inline float MathHelper::Saturate(float value)
	{
		return value < 0.0f ? 0.0f : (value > 1.0f ? 1.0f : value);
	}

	inline UINT MathHelper::Saturate(UINT value)
	{
		return value < 0 ? 0 : (value > 255 ? 255 : value);
	}
}
