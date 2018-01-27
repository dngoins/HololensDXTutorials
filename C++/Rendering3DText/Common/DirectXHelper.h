#pragma once

#include <ppltasks.h>    // For create_task

namespace DX
{
	class com_exception : public std::exception
	{
	public:
		com_exception(HRESULT hr) : result(hr) {}

		virtual const char* what() const override
		{
			static char s_str[64] = {};
			sprintf_s(s_str, "Failure with HRESULT of %08X", static_cast<unsigned int>(result));
			return s_str;
		}

	private:
		HRESULT result;
	};

	// Helper utility converts D3D API failures into exceptions.
	inline void ThrowIfFailed(HRESULT hr, bool use_standard )
	{
		if (FAILED(hr))
		{
			throw com_exception(hr);
		}
	}


	// Helper for output debug tracing
	inline void DebugTrace(_In_z_ _Printf_format_string_ const char* format, ...)
	{
#ifdef _DEBUG
		va_list args;
		va_start(args, format);

		char buff[1024] = {};
		vsprintf_s(buff, format, args);
		OutputDebugStringA(buff);
		va_end(args);
#else
		UNREFERENCED_PARAMETER(format);
#endif
	}


    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            // Set a breakpoint on this line to catch Win32 API errors.
            throw Platform::Exception::CreateException(hr);
        }
    }

    // Function that reads from a binary file asynchronously.
    inline Concurrency::task<std::vector<byte>> ReadDataAsync(const std::wstring& filename)
    {
        using namespace Windows::Storage;
        using namespace Concurrency;

        return create_task(PathIO::ReadBufferAsync(Platform::StringReference(filename.c_str()))).then(
            [] (Streams::IBuffer^ fileBuffer) -> std::vector<byte>
            {
                std::vector<byte> returnBuffer;
                returnBuffer.resize(fileBuffer->Length);
                Streams::DataReader::FromBuffer(fileBuffer)->ReadBytes(Platform::ArrayReference<byte>(returnBuffer.data(), returnBuffer.size()));
                return returnBuffer;
            });
    }

    // Converts a length in device-independent pixels (DIPs) to a length in physical pixels.
    inline float ConvertDipsToPixels(float dips, float dpi)
    {
        static const float dipsPerInch = 96.0f;
        return floorf(dips * dpi / dipsPerInch + 0.5f); // Round to nearest integer.
    }

#if defined(_DEBUG)
    // Check for SDK Layer support.
    inline bool SdkLayersAvailable()
    {
        HRESULT hr = D3D11CreateDevice(
            nullptr,
            D3D_DRIVER_TYPE_NULL,       // There is no need to create a real hardware device.
            0,
            D3D11_CREATE_DEVICE_DEBUG,  // Check for the SDK layers.
            nullptr,                    // Any feature level will do.
            0,
            D3D11_SDK_VERSION,          // Always set this to D3D11_SDK_VERSION for Windows Store apps.
            nullptr,                    // No need to keep the D3D device reference.
            nullptr,                    // No need to know the feature level.
            nullptr                     // No need to keep the D3D device context reference.
            );

        return SUCCEEDED(hr);
    }
#endif
}
