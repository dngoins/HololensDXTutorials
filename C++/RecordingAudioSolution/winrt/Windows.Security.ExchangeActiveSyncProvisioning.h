﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/base.h"

WINRT_WARNING_PUSH
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Foundation.Collections.h"
#include "winrt/impl/Windows.Security.ExchangeActiveSyncProvisioning.2.h"

namespace winrt::impl {

template <typename D> GUID consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation<D>::Id() const noexcept
{
    GUID value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation<D>::OperatingSystem() const noexcept
{
    hstring value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation)->get_OperatingSystem(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation<D>::FriendlyName() const noexcept
{
    hstring value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation<D>::SystemManufacturer() const noexcept
{
    hstring value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation)->get_SystemManufacturer(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation<D>::SystemProductName() const noexcept
{
    hstring value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation)->get_SystemProductName(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation<D>::SystemSku() const noexcept
{
    hstring value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation)->get_SystemSku(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation2<D>::SystemHardwareVersion() const noexcept
{
    hstring value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2)->get_SystemHardwareVersion(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation2<D>::SystemFirmwareVersion() const noexcept
{
    hstring value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2)->get_SystemFirmwareVersion(put_abi(value)));
    return value;
}

template <typename D> bool consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::RequireEncryption() const noexcept
{
    bool value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->get_RequireEncryption(&value));
    return value;
}

template <typename D> void consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::RequireEncryption(bool value) const noexcept
{
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->put_RequireEncryption(value));
}

template <typename D> uint8_t consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::MinPasswordLength() const noexcept
{
    uint8_t value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->get_MinPasswordLength(&value));
    return value;
}

template <typename D> void consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::MinPasswordLength(uint8_t value) const noexcept
{
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->put_MinPasswordLength(value));
}

template <typename D> bool consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::DisallowConvenienceLogon() const noexcept
{
    bool value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->get_DisallowConvenienceLogon(&value));
    return value;
}

template <typename D> void consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::DisallowConvenienceLogon(bool value) const noexcept
{
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->put_DisallowConvenienceLogon(value));
}

template <typename D> uint8_t consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::MinPasswordComplexCharacters() const noexcept
{
    uint8_t value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->get_MinPasswordComplexCharacters(&value));
    return value;
}

template <typename D> void consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::MinPasswordComplexCharacters(uint8_t value) const noexcept
{
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->put_MinPasswordComplexCharacters(value));
}

template <typename D> Windows::Foundation::TimeSpan consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::PasswordExpiration() const noexcept
{
    Windows::Foundation::TimeSpan value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->get_PasswordExpiration(put_abi(value)));
    return value;
}

template <typename D> void consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::PasswordExpiration(Windows::Foundation::TimeSpan const& value) const noexcept
{
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->put_PasswordExpiration(get_abi(value)));
}

template <typename D> uint32_t consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::PasswordHistory() const noexcept
{
    uint32_t value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->get_PasswordHistory(&value));
    return value;
}

template <typename D> void consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::PasswordHistory(uint32_t value) const noexcept
{
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->put_PasswordHistory(value));
}

template <typename D> uint8_t consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::MaxPasswordFailedAttempts() const noexcept
{
    uint8_t value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->get_MaxPasswordFailedAttempts(&value));
    return value;
}

template <typename D> void consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::MaxPasswordFailedAttempts(uint8_t value) const noexcept
{
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->put_MaxPasswordFailedAttempts(value));
}

template <typename D> Windows::Foundation::TimeSpan consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::MaxInactivityTimeLock() const noexcept
{
    Windows::Foundation::TimeSpan value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->get_MaxInactivityTimeLock(put_abi(value)));
    return value;
}

template <typename D> void consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::MaxInactivityTimeLock(Windows::Foundation::TimeSpan const& value) const noexcept
{
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->put_MaxInactivityTimeLock(get_abi(value)));
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::CheckCompliance() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults result{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->CheckCompliance(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>::ApplyAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> operation{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy)->ApplyAsync(put_abi(operation)));
    return operation;
}

