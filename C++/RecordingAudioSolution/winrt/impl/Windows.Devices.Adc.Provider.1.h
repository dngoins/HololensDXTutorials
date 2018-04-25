﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.Devices.Adc.Provider.0.h"

WINRT_EXPORT namespace winrt::Windows::Devices::Adc::Provider {

struct WINRT_EBO IAdcControllerProvider :
    Windows::Foundation::IInspectable,
    impl::consume_t<IAdcControllerProvider>
{
    IAdcControllerProvider(std::nullptr_t = nullptr) noexcept {}
};

struct WINRT_EBO IAdcProvider :
    Windows::Foundation::IInspectable,
    impl::consume_t<IAdcProvider>
{
    IAdcProvider(std::nullptr_t = nullptr) noexcept {}
};

}
