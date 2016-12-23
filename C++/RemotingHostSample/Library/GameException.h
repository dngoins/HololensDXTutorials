#pragma once

#include <exception>
#include <Windows.h>
#include <string>

namespace Library
{
	class GameException : public std::exception
	{
	public:
		GameException(const char* const& message, HRESULT hr = S_OK);

		HRESULT HR() const;
		std::wstring whatw() const;

	private:
		HRESULT mHR;
	};

	inline void ThrowIfFailed(HRESULT hr, const char* const& message = "")
	{
		if (FAILED(hr))
		{
			throw GameException(message, hr);
		}
	}
}
