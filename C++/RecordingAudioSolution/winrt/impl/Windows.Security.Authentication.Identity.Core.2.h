﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.Security.Authentication.Identity.Core.1.h"

WINRT_EXPORT namespace winrt::Windows::Security::Authentication::Identity::Core {

}

namespace winrt::impl {

}

WINRT_EXPORT namespace winrt::Windows::Security::Authentication::Identity::Core {

struct WINRT_EBO MicrosoftAccountMultiFactorAuthenticationManager :
    Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager
{
    MicrosoftAccountMultiFactorAuthenticationManager(std::nullptr_t) noexcept {}
    static Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager Current();
};

struct WINRT_EBO MicrosoftAccountMultiFactorGetSessionsResult :
    Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult
{
    MicrosoftAccountMultiFactorGetSessionsResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MicrosoftAccountMultiFactorOneTimeCodedInfo :
    Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo
{
    MicrosoftAccountMultiFactorOneTimeCodedInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MicrosoftAccountMultiFactorSessionInfo :
    Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo
{
    MicrosoftAccountMultiFactorSessionInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo :
    Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo
{
    MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo(std::nullptr_t) noexcept {}
};

}
