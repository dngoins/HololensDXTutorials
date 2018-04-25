﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.UI.Input.Inking.1.h"
#include "winrt/impl/Windows.UI.Input.Inking.Analysis.1.h"

WINRT_EXPORT namespace winrt::Windows::UI::Input::Inking::Analysis {

}

namespace winrt::impl {

}

WINRT_EXPORT namespace winrt::Windows::UI::Input::Inking::Analysis {

struct WINRT_EBO InkAnalysisInkBullet :
    Windows::UI::Input::Inking::Analysis::IInkAnalysisInkBullet
{
    InkAnalysisInkBullet(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkAnalysisInkDrawing :
    Windows::UI::Input::Inking::Analysis::IInkAnalysisInkDrawing
{
    InkAnalysisInkDrawing(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkAnalysisInkWord :
    Windows::UI::Input::Inking::Analysis::IInkAnalysisInkWord
{
    InkAnalysisInkWord(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkAnalysisLine :
    Windows::UI::Input::Inking::Analysis::IInkAnalysisLine
{
    InkAnalysisLine(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkAnalysisListItem :
    Windows::UI::Input::Inking::Analysis::IInkAnalysisListItem
{
    InkAnalysisListItem(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkAnalysisNode :
    Windows::UI::Input::Inking::Analysis::IInkAnalysisNode
{
    InkAnalysisNode(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkAnalysisParagraph :
    Windows::UI::Input::Inking::Analysis::IInkAnalysisParagraph
{
    InkAnalysisParagraph(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkAnalysisResult :
    Windows::UI::Input::Inking::Analysis::IInkAnalysisResult
{
    InkAnalysisResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkAnalysisRoot :
    Windows::UI::Input::Inking::Analysis::IInkAnalysisRoot
{
    InkAnalysisRoot(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkAnalysisWritingRegion :
    Windows::UI::Input::Inking::Analysis::IInkAnalysisWritingRegion
{
    InkAnalysisWritingRegion(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkAnalyzer :
    Windows::UI::Input::Inking::Analysis::IInkAnalyzer
{
    InkAnalyzer(std::nullptr_t) noexcept {}
    InkAnalyzer();
};

}
