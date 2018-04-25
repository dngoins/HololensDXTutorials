﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.UI.Core.AnimationMetrics.1.h"

WINRT_EXPORT namespace winrt::Windows::UI::Core::AnimationMetrics {

}

namespace winrt::impl {

}

WINRT_EXPORT namespace winrt::Windows::UI::Core::AnimationMetrics {

struct WINRT_EBO AnimationDescription :
    Windows::UI::Core::AnimationMetrics::IAnimationDescription
{
    AnimationDescription(std::nullptr_t) noexcept {}
    AnimationDescription(Windows::UI::Core::AnimationMetrics::AnimationEffect const& effect, Windows::UI::Core::AnimationMetrics::AnimationEffectTarget const& target);
};

struct WINRT_EBO OpacityAnimation :
    Windows::UI::Core::AnimationMetrics::IOpacityAnimation
{
    OpacityAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PropertyAnimation :
    Windows::UI::Core::AnimationMetrics::IPropertyAnimation
{
    PropertyAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ScaleAnimation :
    Windows::UI::Core::AnimationMetrics::IScaleAnimation
{
    ScaleAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TranslationAnimation :
    Windows::UI::Core::AnimationMetrics::IPropertyAnimation
{
    TranslationAnimation(std::nullptr_t) noexcept {}
};

}
