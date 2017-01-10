#pragma once

#include <agile.h>
#include <concrt.h>
#include <d2d1_2.h>
#include <d2d1effects_1.h>
#include <d3d11_4.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#include <dwrite_2.h>
#include <dxgi1_5.h>
#include <wincodec.h>
#include <WindowsNumerics.h>
#include <wrl.h>
#include <memory>
#include <map>
#include <mutex>

#include <exception>
#include <cassert>
#include <string>
#include <vector>
#include <stack>

#include <DirectXPackedVector.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#define DeleteObject(object) if((object) != nullptr) { delete object; object = nullptr; }
#define DeleteObjects(objects) if((objects) != nullptr) { delete[] objects; objects = nullptr; }
#define ReleaseObject(object) if((object) != nullptr) { object->Release(); object = nullptr; }


using namespace DirectX;
using namespace DirectX::PackedVector;

#define ASSERT(expression) _ASSERTE(expression)
D2D1_COLOR_F	const COLOR_BLUE = { 0.26f, 0.56f, 0.87f, 1.0f };
D2D1_COLOR_F	const COLOR_DARKBLUE = { 0.0f, 0.0f, 1.0f, 1.0f };
D2D1_COLOR_F	const COLOR_YELLOW = { 0.99f, 0.85f, 0.0f, 1.0f };
D2D1_COLOR_F	const COLOR_BLACK = { 0.0f, 0.0f, 0.07f, 1.0f };
D2D1_COLOR_F	const COLOR_WHITE = { 1.0f, 1.0f, 1.0f, 1.0f };
D2D1_COLOR_F	const COLOR_GREEN = { 0.0f, 1.0f, 0.0f, 1.0f };
D2D1_COLOR_F	const COLOR_RED = { 1.0f, 0.0f, 0.0f, 1.0f };

#define VERIFY(expression)	ASSERT(expression)

#ifdef __cplusplus_winrt

namespace win {
	using namespace Platform;
	using namespace Windows::ApplicationModel::Core;
	using namespace Windows::UI::Core;
	using namespace Windows::Graphics::Display;
}

inline void HR(HRESULT const hr)
{
	if (S_OK != hr) throw win::Exception::CreateException(hr);
}
#else
#define HR(expression)	ASSERT(S_OK == (expression	))

#endif

inline void TRACE(WCHAR const * const format, ...)
{
	va_list args;
	va_start(args, format);

	WCHAR output[512];
	vswprintf_s(output, format, args);

	OutputDebugString(output);

	va_end(args);
}

// Safe release for interfaces
template<class Interface>
inline void SafeRelease(Microsoft::WRL::ComPtr<Interface> pInterfaceToRelease)
{
	if (pInterfaceToRelease)
	{

		pInterfaceToRelease.Reset();
		pInterfaceToRelease = nullptr;
	}
}
