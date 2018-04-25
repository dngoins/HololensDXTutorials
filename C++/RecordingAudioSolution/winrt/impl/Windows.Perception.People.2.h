﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.Perception.People.1.h"

WINRT_EXPORT namespace winrt::Windows::Perception::People {

}

namespace winrt::impl {

}

WINRT_EXPORT namespace winrt::Windows::Perception::People {

struct WINRT_EBO HeadPose :
    Windows::Perception::People::IHeadPose
{
    HeadPose(std::nullptr_t) noexcept {}
};

}
