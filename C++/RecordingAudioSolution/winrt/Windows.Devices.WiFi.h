﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/base.h"

WINRT_WARNING_PUSH
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Foundation.Collections.h"
#include "winrt/impl/Windows.Networking.Connectivity.2.h"
#include "winrt/impl/Windows.Security.Credentials.2.h"
#include "winrt/impl/Windows.Devices.WiFi.2.h"
#include "winrt/Windows.Devices.h"

namespace winrt::impl {

template <typename D> Windows::Networking::Connectivity::NetworkAdapter consume_Windows_Devices_WiFi_IWiFiAdapter<D>::NetworkAdapter() const noexcept
{
    Windows::Networking::Connectivity::NetworkAdapter value{ nullptr };
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter)->get_NetworkAdapter(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction consume_Windows_Devices_WiFi_IWiFiAdapter<D>::ScanAsync() const
{
    Windows::Foundation::IAsyncAction value{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter)->ScanAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::WiFi::WiFiNetworkReport consume_Windows_Devices_WiFi_IWiFiAdapter<D>::NetworkReport() const noexcept
{
    Windows::Devices::WiFi::WiFiNetworkReport value{ nullptr };
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter)->get_NetworkReport(put_abi(value)));
    return value;
}

template <typename D> event_token consume_Windows_Devices_WiFi_IWiFiAdapter<D>::AvailableNetworksChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFi::WiFiAdapter, Windows::Foundation::IInspectable> const& args) const
{
    event_token eventCookie{};
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter)->add_AvailableNetworksChanged(get_abi(args), put_abi(eventCookie)));
    return eventCookie;
}

template <typename D> event_revoker<Windows::Devices::WiFi::IWiFiAdapter> consume_Windows_Devices_WiFi_IWiFiAdapter<D>::AvailableNetworksChanged(auto_revoke_t, Windows::Foundation::TypedEventHandler<Windows::Devices::WiFi::WiFiAdapter, Windows::Foundation::IInspectable> const& args) const
{
    return impl::make_event_revoker<D, Windows::Devices::WiFi::IWiFiAdapter>(this, &abi_t<Windows::Devices::WiFi::IWiFiAdapter>::remove_AvailableNetworksChanged, AvailableNetworksChanged(args));
}

