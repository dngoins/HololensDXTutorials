﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.UI.Composition.0.h"
#include "winrt/impl/Windows.UI.Core.0.h"
#include "winrt/impl/Windows.UI.Input.Inking.0.h"
#include "winrt/impl/Windows.UI.Input.Inking.Core.0.h"

WINRT_EXPORT namespace winrt::Windows::UI::Input::Inking::Core {

struct WINRT_EBO ICoreIncrementalInkStroke :
    Windows::Foundation::IInspectable,
    impl::consume_t<ICoreIncrementalInkStroke>
{
    ICoreIncrementalInkStroke(std::nullptr_t = nullptr) noexcept {}
};

struct WINRT_EBO ICoreIncrementalInkStrokeFactory :
    Windows::Foundation::IInspectable,
    impl::consume_t<ICoreIncrementalInkStrokeFactory>
{
    ICoreIncrementalInkStrokeFactory(std::nullptr_t = nullptr) noexcept {}
};

struct WINRT_EBO ICoreInkIndependentInputSource :
    Windows::Foundation::IInspectable,
    impl::consume_t<ICoreInkIndependentInputSource>
{
    ICoreInkIndependentInputSource(std::nullptr_t = nullptr) noexcept {}
};

struct WINRT_EBO ICoreInkIndependentInputSourceStatics :
    Windows::Foundation::IInspectable,
    impl::consume_t<ICoreInkIndependentInputSourceStatics>
{
    ICoreInkIndependentInputSourceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct WINRT_EBO ICoreInkPresenterHost :
    Windows::Foundation::IInspectable,
    impl::consume_t<ICoreInkPresenterHost>
{
    ICoreInkPresenterHost(std::nullptr_t = nullptr) noexcept {}
};

struct WINRT_EBO ICoreWetStrokeUpdateEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume_t<ICoreWetStrokeUpdateEventArgs>
{
    ICoreWetStrokeUpdateEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct WINRT_EBO ICoreWetStrokeUpdateSource :
    Windows::Foundation::IInspectable,
    impl::consume_t<ICoreWetStrokeUpdateSource>
{
    ICoreWetStrokeUpdateSource(std::nullptr_t = nullptr) noexcept {}
};

struct WINRT_EBO ICoreWetStrokeUpdateSourceStatics :
    Windows::Foundation::IInspectable,
    impl::consume_t<ICoreWetStrokeUpdateSourceStatics>
{
    ICoreWetStrokeUpdateSourceStatics(std::nullptr_t = nullptr) noexcept {}
};

}
