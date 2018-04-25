﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Networking.1.h"
#include "winrt/impl/Windows.Storage.Streams.1.h"
#include "winrt/impl/Windows.Networking.Connectivity.1.h"

WINRT_EXPORT namespace winrt::Windows::Networking::Connectivity {

struct NetworkStatusChangedEventHandler : Windows::Foundation::IUnknown
{
    NetworkStatusChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> NetworkStatusChangedEventHandler(L lambda);
    template <typename F> NetworkStatusChangedEventHandler(F* function);
    template <typename O, typename M> NetworkStatusChangedEventHandler(O* object, M method);
    void operator()(Windows::Foundation::IInspectable const& sender) const;
};

struct NetworkUsageStates
{
    Windows::Networking::Connectivity::TriStates Roaming;
    Windows::Networking::Connectivity::TriStates Shared;
};

}

namespace winrt::impl {

template <> struct is_struct<Windows::Networking::Connectivity::NetworkUsageStates>
{
    static constexpr bool value{ true };
};

}

WINRT_EXPORT namespace winrt::Windows::Networking::Connectivity {

struct WINRT_EBO AttributedNetworkUsage :
    Windows::Networking::Connectivity::IAttributedNetworkUsage
{
    AttributedNetworkUsage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CellularApnContext :
    Windows::Networking::Connectivity::ICellularApnContext
{
    CellularApnContext(std::nullptr_t) noexcept {}
    CellularApnContext();
};

struct WINRT_EBO ConnectionCost :
    Windows::Networking::Connectivity::IConnectionCost,
    impl::require<ConnectionCost, Windows::Networking::Connectivity::IConnectionCost2>
{
    ConnectionCost(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ConnectionProfile :
    Windows::Networking::Connectivity::IConnectionProfile,
    impl::require<ConnectionProfile, Windows::Networking::Connectivity::IConnectionProfile2, Windows::Networking::Connectivity::IConnectionProfile3, Windows::Networking::Connectivity::IConnectionProfile4>
{
    ConnectionProfile(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ConnectionProfileFilter :
    Windows::Networking::Connectivity::IConnectionProfileFilter,
    impl::require<ConnectionProfileFilter, Windows::Networking::Connectivity::IConnectionProfileFilter2>
{
    ConnectionProfileFilter(std::nullptr_t) noexcept {}
    ConnectionProfileFilter();
};

struct WINRT_EBO ConnectionSession :
    Windows::Networking::Connectivity::IConnectionSession
{
    ConnectionSession(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ConnectivityInterval :
    Windows::Networking::Connectivity::IConnectivityInterval
{
    ConnectivityInterval(std::nullptr_t) noexcept {}
};

struct ConnectivityManager
{
    ConnectivityManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Networking::Connectivity::ConnectionSession> AcquireConnectionAsync(Windows::Networking::Connectivity::CellularApnContext const& cellularApnContext);
    static void AddHttpRoutePolicy(Windows::Networking::Connectivity::RoutePolicy const& routePolicy);
    static void RemoveHttpRoutePolicy(Windows::Networking::Connectivity::RoutePolicy const& routePolicy);
};

struct WINRT_EBO DataPlanStatus :
    Windows::Networking::Connectivity::IDataPlanStatus
{
    DataPlanStatus(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataPlanUsage :
    Windows::Networking::Connectivity::IDataPlanUsage
{
    DataPlanUsage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO [[deprecated("DataUsage may be altered or unavailable for releases after Windows 8.1. Instead, use NetworkUsage.")]] DataUsage :
    Windows::Networking::Connectivity::IDataUsage
{
    DataUsage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO IPInformation :
    Windows::Networking::Connectivity::IIPInformation
{
    IPInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LanIdentifier :
    Windows::Networking::Connectivity::ILanIdentifier
{
    LanIdentifier(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LanIdentifierData :
    Windows::Networking::Connectivity::ILanIdentifierData
{
    LanIdentifierData(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkAdapter :
    Windows::Networking::Connectivity::INetworkAdapter
{
    NetworkAdapter(std::nullptr_t) noexcept {}
};

struct NetworkInformation
{
    NetworkInformation() = delete;
    static Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile> GetConnectionProfiles();
    static Windows::Networking::Connectivity::ConnectionProfile GetInternetConnectionProfile();
    static Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::LanIdentifier> GetLanIdentifiers();
    static Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> GetHostNames();
    static Windows::Foundation::IAsyncOperation<Windows::Networking::Connectivity::ProxyConfiguration> GetProxyConfigurationAsync(Windows::Foundation::Uri const& uri);
    static Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> GetSortedEndpointPairs(param::iterable<Windows::Networking::EndpointPair> const& destinationList, Windows::Networking::HostNameSortOptions const& sortOptions);
    static event_token NetworkStatusChanged(Windows::Networking::Connectivity::NetworkStatusChangedEventHandler const& networkStatusHandler);
    using NetworkStatusChanged_revoker = factory_event_revoker<Windows::Networking::Connectivity::INetworkInformationStatics>;
    static NetworkStatusChanged_revoker NetworkStatusChanged(auto_revoke_t, Windows::Networking::Connectivity::NetworkStatusChangedEventHandler const& networkStatusHandler);
    static void NetworkStatusChanged(event_token const& eventCookie);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile>> FindConnectionProfilesAsync(Windows::Networking::Connectivity::ConnectionProfileFilter const& pProfileFilter);
};

struct WINRT_EBO NetworkItem :
    Windows::Networking::Connectivity::INetworkItem
{
    NetworkItem(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkSecuritySettings :
    Windows::Networking::Connectivity::INetworkSecuritySettings
{
    NetworkSecuritySettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkStateChangeEventDetails :
    Windows::Networking::Connectivity::INetworkStateChangeEventDetails,
    impl::require<NetworkStateChangeEventDetails, Windows::Networking::Connectivity::INetworkStateChangeEventDetails2>
{
    NetworkStateChangeEventDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkUsage :
    Windows::Networking::Connectivity::INetworkUsage
{
    NetworkUsage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProviderNetworkUsage :
    Windows::Networking::Connectivity::IProviderNetworkUsage
{
    ProviderNetworkUsage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProxyConfiguration :
    Windows::Networking::Connectivity::IProxyConfiguration
{
    ProxyConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RoutePolicy :
    Windows::Networking::Connectivity::IRoutePolicy
{
    RoutePolicy(std::nullptr_t) noexcept {}
    RoutePolicy(Windows::Networking::Connectivity::ConnectionProfile const& connectionProfile, Windows::Networking::HostName const& hostName, Windows::Networking::DomainNameType const& type);
};

struct WINRT_EBO WlanConnectionProfileDetails :
    Windows::Networking::Connectivity::IWlanConnectionProfileDetails
{
    WlanConnectionProfileDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WwanConnectionProfileDetails :
    Windows::Networking::Connectivity::IWwanConnectionProfileDetails
{
    WwanConnectionProfileDetails(std::nullptr_t) noexcept {}
};

}
