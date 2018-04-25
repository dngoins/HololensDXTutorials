﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/base.h"

WINRT_WARNING_PUSH
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Foundation.Collections.h"
#include "winrt/impl/Windows.Perception.2.h"

namespace winrt::impl {

template <typename D> Windows::Foundation::DateTime consume_Windows_Perception_IPerceptionTimestamp<D>::TargetTime() const noexcept
{
    Windows::Foundation::DateTime value{};
    check_terminate(WINRT_SHIM(Windows::Perception::IPerceptionTimestamp)->get_TargetTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan consume_Windows_Perception_IPerceptionTimestamp<D>::PredictionAmount() const noexcept
{
    Windows::Foundation::TimeSpan value{};
    check_terminate(WINRT_SHIM(Windows::Perception::IPerceptionTimestamp)->get_PredictionAmount(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::PerceptionTimestamp consume_Windows_Perception_IPerceptionTimestampHelperStatics<D>::FromHistoricalTargetTime(Windows::Foundation::DateTime const& targetTime) const
{
    Windows::Perception::PerceptionTimestamp value{ nullptr };
    check_hresult(WINRT_SHIM(Windows::Perception::IPerceptionTimestampHelperStatics)->FromHistoricalTargetTime(get_abi(targetTime), put_abi(value)));
    return value;
}

template <typename D>
struct produce<D, Windows::Perception::IPerceptionTimestamp> : produce_base<D, Windows::Perception::IPerceptionTimestamp>
{
    HRESULT __stdcall get_TargetTime(Windows::Foundation::DateTime* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().TargetTime());
        return S_OK;
    }

    HRESULT __stdcall get_PredictionAmount(Windows::Foundation::TimeSpan* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().PredictionAmount());
        return S_OK;
    }
};

template <typename D>
struct produce<D, Windows::Perception::IPerceptionTimestampHelperStatics> : produce_base<D, Windows::Perception::IPerceptionTimestampHelperStatics>
{
    HRESULT __stdcall FromHistoricalTargetTime(Windows::Foundation::DateTime targetTime, ::IUnknown** value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHistoricalTargetTime(*reinterpret_cast<Windows::Foundation::DateTime const*>(&targetTime)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

WINRT_EXPORT namespace winrt::Windows::Perception {

inline Windows::Perception::PerceptionTimestamp PerceptionTimestampHelper::FromHistoricalTargetTime(Windows::Foundation::DateTime const& targetTime)
{
    return get_activation_factory<PerceptionTimestampHelper, Windows::Perception::IPerceptionTimestampHelperStatics>().FromHistoricalTargetTime(targetTime);
}

}

WINRT_EXPORT namespace std {

template<> struct hash<winrt::Windows::Perception::IPerceptionTimestamp> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Perception::IPerceptionTimestamp> {};

template<> struct hash<winrt::Windows::Perception::IPerceptionTimestampHelperStatics> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Perception::IPerceptionTimestampHelperStatics> {};

template<> struct hash<winrt::Windows::Perception::PerceptionTimestamp> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Perception::PerceptionTimestamp> {};

template<> struct hash<winrt::Windows::Perception::PerceptionTimestampHelper> : 
    winrt::impl::impl_hash_unknown<winrt::Windows::Perception::PerceptionTimestampHelper> {};

}

WINRT_WARNING_POP