template <typename D> bool consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults<D>::Compliant() const noexcept
{
    bool value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults)->get_Compliant(&value));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults<D>::RequireEncryptionResult() const noexcept
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults)->get_RequireEncryptionResult(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults<D>::MinPasswordLengthResult() const noexcept
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults)->get_MinPasswordLengthResult(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults<D>::DisallowConvenienceLogonResult() const noexcept
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults)->get_DisallowConvenienceLogonResult(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults<D>::MinPasswordComplexCharactersResult() const noexcept
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults)->get_MinPasswordComplexCharactersResult(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults<D>::PasswordExpirationResult() const noexcept
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults)->get_PasswordExpirationResult(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults<D>::PasswordHistoryResult() const noexcept
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults)->get_PasswordHistoryResult(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults<D>::MaxPasswordFailedAttemptsResult() const noexcept
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults)->get_MaxPasswordFailedAttemptsResult(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults<D>::MaxInactivityTimeLockResult() const noexcept
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults)->get_MaxInactivityTimeLockResult(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults2<D>::EncryptionProviderType() const noexcept
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType value{};
    check_terminate(WINRT_SHIM(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2)->get_EncryptionProviderType(put_abi(value)));
    return value;
}

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
{
    HRESULT __stdcall get_Id(GUID* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().Id());
        return S_OK;
    }

    HRESULT __stdcall get_OperatingSystem(HSTRING* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().OperatingSystem());
        return S_OK;
    }

    HRESULT __stdcall get_FriendlyName(HSTRING* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().FriendlyName());
        return S_OK;
    }

    HRESULT __stdcall get_SystemManufacturer(HSTRING* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().SystemManufacturer());
        return S_OK;
    }

    HRESULT __stdcall get_SystemProductName(HSTRING* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().SystemProductName());
        return S_OK;
    }

    HRESULT __stdcall get_SystemSku(HSTRING* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().SystemSku());
        return S_OK;
    }
};

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>
{
    HRESULT __stdcall get_SystemHardwareVersion(HSTRING* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().SystemHardwareVersion());
        return S_OK;
    }

    HRESULT __stdcall get_SystemFirmwareVersion(HSTRING* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().SystemFirmwareVersion());
        return S_OK;
    }
};

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>
{
    HRESULT __stdcall get_RequireEncryption(bool* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().RequireEncryption());
        return S_OK;
    }

    HRESULT __stdcall put_RequireEncryption(bool value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        this->shim().RequireEncryption(value);
        return S_OK;
    }

    HRESULT __stdcall get_MinPasswordLength(uint8_t* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().MinPasswordLength());
        return S_OK;
    }

    HRESULT __stdcall put_MinPasswordLength(uint8_t value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        this->shim().MinPasswordLength(value);
        return S_OK;
    }

    HRESULT __stdcall get_DisallowConvenienceLogon(bool* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().DisallowConvenienceLogon());
        return S_OK;
    }

    HRESULT __stdcall put_DisallowConvenienceLogon(bool value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        this->shim().DisallowConvenienceLogon(value);
        return S_OK;
    }

    HRESULT __stdcall get_MinPasswordComplexCharacters(uint8_t* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().MinPasswordComplexCharacters());
        return S_OK;
    }

    HRESULT __stdcall put_MinPasswordComplexCharacters(uint8_t value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        this->shim().MinPasswordComplexCharacters(value);
        return S_OK;
    }

    HRESULT __stdcall get_PasswordExpiration(Windows::Foundation::TimeSpan* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().PasswordExpiration());
        return S_OK;
    }

    HRESULT __stdcall put_PasswordExpiration(Windows::Foundation::TimeSpan value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        this->shim().PasswordExpiration(*reinterpret_cast<Windows::Foundation::TimeSpan const*>(&value));
        return S_OK;
    }

    HRESULT __stdcall get_PasswordHistory(uint32_t* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().PasswordHistory());
        return S_OK;
    }

    HRESULT __stdcall put_PasswordHistory(uint32_t value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        this->shim().PasswordHistory(value);
        return S_OK;
    }

    HRESULT __stdcall get_MaxPasswordFailedAttempts(uint8_t* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().MaxPasswordFailedAttempts());
        return S_OK;
    }

    HRESULT __stdcall put_MaxPasswordFailedAttempts(uint8_t value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        this->shim().MaxPasswordFailedAttempts(value);
        return S_OK;
    }

    HRESULT __stdcall get_MaxInactivityTimeLock(Windows::Foundation::TimeSpan* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().MaxInactivityTimeLock());
        return S_OK;
    }

    HRESULT __stdcall put_MaxInactivityTimeLock(Windows::Foundation::TimeSpan value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        this->shim().MaxInactivityTimeLock(*reinterpret_cast<Windows::Foundation::TimeSpan const*>(&value));
        return S_OK;
    }

    HRESULT __stdcall CheckCompliance(::IUnknown** result) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CheckCompliance());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall ApplyAsync(::IUnknown** operation) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ApplyAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>
{
    HRESULT __stdcall get_Compliant(bool* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().Compliant());
        return S_OK;
    }

    HRESULT __stdcall get_RequireEncryptionResult(Windows::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().RequireEncryptionResult());
        return S_OK;
    }

    HRESULT __stdcall get_MinPasswordLengthResult(Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().MinPasswordLengthResult());
        return S_OK;
    }

    HRESULT __stdcall get_DisallowConvenienceLogonResult(Windows::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().DisallowConvenienceLogonResult());
        return S_OK;
    }

    HRESULT __stdcall get_MinPasswordComplexCharactersResult(Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().MinPasswordComplexCharactersResult());
        return S_OK;
    }

    HRESULT __stdcall get_PasswordExpirationResult(Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().PasswordExpirationResult());
        return S_OK;
    }

    HRESULT __stdcall get_PasswordHistoryResult(Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().PasswordHistoryResult());
        return S_OK;
    }

    HRESULT __stdcall get_MaxPasswordFailedAttemptsResult(Windows::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().MaxPasswordFailedAttemptsResult());
        return S_OK;
    }

    HRESULT __stdcall get_MaxInactivityTimeLockResult(Windows::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().MaxInactivityTimeLockResult());
        return S_OK;
    }
};

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2>
{
    HRESULT __stdcall get_EncryptionProviderType(Windows::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().EncryptionProviderType());
        return S_OK;
    }
};

}

WINRT_EXPORT namespace winrt::Windows::Security::ExchangeActiveSyncProvisioning {

inline EasClientDeviceInformation::EasClientDeviceInformation() :
    EasClientDeviceInformation(activate_instance<EasClientDeviceInformation>())
{}

inline EasClientSecurityPolicy::EasClientSecurityPolicy() :
    EasClientSecurityPolicy(activate_instance<EasClientSecurityPolicy>())
{}

}

WINRT_EXPORT namespace std {

template<> struct hash<winrt::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> {};

template<> struct hash<winrt::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2> {};

template<> struct hash<winrt::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy> {};

template<> struct hash<winrt::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> {};

template<> struct hash<winrt::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2> {};

template<> struct hash<winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation> {};

template<> struct hash<winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasClientSecurityPolicy> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasClientSecurityPolicy> {};

template<> struct hash<winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> {};

}

WINRT_WARNING_POP
