﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Storage.1.h"
#include "winrt/impl/Windows.Storage.Streams.1.h"
#include "winrt/impl/Windows.Storage.Provider.1.h"

WINRT_EXPORT namespace winrt::Windows::Storage::Provider {

}

namespace winrt::impl {

}

WINRT_EXPORT namespace winrt::Windows::Storage::Provider {

struct CachedFileUpdater
{
    CachedFileUpdater() = delete;
    static void SetUpdateInformation(Windows::Storage::IStorageFile const& file, param::hstring const& contentId, Windows::Storage::Provider::ReadActivationMode const& readMode, Windows::Storage::Provider::WriteActivationMode const& writeMode, Windows::Storage::Provider::CachedFileOptions const& options);
};

struct WINRT_EBO CachedFileUpdaterUI :
    Windows::Storage::Provider::ICachedFileUpdaterUI,
    impl::require<CachedFileUpdaterUI, Windows::Storage::Provider::ICachedFileUpdaterUI2>
{
    CachedFileUpdaterUI(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileUpdateRequest :
    Windows::Storage::Provider::IFileUpdateRequest,
    impl::require<FileUpdateRequest, Windows::Storage::Provider::IFileUpdateRequest2>
{
    FileUpdateRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileUpdateRequestDeferral :
    Windows::Storage::Provider::IFileUpdateRequestDeferral
{
    FileUpdateRequestDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileUpdateRequestedEventArgs :
    Windows::Storage::Provider::IFileUpdateRequestedEventArgs
{
    FileUpdateRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct StorageProviderItemProperties
{
    StorageProviderItemProperties() = delete;
    static Windows::Foundation::IAsyncAction SetAsync(Windows::Storage::IStorageItem const& item, param::async_iterable<Windows::Storage::Provider::StorageProviderItemProperty> const& itemProperties);
};

struct WINRT_EBO StorageProviderItemProperty :
    Windows::Storage::Provider::IStorageProviderItemProperty
{
    StorageProviderItemProperty(std::nullptr_t) noexcept {}
    StorageProviderItemProperty();
};

struct WINRT_EBO StorageProviderItemPropertyDefinition :
    Windows::Storage::Provider::IStorageProviderItemPropertyDefinition
{
    StorageProviderItemPropertyDefinition(std::nullptr_t) noexcept {}
    StorageProviderItemPropertyDefinition();
};

struct WINRT_EBO StorageProviderSyncRootInfo :
    Windows::Storage::Provider::IStorageProviderSyncRootInfo
{
    StorageProviderSyncRootInfo(std::nullptr_t) noexcept {}
    StorageProviderSyncRootInfo();
};

struct StorageProviderSyncRootManager
{
    StorageProviderSyncRootManager() = delete;
    static void Register(Windows::Storage::Provider::StorageProviderSyncRootInfo const& syncRootInformation);
    static void Unregister(param::hstring const& id);
    static Windows::Storage::Provider::StorageProviderSyncRootInfo GetSyncRootInformationForFolder(Windows::Storage::IStorageFolder const& folder);
    static Windows::Storage::Provider::StorageProviderSyncRootInfo GetSyncRootInformationForId(param::hstring const& id);
    static Windows::Foundation::Collections::IVectorView<Windows::Storage::Provider::StorageProviderSyncRootInfo> GetCurrentSyncRoots();
};

}
