﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.System.Power.Diagnostics.1.h"

WINRT_EXPORT namespace winrt::Windows::System::Power::Diagnostics {

}

namespace winrt::impl {

}

WINRT_EXPORT namespace winrt::Windows::System::Power::Diagnostics {

struct BackgroundEnergyDiagnostics
{
    BackgroundEnergyDiagnostics() = delete;
    static double DeviceSpecificConversionFactor();
    static uint64_t ComputeTotalEnergyUsage();
    static void ResetTotalEnergyUsage();
};

struct ForegroundEnergyDiagnostics
{
    ForegroundEnergyDiagnostics() = delete;
    static double DeviceSpecificConversionFactor();
    static uint64_t ComputeTotalEnergyUsage();
    static void ResetTotalEnergyUsage();
};

}
