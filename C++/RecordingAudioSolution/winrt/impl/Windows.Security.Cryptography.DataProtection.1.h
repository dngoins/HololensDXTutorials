﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.Storage.Streams.0.h"
#include "winrt/impl/Windows.Security.Cryptography.DataProtection.0.h"

WINRT_EXPORT namespace winrt::Windows::Security::Cryptography::DataProtection {

struct WINRT_EBO IDataProtectionProvider :
    Windows::Foundation::IInspectable,
    impl::consume_t<IDataProtectionProvider>
{
    IDataProtectionProvider(std::nullptr_t = nullptr) noexcept {}
};

struct WINRT_EBO IDataProtectionProviderFactory :
    Windows::Foundation::IInspectable,
    impl::consume_t<IDataProtectionProviderFactory>
{
    IDataProtectionProviderFactory(std::nullptr_t = nullptr) noexcept {}
};

}