template <typename D> void consume_Windows_Devices_WiFi_IWiFiAdapter<D>::AvailableNetworksChanged(event_token const& eventCookie) const
{
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter)->remove_AvailableNetworksChanged(get_abi(eventCookie)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> consume_Windows_Devices_WiFi_IWiFiAdapter<D>::ConnectAsync(Windows::Devices::WiFi::WiFiAvailableNetwork const& availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind const& reconnectionKind) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> value{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter)->ConnectAsync(get_abi(availableNetwork), get_abi(reconnectionKind), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> consume_Windows_Devices_WiFi_IWiFiAdapter<D>::ConnectAsync(Windows::Devices::WiFi::WiFiAvailableNetwork const& availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind const& reconnectionKind, Windows::Security::Credentials::PasswordCredential const& passwordCredential) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> value{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter)->ConnectWithPasswordCredentialAsync(get_abi(availableNetwork), get_abi(reconnectionKind), get_abi(passwordCredential), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> consume_Windows_Devices_WiFi_IWiFiAdapter<D>::ConnectAsync(Windows::Devices::WiFi::WiFiAvailableNetwork const& availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind const& reconnectionKind, Windows::Security::Credentials::PasswordCredential const& passwordCredential, param::hstring const& ssid) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> value{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter)->ConnectWithPasswordCredentialAndSsidAsync(get_abi(availableNetwork), get_abi(reconnectionKind), get_abi(passwordCredential), get_abi(ssid), put_abi(value)));
    return value;
}

template <typename D> void consume_Windows_Devices_WiFi_IWiFiAdapter<D>::Disconnect() const
{
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter)->Disconnect());
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiWpsConfigurationResult> consume_Windows_Devices_WiFi_IWiFiAdapter2<D>::GetWpsConfigurationAsync(Windows::Devices::WiFi::WiFiAvailableNetwork const& availableNetwork) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiWpsConfigurationResult> operation{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter2)->GetWpsConfigurationAsync(get_abi(availableNetwork), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> consume_Windows_Devices_WiFi_IWiFiAdapter2<D>::ConnectAsync(Windows::Devices::WiFi::WiFiAvailableNetwork const& availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind const& reconnectionKind, Windows::Security::Credentials::PasswordCredential const& passwordCredential, param::hstring const& ssid, Windows::Devices::WiFi::WiFiConnectionMethod const& connectionMethod) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> operation{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapter2)->ConnectWithPasswordCredentialAndSsidAndConnectionMethodAsync(get_abi(availableNetwork), get_abi(reconnectionKind), get_abi(passwordCredential), get_abi(ssid), get_abi(connectionMethod), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAdapter>> consume_Windows_Devices_WiFi_IWiFiAdapterStatics<D>::FindAllAdaptersAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAdapter>> value{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapterStatics)->FindAllAdaptersAsync(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Windows_Devices_WiFi_IWiFiAdapterStatics<D>::GetDeviceSelector() const
{
    hstring deviceSelector{};
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapterStatics)->GetDeviceSelector(put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAdapter> consume_Windows_Devices_WiFi_IWiFiAdapterStatics<D>::FromIdAsync(param::hstring const& deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAdapter> asyncOp{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapterStatics)->FromIdAsync(get_abi(deviceId), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAccessStatus> consume_Windows_Devices_WiFi_IWiFiAdapterStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAccessStatus> value{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAdapterStatics)->RequestAccessAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::Uptime() const noexcept
{
    Windows::Foundation::TimeSpan value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_Uptime(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::Ssid() const noexcept
{
    hstring value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_Ssid(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::Bssid() const noexcept
{
    hstring value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_Bssid(put_abi(value)));
    return value;
}

template <typename D> int32_t consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::ChannelCenterFrequencyInKilohertz() const noexcept
{
    int32_t value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_ChannelCenterFrequencyInKilohertz(&value));
    return value;
}

template <typename D> double consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::NetworkRssiInDecibelMilliwatts() const noexcept
{
    double value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_NetworkRssiInDecibelMilliwatts(&value));
    return value;
}

template <typename D> uint8_t consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::SignalBars() const noexcept
{
    uint8_t value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_SignalBars(&value));
    return value;
}

template <typename D> Windows::Devices::WiFi::WiFiNetworkKind consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::NetworkKind() const noexcept
{
    Windows::Devices::WiFi::WiFiNetworkKind value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_NetworkKind(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::WiFi::WiFiPhyKind consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::PhyKind() const noexcept
{
    Windows::Devices::WiFi::WiFiPhyKind value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_PhyKind(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Connectivity::NetworkSecuritySettings consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::SecuritySettings() const noexcept
{
    Windows::Networking::Connectivity::NetworkSecuritySettings value{ nullptr };
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_SecuritySettings(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::BeaconInterval() const noexcept
{
    Windows::Foundation::TimeSpan value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_BeaconInterval(put_abi(value)));
    return value;
}

template <typename D> bool consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::IsWiFiDirect() const noexcept
{
    bool value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiAvailableNetwork)->get_IsWiFiDirect(&value));
    return value;
}

template <typename D> Windows::Devices::WiFi::WiFiConnectionStatus consume_Windows_Devices_WiFi_IWiFiConnectionResult<D>::ConnectionStatus() const noexcept
{
    Windows::Devices::WiFi::WiFiConnectionStatus value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiConnectionResult)->get_ConnectionStatus(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime consume_Windows_Devices_WiFi_IWiFiNetworkReport<D>::Timestamp() const noexcept
{
    Windows::Foundation::DateTime value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiNetworkReport)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAvailableNetwork> consume_Windows_Devices_WiFi_IWiFiNetworkReport<D>::AvailableNetworks() const noexcept
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAvailableNetwork> value{ nullptr };
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiNetworkReport)->get_AvailableNetworks(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::WiFi::WiFiWpsConfigurationStatus consume_Windows_Devices_WiFi_IWiFiWpsConfigurationResult<D>::Status() const noexcept
{
    Windows::Devices::WiFi::WiFiWpsConfigurationStatus value{};
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiWpsConfigurationResult)->get_Status(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiWpsKind> consume_Windows_Devices_WiFi_IWiFiWpsConfigurationResult<D>::SupportedWpsKinds() const noexcept
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiWpsKind> value{ nullptr };
    check_terminate(WINRT_SHIM(Windows::Devices::WiFi::IWiFiWpsConfigurationResult)->get_SupportedWpsKinds(put_abi(value)));
    return value;
}

template <typename D>
struct produce<D, Windows::Devices::WiFi::IWiFiAdapter> : produce_base<D, Windows::Devices::WiFi::IWiFiAdapter>
{
    HRESULT __stdcall get_NetworkAdapter(::IUnknown** value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().NetworkAdapter());
        return S_OK;
    }

    HRESULT __stdcall ScanAsync(::IUnknown** value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScanAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkReport(::IUnknown** value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().NetworkReport());
        return S_OK;
    }

    HRESULT __stdcall add_AvailableNetworksChanged(::IUnknown* args, event_token* eventCookie) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().AvailableNetworksChanged(*reinterpret_cast<Windows::Foundation::TypedEventHandler<Windows::Devices::WiFi::WiFiAdapter, Windows::Foundation::IInspectable> const*>(&args)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AvailableNetworksChanged(event_token eventCookie) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailableNetworksChanged(*reinterpret_cast<event_token const*>(&eventCookie));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall ConnectAsync(::IUnknown* availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, ::IUnknown** value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<Windows::Devices::WiFi::WiFiAvailableNetwork const*>(&availableNetwork), *reinterpret_cast<Windows::Devices::WiFi::WiFiReconnectionKind const*>(&reconnectionKind)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall ConnectWithPasswordCredentialAsync(::IUnknown* availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, ::IUnknown* passwordCredential, ::IUnknown** value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<Windows::Devices::WiFi::WiFiAvailableNetwork const*>(&availableNetwork), *reinterpret_cast<Windows::Devices::WiFi::WiFiReconnectionKind const*>(&reconnectionKind), *reinterpret_cast<Windows::Security::Credentials::PasswordCredential const*>(&passwordCredential)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall ConnectWithPasswordCredentialAndSsidAsync(::IUnknown* availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, ::IUnknown* passwordCredential, HSTRING ssid, ::IUnknown** value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<Windows::Devices::WiFi::WiFiAvailableNetwork const*>(&availableNetwork), *reinterpret_cast<Windows::Devices::WiFi::WiFiReconnectionKind const*>(&reconnectionKind), *reinterpret_cast<Windows::Security::Credentials::PasswordCredential const*>(&passwordCredential), *reinterpret_cast<hstring const*>(&ssid)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall Disconnect() noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disconnect();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFi::IWiFiAdapter2> : produce_base<D, Windows::Devices::WiFi::IWiFiAdapter2>
{
    HRESULT __stdcall GetWpsConfigurationAsync(::IUnknown* availableNetwork, ::IUnknown** operation) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetWpsConfigurationAsync(*reinterpret_cast<Windows::Devices::WiFi::WiFiAvailableNetwork const*>(&availableNetwork)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall ConnectWithPasswordCredentialAndSsidAndConnectionMethodAsync(::IUnknown* availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, ::IUnknown* passwordCredential, HSTRING ssid, Windows::Devices::WiFi::WiFiConnectionMethod connectionMethod, ::IUnknown** operation) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<Windows::Devices::WiFi::WiFiAvailableNetwork const*>(&availableNetwork), *reinterpret_cast<Windows::Devices::WiFi::WiFiReconnectionKind const*>(&reconnectionKind), *reinterpret_cast<Windows::Security::Credentials::PasswordCredential const*>(&passwordCredential), *reinterpret_cast<hstring const*>(&ssid), *reinterpret_cast<Windows::Devices::WiFi::WiFiConnectionMethod const*>(&connectionMethod)));
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
struct produce<D, Windows::Devices::WiFi::IWiFiAdapterStatics> : produce_base<D, Windows::Devices::WiFi::IWiFiAdapterStatics>
{
    HRESULT __stdcall FindAllAdaptersAsync(::IUnknown** value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindAllAdaptersAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall GetDeviceSelector(HSTRING* deviceSelector) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall FromIdAsync(HSTRING deviceId, ::IUnknown** asyncOp) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall RequestAccessAsync(::IUnknown** value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestAccessAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFi::IWiFiAvailableNetwork> : produce_base<D, Windows::Devices::WiFi::IWiFiAvailableNetwork>
{
    HRESULT __stdcall get_Uptime(Windows::Foundation::TimeSpan* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().Uptime());
        return S_OK;
    }

    HRESULT __stdcall get_Ssid(HSTRING* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().Ssid());
        return S_OK;
    }

    HRESULT __stdcall get_Bssid(HSTRING* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().Bssid());
        return S_OK;
    }

    HRESULT __stdcall get_ChannelCenterFrequencyInKilohertz(int32_t* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().ChannelCenterFrequencyInKilohertz());
        return S_OK;
    }

    HRESULT __stdcall get_NetworkRssiInDecibelMilliwatts(double* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().NetworkRssiInDecibelMilliwatts());
        return S_OK;
    }

    HRESULT __stdcall get_SignalBars(uint8_t* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().SignalBars());
        return S_OK;
    }

    HRESULT __stdcall get_NetworkKind(Windows::Devices::WiFi::WiFiNetworkKind* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().NetworkKind());
        return S_OK;
    }

    HRESULT __stdcall get_PhyKind(Windows::Devices::WiFi::WiFiPhyKind* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().PhyKind());
        return S_OK;
    }

    HRESULT __stdcall get_SecuritySettings(::IUnknown** value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().SecuritySettings());
        return S_OK;
    }

    HRESULT __stdcall get_BeaconInterval(Windows::Foundation::TimeSpan* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().BeaconInterval());
        return S_OK;
    }

    HRESULT __stdcall get_IsWiFiDirect(bool* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().IsWiFiDirect());
        return S_OK;
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFi::IWiFiConnectionResult> : produce_base<D, Windows::Devices::WiFi::IWiFiConnectionResult>
{
    HRESULT __stdcall get_ConnectionStatus(Windows::Devices::WiFi::WiFiConnectionStatus* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().ConnectionStatus());
        return S_OK;
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFi::IWiFiNetworkReport> : produce_base<D, Windows::Devices::WiFi::IWiFiNetworkReport>
{
    HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().Timestamp());
        return S_OK;
    }

    HRESULT __stdcall get_AvailableNetworks(::IUnknown** value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().AvailableNetworks());
        return S_OK;
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFi::IWiFiWpsConfigurationResult> : produce_base<D, Windows::Devices::WiFi::IWiFiWpsConfigurationResult>
{
    HRESULT __stdcall get_Status(Windows::Devices::WiFi::WiFiWpsConfigurationStatus* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().Status());
        return S_OK;
    }

    HRESULT __stdcall get_SupportedWpsKinds(::IUnknown** value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().SupportedWpsKinds());
        return S_OK;
    }
};

}

WINRT_EXPORT namespace winrt::Windows::Devices::WiFi {

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAdapter>> WiFiAdapter::FindAllAdaptersAsync()
{
    return get_activation_factory<WiFiAdapter, Windows::Devices::WiFi::IWiFiAdapterStatics>().FindAllAdaptersAsync();
}

inline hstring WiFiAdapter::GetDeviceSelector()
{
    return get_activation_factory<WiFiAdapter, Windows::Devices::WiFi::IWiFiAdapterStatics>().GetDeviceSelector();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAdapter> WiFiAdapter::FromIdAsync(param::hstring const& deviceId)
{
    return get_activation_factory<WiFiAdapter, Windows::Devices::WiFi::IWiFiAdapterStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAccessStatus> WiFiAdapter::RequestAccessAsync()
{
    return get_activation_factory<WiFiAdapter, Windows::Devices::WiFi::IWiFiAdapterStatics>().RequestAccessAsync();
}

}

WINRT_EXPORT namespace std {

template<> struct hash<winrt::Windows::Devices::WiFi::IWiFiAdapter> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::IWiFiAdapter> {};

template<> struct hash<winrt::Windows::Devices::WiFi::IWiFiAdapter2> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::IWiFiAdapter2> {};

template<> struct hash<winrt::Windows::Devices::WiFi::IWiFiAdapterStatics> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::IWiFiAdapterStatics> {};

template<> struct hash<winrt::Windows::Devices::WiFi::IWiFiAvailableNetwork> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::IWiFiAvailableNetwork> {};

template<> struct hash<winrt::Windows::Devices::WiFi::IWiFiConnectionResult> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::IWiFiConnectionResult> {};

template<> struct hash<winrt::Windows::Devices::WiFi::IWiFiNetworkReport> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::IWiFiNetworkReport> {};

template<> struct hash<winrt::Windows::Devices::WiFi::IWiFiWpsConfigurationResult> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::IWiFiWpsConfigurationResult> {};

template<> struct hash<winrt::Windows::Devices::WiFi::WiFiAdapter> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::WiFiAdapter> {};

template<> struct hash<winrt::Windows::Devices::WiFi::WiFiAvailableNetwork> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::WiFiAvailableNetwork> {};

template<> struct hash<winrt::Windows::Devices::WiFi::WiFiConnectionResult> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::WiFiConnectionResult> {};

template<> struct hash<winrt::Windows::Devices::WiFi::WiFiNetworkReport> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::WiFiNetworkReport> {};

template<> struct hash<winrt::Windows::Devices::WiFi::WiFiWpsConfigurationResult> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Devices::WiFi::WiFiWpsConfigurationResult> {};

}

WINRT_WARNING_POP
