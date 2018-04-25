﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

WINRT_EXPORT namespace winrt::Windows::Storage::Streams {

struct IRandomAccessStream;

}

WINRT_EXPORT namespace winrt::Windows::UI {

struct Color;

}

WINRT_EXPORT namespace winrt::Windows::UI::Text {

enum class CaretType : int32_t
{
    Normal = 0,
    Null = 1,
};

enum class FindOptions : uint32_t
{
    None = 0x0,
    Word = 0x2,
    Case = 0x4,
};

enum class FontStretch : int32_t
{
    Undefined = 0,
    UltraCondensed = 1,
    ExtraCondensed = 2,
    Condensed = 3,
    SemiCondensed = 4,
    Normal = 5,
    SemiExpanded = 6,
    Expanded = 7,
    ExtraExpanded = 8,
    UltraExpanded = 9,
};

enum class FontStyle : int32_t
{
    Normal = 0,
    Oblique = 1,
    Italic = 2,
};

enum class FormatEffect : int32_t
{
    Off = 0,
    On = 1,
    Toggle = 2,
    Undefined = 3,
};

enum class HorizontalCharacterAlignment : int32_t
{
    Left = 0,
    Right = 1,
    Center = 2,
};

enum class LetterCase : int32_t
{
    Lower = 0,
    Upper = 1,
};

enum class LineSpacingRule : int32_t
{
    Undefined = 0,
    Single = 1,
    OneAndHalf = 2,
    Double = 3,
    AtLeast = 4,
    Exactly = 5,
    Multiple = 6,
    Percent = 7,
};

enum class LinkType : int32_t
{
    Undefined = 0,
    NotALink = 1,
    ClientLink = 2,
    FriendlyLinkName = 3,
    FriendlyLinkAddress = 4,
    AutoLink = 5,
    AutoLinkEmail = 6,
    AutoLinkPhone = 7,
    AutoLinkPath = 8,
};

enum class MarkerAlignment : int32_t
{
    Undefined = 0,
    Left = 1,
    Center = 2,
    Right = 3,
};

enum class MarkerStyle : int32_t
{
    Undefined = 0,
    Parenthesis = 1,
    Parentheses = 2,
    Period = 3,
    Plain = 4,
    Minus = 5,
    NoNumber = 6,
};

enum class MarkerType : int32_t
{
    Undefined = 0,
    None = 1,
    Bullet = 2,
    Arabic = 3,
    LowercaseEnglishLetter = 4,
    UppercaseEnglishLetter = 5,
    LowercaseRoman = 6,
    UppercaseRoman = 7,
    UnicodeSequence = 8,
    CircledNumber = 9,
    BlackCircleWingding = 10,
    WhiteCircleWingding = 11,
    ArabicWide = 12,
    SimplifiedChinese = 13,
    TraditionalChinese = 14,
    JapanSimplifiedChinese = 15,
    JapanKorea = 16,
    ArabicDictionary = 17,
    ArabicAbjad = 18,
    Hebrew = 19,
    ThaiAlphabetic = 20,
    ThaiNumeric = 21,
    DevanagariVowel = 22,
    DevanagariConsonant = 23,
    DevanagariNumeric = 24,
};

enum class ParagraphAlignment : int32_t
{
    Undefined = 0,
    Left = 1,
    Center = 2,
    Right = 3,
    Justify = 4,
};

enum class ParagraphStyle : int32_t
{
    Undefined = 0,
    None = 1,
    Normal = 2,
    Heading1 = 3,
    Heading2 = 4,
    Heading3 = 5,
    Heading4 = 6,
    Heading5 = 7,
    Heading6 = 8,
    Heading7 = 9,
    Heading8 = 10,
    Heading9 = 11,
};

enum class PointOptions : uint32_t
{
    None = 0x0,
    IncludeInset = 0x1,
    Start = 0x20,
    ClientCoordinates = 0x100,
    AllowOffClient = 0x200,
    Transform = 0x400,
    NoHorizontalScroll = 0x10000,
    NoVerticalScroll = 0x40000,
};

enum class RangeGravity : int32_t
{
    UIBehavior = 0,
    Backward = 1,
    Forward = 2,
    Inward = 3,
    Outward = 4,
};

enum class SelectionOptions : uint32_t
{
    StartActive = 0x1,
    AtEndOfLine = 0x2,
    Overtype = 0x4,
    Active = 0x8,
    Replace = 0x10,
};

enum class SelectionType : int32_t
{
    None = 0,
    InsertionPoint = 1,
    Normal = 2,
    InlineShape = 7,
    Shape = 8,
};

enum class TabAlignment : int32_t
{
    Left = 0,
    Center = 1,
    Right = 2,
    Decimal = 3,
    Bar = 4,
};

enum class TabLeader : int32_t
{
    Spaces = 0,
    Dots = 1,
    Dashes = 2,
    Lines = 3,
    ThickLines = 4,
    Equals = 5,
};

enum class TextDecorations : uint32_t
{
    None = 0x0,
    Underline = 0x1,
    Strikethrough = 0x2,
};

enum class TextGetOptions : uint32_t
{
    None = 0x0,
    AdjustCrlf = 0x1,
    UseCrlf = 0x2,
    UseObjectText = 0x4,
    AllowFinalEop = 0x8,
    NoHidden = 0x20,
    IncludeNumbering = 0x40,
    FormatRtf = 0x2000,
    UseLf = 0x1000000,
};

enum class TextRangeUnit : int32_t
{
    Character = 0,
    Word = 1,
    Sentence = 2,
    Paragraph = 3,
    Line = 4,
    Story = 5,
    Screen = 6,
    Section = 7,
    Window = 8,
    CharacterFormat = 9,
    ParagraphFormat = 10,
    Object = 11,
    HardParagraph = 12,
    Cluster = 13,
    Bold = 14,
    Italic = 15,
    Underline = 16,
    Strikethrough = 17,
    ProtectedText = 18,
    Link = 19,
    SmallCaps = 20,
    AllCaps = 21,
    Hidden = 22,
    Outline = 23,
    Shadow = 24,
    Imprint = 25,
    Disabled = 26,
    Revised = 27,
    Subscript = 28,
    Superscript = 29,
    FontBound = 30,
    LinkProtected = 31,
};

enum class TextScript : int32_t
{
    Undefined = 0,
    Ansi = 1,
    EastEurope = 2,
    Cyrillic = 3,
    Greek = 4,
    Turkish = 5,
    Hebrew = 6,
    Arabic = 7,
    Baltic = 8,
    Vietnamese = 9,
    Default = 10,
    Symbol = 11,
    Thai = 12,
    ShiftJis = 13,
    GB2312 = 14,
    Hangul = 15,
    Big5 = 16,
    PC437 = 17,
    Oem = 18,
    Mac = 19,
    Armenian = 20,
    Syriac = 21,
    Thaana = 22,
    Devanagari = 23,
    Bengali = 24,
    Gurmukhi = 25,
    Gujarati = 26,
    Oriya = 27,
    Tamil = 28,
    Telugu = 29,
    Kannada = 30,
    Malayalam = 31,
    Sinhala = 32,
    Lao = 33,
    Tibetan = 34,
    Myanmar = 35,
    Georgian = 36,
    Jamo = 37,
    Ethiopic = 38,
    Cherokee = 39,
    Aboriginal = 40,
    Ogham = 41,
    Runic = 42,
    Khmer = 43,
    Mongolian = 44,
    Braille = 45,
    Yi = 46,
    Limbu = 47,
    TaiLe = 48,
    NewTaiLue = 49,
    SylotiNagri = 50,
    Kharoshthi = 51,
    Kayahli = 52,
    UnicodeSymbol = 53,
    Emoji = 54,
    Glagolitic = 55,
    Lisu = 56,
    Vai = 57,
    NKo = 58,
    Osmanya = 59,
    PhagsPa = 60,
    Gothic = 61,
    Deseret = 62,
    Tifinagh = 63,
};

enum class TextSetOptions : uint32_t
{
    None = 0x0,
    UnicodeBidi = 0x1,
    Unlink = 0x8,
    Unhide = 0x10,
    CheckTextLimit = 0x20,
    FormatRtf = 0x2000,
    ApplyRtfDocumentDefaults = 0x4000,
};

enum class UnderlineType : int32_t
{
    Undefined = 0,
    None = 1,
    Single = 2,
    Words = 3,
    Double = 4,
    Dotted = 5,
    Dash = 6,
    DashDot = 7,
    DashDotDot = 8,
    Wave = 9,
    Thick = 10,
    Thin = 11,
    DoubleWave = 12,
    HeavyWave = 13,
    LongDash = 14,
    ThickDash = 15,
    ThickDashDot = 16,
    ThickDashDotDot = 17,
    ThickDotted = 18,
    ThickLongDash = 19,
};

enum class VerticalCharacterAlignment : int32_t
{
    Top = 0,
    Baseline = 1,
    Bottom = 2,
};

struct IFontWeights;
struct IFontWeightsStatics;
struct ITextCharacterFormat;
struct ITextConstantsStatics;
struct ITextDocument;
struct ITextDocument2;
struct ITextParagraphFormat;
struct ITextRange;
struct ITextSelection;
struct FontWeights;
struct RichEditTextDocument;
struct TextConstants;
struct FontWeight;

}

namespace winrt::impl {

template<> struct is_enum_flag<Windows::UI::Text::FindOptions> : std::true_type {};
template<> struct is_enum_flag<Windows::UI::Text::PointOptions> : std::true_type {};
template<> struct is_enum_flag<Windows::UI::Text::SelectionOptions> : std::true_type {};
template<> struct is_enum_flag<Windows::UI::Text::TextDecorations> : std::true_type {};
template<> struct is_enum_flag<Windows::UI::Text::TextGetOptions> : std::true_type {};
template<> struct is_enum_flag<Windows::UI::Text::TextSetOptions> : std::true_type {};
template <> struct category<Windows::UI::Text::IFontWeights>{ using type = interface_category; };
template <> struct category<Windows::UI::Text::IFontWeightsStatics>{ using type = interface_category; };
template <> struct category<Windows::UI::Text::ITextCharacterFormat>{ using type = interface_category; };
template <> struct category<Windows::UI::Text::ITextConstantsStatics>{ using type = interface_category; };
template <> struct category<Windows::UI::Text::ITextDocument>{ using type = interface_category; };
template <> struct category<Windows::UI::Text::ITextDocument2>{ using type = interface_category; };
template <> struct category<Windows::UI::Text::ITextParagraphFormat>{ using type = interface_category; };
template <> struct category<Windows::UI::Text::ITextRange>{ using type = interface_category; };
template <> struct category<Windows::UI::Text::ITextSelection>{ using type = interface_category; };
template <> struct category<Windows::UI::Text::FontWeights>{ using type = class_category; };
template <> struct category<Windows::UI::Text::RichEditTextDocument>{ using type = class_category; };
template <> struct category<Windows::UI::Text::TextConstants>{ using type = class_category; };
template <> struct category<Windows::UI::Text::CaretType>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::FindOptions>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::FontStretch>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::FontStyle>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::FormatEffect>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::HorizontalCharacterAlignment>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::LetterCase>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::LineSpacingRule>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::LinkType>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::MarkerAlignment>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::MarkerStyle>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::MarkerType>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::ParagraphAlignment>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::ParagraphStyle>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::PointOptions>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::RangeGravity>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::SelectionOptions>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::SelectionType>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::TabAlignment>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::TabLeader>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::TextDecorations>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::TextGetOptions>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::TextRangeUnit>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::TextScript>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::TextSetOptions>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::UnderlineType>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::VerticalCharacterAlignment>{ using type = enum_category; };
template <> struct category<Windows::UI::Text::FontWeight>{ using type = struct_category<uint16_t>; };
template <> struct name<Windows::UI::Text::IFontWeights>{ static constexpr auto & value{ L"Windows.UI.Text.IFontWeights" }; };
template <> struct name<Windows::UI::Text::IFontWeightsStatics>{ static constexpr auto & value{ L"Windows.UI.Text.IFontWeightsStatics" }; };
template <> struct name<Windows::UI::Text::ITextCharacterFormat>{ static constexpr auto & value{ L"Windows.UI.Text.ITextCharacterFormat" }; };
template <> struct name<Windows::UI::Text::ITextConstantsStatics>{ static constexpr auto & value{ L"Windows.UI.Text.ITextConstantsStatics" }; };
template <> struct name<Windows::UI::Text::ITextDocument>{ static constexpr auto & value{ L"Windows.UI.Text.ITextDocument" }; };
template <> struct name<Windows::UI::Text::ITextDocument2>{ static constexpr auto & value{ L"Windows.UI.Text.ITextDocument2" }; };
template <> struct name<Windows::UI::Text::ITextParagraphFormat>{ static constexpr auto & value{ L"Windows.UI.Text.ITextParagraphFormat" }; };
template <> struct name<Windows::UI::Text::ITextRange>{ static constexpr auto & value{ L"Windows.UI.Text.ITextRange" }; };
template <> struct name<Windows::UI::Text::ITextSelection>{ static constexpr auto & value{ L"Windows.UI.Text.ITextSelection" }; };
template <> struct name<Windows::UI::Text::FontWeights>{ static constexpr auto & value{ L"Windows.UI.Text.FontWeights" }; };
template <> struct name<Windows::UI::Text::RichEditTextDocument>{ static constexpr auto & value{ L"Windows.UI.Text.RichEditTextDocument" }; };
template <> struct name<Windows::UI::Text::TextConstants>{ static constexpr auto & value{ L"Windows.UI.Text.TextConstants" }; };
template <> struct name<Windows::UI::Text::CaretType>{ static constexpr auto & value{ L"Windows.UI.Text.CaretType" }; };
template <> struct name<Windows::UI::Text::FindOptions>{ static constexpr auto & value{ L"Windows.UI.Text.FindOptions" }; };
template <> struct name<Windows::UI::Text::FontStretch>{ static constexpr auto & value{ L"Windows.UI.Text.FontStretch" }; };
template <> struct name<Windows::UI::Text::FontStyle>{ static constexpr auto & value{ L"Windows.UI.Text.FontStyle" }; };
template <> struct name<Windows::UI::Text::FormatEffect>{ static constexpr auto & value{ L"Windows.UI.Text.FormatEffect" }; };
template <> struct name<Windows::UI::Text::HorizontalCharacterAlignment>{ static constexpr auto & value{ L"Windows.UI.Text.HorizontalCharacterAlignment" }; };
template <> struct name<Windows::UI::Text::LetterCase>{ static constexpr auto & value{ L"Windows.UI.Text.LetterCase" }; };
template <> struct name<Windows::UI::Text::LineSpacingRule>{ static constexpr auto & value{ L"Windows.UI.Text.LineSpacingRule" }; };
template <> struct name<Windows::UI::Text::LinkType>{ static constexpr auto & value{ L"Windows.UI.Text.LinkType" }; };
template <> struct name<Windows::UI::Text::MarkerAlignment>{ static constexpr auto & value{ L"Windows.UI.Text.MarkerAlignment" }; };
template <> struct name<Windows::UI::Text::MarkerStyle>{ static constexpr auto & value{ L"Windows.UI.Text.MarkerStyle" }; };
template <> struct name<Windows::UI::Text::MarkerType>{ static constexpr auto & value{ L"Windows.UI.Text.MarkerType" }; };
template <> struct name<Windows::UI::Text::ParagraphAlignment>{ static constexpr auto & value{ L"Windows.UI.Text.ParagraphAlignment" }; };
template <> struct name<Windows::UI::Text::ParagraphStyle>{ static constexpr auto & value{ L"Windows.UI.Text.ParagraphStyle" }; };
template <> struct name<Windows::UI::Text::PointOptions>{ static constexpr auto & value{ L"Windows.UI.Text.PointOptions" }; };
template <> struct name<Windows::UI::Text::RangeGravity>{ static constexpr auto & value{ L"Windows.UI.Text.RangeGravity" }; };
template <> struct name<Windows::UI::Text::SelectionOptions>{ static constexpr auto & value{ L"Windows.UI.Text.SelectionOptions" }; };
template <> struct name<Windows::UI::Text::SelectionType>{ static constexpr auto & value{ L"Windows.UI.Text.SelectionType" }; };
template <> struct name<Windows::UI::Text::TabAlignment>{ static constexpr auto & value{ L"Windows.UI.Text.TabAlignment" }; };
template <> struct name<Windows::UI::Text::TabLeader>{ static constexpr auto & value{ L"Windows.UI.Text.TabLeader" }; };
template <> struct name<Windows::UI::Text::TextDecorations>{ static constexpr auto & value{ L"Windows.UI.Text.TextDecorations" }; };
template <> struct name<Windows::UI::Text::TextGetOptions>{ static constexpr auto & value{ L"Windows.UI.Text.TextGetOptions" }; };
template <> struct name<Windows::UI::Text::TextRangeUnit>{ static constexpr auto & value{ L"Windows.UI.Text.TextRangeUnit" }; };
template <> struct name<Windows::UI::Text::TextScript>{ static constexpr auto & value{ L"Windows.UI.Text.TextScript" }; };
template <> struct name<Windows::UI::Text::TextSetOptions>{ static constexpr auto & value{ L"Windows.UI.Text.TextSetOptions" }; };
template <> struct name<Windows::UI::Text::UnderlineType>{ static constexpr auto & value{ L"Windows.UI.Text.UnderlineType" }; };
template <> struct name<Windows::UI::Text::VerticalCharacterAlignment>{ static constexpr auto & value{ L"Windows.UI.Text.VerticalCharacterAlignment" }; };
template <> struct name<Windows::UI::Text::FontWeight>{ static constexpr auto & value{ L"Windows.UI.Text.FontWeight" }; };
template <> struct guid<Windows::UI::Text::IFontWeights>{ static constexpr GUID value{ 0x7880A444,0x01AB,0x4997,{ 0x85,0x17,0xDF,0x82,0x2A,0x0C,0x45,0xF1 } }; };
template <> struct guid<Windows::UI::Text::IFontWeightsStatics>{ static constexpr GUID value{ 0xB3B579D5,0x1BA9,0x48EB,{ 0x9D,0xAD,0xC0,0x95,0xE8,0xC2,0x3B,0xA3 } }; };
template <> struct guid<Windows::UI::Text::ITextCharacterFormat>{ static constexpr GUID value{ 0x5ADEF3DB,0x05FB,0x442D,{ 0x80,0x65,0x64,0x2A,0xFE,0xA0,0x2C,0xED } }; };
template <> struct guid<Windows::UI::Text::ITextConstantsStatics>{ static constexpr GUID value{ 0x779E7C33,0x189D,0x4BFA,{ 0x97,0xC8,0x10,0xDB,0x13,0x5D,0x97,0x6E } }; };
template <> struct guid<Windows::UI::Text::ITextDocument>{ static constexpr GUID value{ 0xBEEE4DDB,0x90B2,0x408C,{ 0xA2,0xF6,0x0A,0x0A,0xC3,0x1E,0x33,0xE4 } }; };
template <> struct guid<Windows::UI::Text::ITextDocument2>{ static constexpr GUID value{ 0xF2311112,0x8C89,0x49C9,{ 0x91,0x18,0xF0,0x57,0xCB,0xB8,0x14,0xEE } }; };
template <> struct guid<Windows::UI::Text::ITextParagraphFormat>{ static constexpr GUID value{ 0x2CF8CFA6,0x4676,0x498A,{ 0x93,0xF5,0xBB,0xDB,0xFC,0x0B,0xD8,0x83 } }; };
template <> struct guid<Windows::UI::Text::ITextRange>{ static constexpr GUID value{ 0x5B9E4E57,0xC072,0x42A0,{ 0x89,0x45,0xAF,0x50,0x3E,0xE5,0x47,0x68 } }; };
template <> struct guid<Windows::UI::Text::ITextSelection>{ static constexpr GUID value{ 0xA6D36724,0xF28F,0x430A,{ 0xB2,0xCF,0xC3,0x43,0x67,0x1E,0xC0,0xE9 } }; };
template <> struct default_interface<Windows::UI::Text::FontWeights>{ using type = Windows::UI::Text::IFontWeights; };
template <> struct default_interface<Windows::UI::Text::RichEditTextDocument>{ using type = Windows::UI::Text::ITextDocument; };

template <typename D>
struct consume_Windows_UI_Text_IFontWeights
{
};
template <> struct consume<Windows::UI::Text::IFontWeights> { template <typename D> using type = consume_Windows_UI_Text_IFontWeights<D>; };

template <typename D>
struct consume_Windows_UI_Text_IFontWeightsStatics
{
    Windows::UI::Text::FontWeight Black() const noexcept;
    Windows::UI::Text::FontWeight Bold() const noexcept;
    Windows::UI::Text::FontWeight ExtraBlack() const noexcept;
    Windows::UI::Text::FontWeight ExtraBold() const noexcept;
    Windows::UI::Text::FontWeight ExtraLight() const noexcept;
    Windows::UI::Text::FontWeight Light() const noexcept;
    Windows::UI::Text::FontWeight Medium() const noexcept;
    Windows::UI::Text::FontWeight Normal() const noexcept;
    Windows::UI::Text::FontWeight SemiBold() const noexcept;
    Windows::UI::Text::FontWeight SemiLight() const noexcept;
    Windows::UI::Text::FontWeight Thin() const noexcept;
};
template <> struct consume<Windows::UI::Text::IFontWeightsStatics> { template <typename D> using type = consume_Windows_UI_Text_IFontWeightsStatics<D>; };

template <typename D>
struct consume_Windows_UI_Text_ITextCharacterFormat
{
    Windows::UI::Text::FormatEffect AllCaps() const noexcept;
    void AllCaps(Windows::UI::Text::FormatEffect const& value) const noexcept;
    Windows::UI::Color BackgroundColor() const noexcept;
    void BackgroundColor(Windows::UI::Color const& value) const noexcept;
    Windows::UI::Text::FormatEffect Bold() const noexcept;
    void Bold(Windows::UI::Text::FormatEffect const& value) const noexcept;
    Windows::UI::Text::FontStretch FontStretch() const noexcept;
    void FontStretch(Windows::UI::Text::FontStretch const& value) const noexcept;
    Windows::UI::Text::FontStyle FontStyle() const noexcept;
    void FontStyle(Windows::UI::Text::FontStyle const& value) const noexcept;
    Windows::UI::Color ForegroundColor() const noexcept;
    void ForegroundColor(Windows::UI::Color const& value) const noexcept;
    Windows::UI::Text::FormatEffect Hidden() const noexcept;
    void Hidden(Windows::UI::Text::FormatEffect const& value) const noexcept;
    Windows::UI::Text::FormatEffect Italic() const noexcept;
    void Italic(Windows::UI::Text::FormatEffect const& value) const noexcept;
    float Kerning() const noexcept;
    void Kerning(float value) const noexcept;
    hstring LanguageTag() const noexcept;
    void LanguageTag(param::hstring const& value) const noexcept;
    Windows::UI::Text::LinkType LinkType() const noexcept;
    hstring Name() const noexcept;
    void Name(param::hstring const& value) const noexcept;
    Windows::UI::Text::FormatEffect Outline() const noexcept;
    void Outline(Windows::UI::Text::FormatEffect const& value) const noexcept;
    float Position() const noexcept;
    void Position(float value) const noexcept;
    Windows::UI::Text::FormatEffect ProtectedText() const noexcept;
    void ProtectedText(Windows::UI::Text::FormatEffect const& value) const noexcept;
    float Size() const noexcept;
    void Size(float value) const noexcept;
    Windows::UI::Text::FormatEffect SmallCaps() const noexcept;
    void SmallCaps(Windows::UI::Text::FormatEffect const& value) const noexcept;
    float Spacing() const noexcept;
    void Spacing(float value) const noexcept;
    Windows::UI::Text::FormatEffect Strikethrough() const noexcept;
    void Strikethrough(Windows::UI::Text::FormatEffect const& value) const noexcept;
    Windows::UI::Text::FormatEffect Subscript() const noexcept;
    void Subscript(Windows::UI::Text::FormatEffect const& value) const noexcept;
    Windows::UI::Text::FormatEffect Superscript() const noexcept;
    void Superscript(Windows::UI::Text::FormatEffect const& value) const noexcept;
    Windows::UI::Text::TextScript TextScript() const noexcept;
    void TextScript(Windows::UI::Text::TextScript const& value) const noexcept;
    Windows::UI::Text::UnderlineType Underline() const noexcept;
    void Underline(Windows::UI::Text::UnderlineType const& value) const noexcept;
    int32_t Weight() const noexcept;
    void Weight(int32_t value) const noexcept;
    void SetClone(Windows::UI::Text::ITextCharacterFormat const& value) const;
    Windows::UI::Text::ITextCharacterFormat GetClone() const;
    bool IsEqual(Windows::UI::Text::ITextCharacterFormat const& format) const;
};
template <> struct consume<Windows::UI::Text::ITextCharacterFormat> { template <typename D> using type = consume_Windows_UI_Text_ITextCharacterFormat<D>; };

template <typename D>
struct consume_Windows_UI_Text_ITextConstantsStatics
{
    Windows::UI::Color AutoColor() const noexcept;
    int32_t MinUnitCount() const noexcept;
    int32_t MaxUnitCount() const noexcept;
    Windows::UI::Color UndefinedColor() const noexcept;
    float UndefinedFloatValue() const noexcept;
    int32_t UndefinedInt32Value() const noexcept;
    Windows::UI::Text::FontStretch UndefinedFontStretch() const noexcept;
    Windows::UI::Text::FontStyle UndefinedFontStyle() const noexcept;
};
template <> struct consume<Windows::UI::Text::ITextConstantsStatics> { template <typename D> using type = consume_Windows_UI_Text_ITextConstantsStatics<D>; };

template <typename D>
struct consume_Windows_UI_Text_ITextDocument
{
    Windows::UI::Text::CaretType CaretType() const noexcept;
    void CaretType(Windows::UI::Text::CaretType const& value) const noexcept;
    float DefaultTabStop() const noexcept;
    void DefaultTabStop(float value) const noexcept;
    Windows::UI::Text::ITextSelection Selection() const noexcept;
    uint32_t UndoLimit() const noexcept;
    void UndoLimit(uint32_t value) const noexcept;
    bool CanCopy() const;
    bool CanPaste() const;
    bool CanRedo() const;
    bool CanUndo() const;
    int32_t ApplyDisplayUpdates() const;
    int32_t BatchDisplayUpdates() const;
    void BeginUndoGroup() const;
    void EndUndoGroup() const;
    Windows::UI::Text::ITextCharacterFormat GetDefaultCharacterFormat() const;
    Windows::UI::Text::ITextParagraphFormat GetDefaultParagraphFormat() const;
    Windows::UI::Text::ITextRange GetRange(int32_t startPosition, int32_t endPosition) const;
    Windows::UI::Text::ITextRange GetRangeFromPoint(Windows::Foundation::Point const& point, Windows::UI::Text::PointOptions const& options) const;
    void GetText(Windows::UI::Text::TextGetOptions const& options, hstring& value) const;
    void LoadFromStream(Windows::UI::Text::TextSetOptions const& options, Windows::Storage::Streams::IRandomAccessStream const& value) const;
    void Redo() const;
    void SaveToStream(Windows::UI::Text::TextGetOptions const& options, Windows::Storage::Streams::IRandomAccessStream const& value) const;
    void SetDefaultCharacterFormat(Windows::UI::Text::ITextCharacterFormat const& value) const;
    void SetDefaultParagraphFormat(Windows::UI::Text::ITextParagraphFormat const& value) const;
    void SetText(Windows::UI::Text::TextSetOptions const& options, param::hstring const& value) const;
    void Undo() const;
};
template <> struct consume<Windows::UI::Text::ITextDocument> { template <typename D> using type = consume_Windows_UI_Text_ITextDocument<D>; };

template <typename D>
struct consume_Windows_UI_Text_ITextDocument2
{
    bool AlignmentIncludesTrailingWhitespace() const noexcept;
    void AlignmentIncludesTrailingWhitespace(bool value) const noexcept;
    bool IgnoreTrailingCharacterSpacing() const noexcept;
    void IgnoreTrailingCharacterSpacing(bool value) const noexcept;
};
template <> struct consume<Windows::UI::Text::ITextDocument2> { template <typename D> using type = consume_Windows_UI_Text_ITextDocument2<D>; };

template <typename D>
struct consume_Windows_UI_Text_ITextParagraphFormat
{
    Windows::UI::Text::ParagraphAlignment Alignment() const noexcept;
    void Alignment(Windows::UI::Text::ParagraphAlignment const& value) const noexcept;
    float FirstLineIndent() const noexcept;
    Windows::UI::Text::FormatEffect KeepTogether() const noexcept;
    void KeepTogether(Windows::UI::Text::FormatEffect const& value) const noexcept;
    Windows::UI::Text::FormatEffect KeepWithNext() const noexcept;
    void KeepWithNext(Windows::UI::Text::FormatEffect const& value) const noexcept;
    float LeftIndent() const noexcept;
    float LineSpacing() const noexcept;
    Windows::UI::Text::LineSpacingRule LineSpacingRule() const noexcept;
    Windows::UI::Text::MarkerAlignment ListAlignment() const noexcept;
    void ListAlignment(Windows::UI::Text::MarkerAlignment const& value) const noexcept;
    int32_t ListLevelIndex() const noexcept;
    void ListLevelIndex(int32_t value) const noexcept;
    int32_t ListStart() const noexcept;
    void ListStart(int32_t value) const noexcept;
    Windows::UI::Text::MarkerStyle ListStyle() const noexcept;
    void ListStyle(Windows::UI::Text::MarkerStyle const& value) const noexcept;
    float ListTab() const noexcept;
    void ListTab(float value) const noexcept;
    Windows::UI::Text::MarkerType ListType() const noexcept;
    void ListType(Windows::UI::Text::MarkerType const& value) const noexcept;
    Windows::UI::Text::FormatEffect NoLineNumber() const noexcept;
    void NoLineNumber(Windows::UI::Text::FormatEffect const& value) const noexcept;
    Windows::UI::Text::FormatEffect PageBreakBefore() const noexcept;
    void PageBreakBefore(Windows::UI::Text::FormatEffect const& value) const noexcept;
    float RightIndent() const noexcept;
    void RightIndent(float value) const noexcept;
    Windows::UI::Text::FormatEffect RightToLeft() const noexcept;
    void RightToLeft(Windows::UI::Text::FormatEffect const& value) const noexcept;
    Windows::UI::Text::ParagraphStyle Style() const noexcept;
    void Style(Windows::UI::Text::ParagraphStyle const& value) const noexcept;
    float SpaceAfter() const noexcept;
    void SpaceAfter(float value) const noexcept;
    float SpaceBefore() const noexcept;
    void SpaceBefore(float value) const noexcept;
    Windows::UI::Text::FormatEffect WidowControl() const noexcept;
    void WidowControl(Windows::UI::Text::FormatEffect const& value) const noexcept;
    int32_t TabCount() const noexcept;
    void AddTab(float position, Windows::UI::Text::TabAlignment const& align, Windows::UI::Text::TabLeader const& leader) const;
    void ClearAllTabs() const;
    void DeleteTab(float position) const;
    Windows::UI::Text::ITextParagraphFormat GetClone() const;
    void GetTab(int32_t index, float& position, Windows::UI::Text::TabAlignment& align, Windows::UI::Text::TabLeader& leader) const;
    bool IsEqual(Windows::UI::Text::ITextParagraphFormat const& format) const;
    void SetClone(Windows::UI::Text::ITextParagraphFormat const& format) const;
    void SetIndents(float start, float left, float right) const;
    void SetLineSpacing(Windows::UI::Text::LineSpacingRule const& rule, float spacing) const;
};
template <> struct consume<Windows::UI::Text::ITextParagraphFormat> { template <typename D> using type = consume_Windows_UI_Text_ITextParagraphFormat<D>; };

template <typename D>
struct consume_Windows_UI_Text_ITextRange
{
    char16_t Character() const noexcept;
    void Character(char16_t value) const noexcept;
    Windows::UI::Text::ITextCharacterFormat CharacterFormat() const noexcept;
    void CharacterFormat(Windows::UI::Text::ITextCharacterFormat const& value) const noexcept;
    Windows::UI::Text::ITextRange FormattedText() const noexcept;
    void FormattedText(Windows::UI::Text::ITextRange const& value) const noexcept;
    int32_t EndPosition() const noexcept;
    void EndPosition(int32_t value) const noexcept;
    Windows::UI::Text::RangeGravity Gravity() const noexcept;
    void Gravity(Windows::UI::Text::RangeGravity const& value) const noexcept;
    int32_t Length() const noexcept;
    hstring Link() const noexcept;
    void Link(param::hstring const& value) const noexcept;
    Windows::UI::Text::ITextParagraphFormat ParagraphFormat() const noexcept;
    void ParagraphFormat(Windows::UI::Text::ITextParagraphFormat const& value) const noexcept;
    int32_t StartPosition() const noexcept;
    void StartPosition(int32_t value) const noexcept;
    int32_t StoryLength() const noexcept;
    hstring Text() const noexcept;
    void Text(param::hstring const& value) const noexcept;
    bool CanPaste(int32_t format) const;
    void ChangeCase(Windows::UI::Text::LetterCase const& value) const;
    void Collapse(bool value) const;
    void Copy() const;
    void Cut() const;
    int32_t Delete(Windows::UI::Text::TextRangeUnit const& unit, int32_t count) const;
    int32_t EndOf(Windows::UI::Text::TextRangeUnit const& unit, bool extend) const;
    int32_t Expand(Windows::UI::Text::TextRangeUnit const& unit) const;
    int32_t FindText(param::hstring const& value, int32_t scanLength, Windows::UI::Text::FindOptions const& options) const;
    void GetCharacterUtf32(uint32_t& value, int32_t offset) const;
    Windows::UI::Text::ITextRange GetClone() const;
    int32_t GetIndex(Windows::UI::Text::TextRangeUnit const& unit) const;
    void GetPoint(Windows::UI::Text::HorizontalCharacterAlignment const& horizontalAlign, Windows::UI::Text::VerticalCharacterAlignment const& verticalAlign, Windows::UI::Text::PointOptions const& options, Windows::Foundation::Point& point) const;
    void GetRect(Windows::UI::Text::PointOptions const& options, Windows::Foundation::Rect& rect, int32_t& hit) const;
    void GetText(Windows::UI::Text::TextGetOptions const& options, hstring& value) const;
    void GetTextViaStream(Windows::UI::Text::TextGetOptions const& options, Windows::Storage::Streams::IRandomAccessStream const& value) const;
    bool InRange(Windows::UI::Text::ITextRange const& range) const;
    void InsertImage(int32_t width, int32_t height, int32_t ascent, Windows::UI::Text::VerticalCharacterAlignment const& verticalAlign, param::hstring const& alternateText, Windows::Storage::Streams::IRandomAccessStream const& value) const;
    bool InStory(Windows::UI::Text::ITextRange const& range) const;
    bool IsEqual(Windows::UI::Text::ITextRange const& range) const;
    int32_t Move(Windows::UI::Text::TextRangeUnit const& unit, int32_t count) const;
    int32_t MoveEnd(Windows::UI::Text::TextRangeUnit const& unit, int32_t count) const;
    int32_t MoveStart(Windows::UI::Text::TextRangeUnit const& unit, int32_t count) const;
    void Paste(int32_t format) const;
    void ScrollIntoView(Windows::UI::Text::PointOptions const& value) const;
    void MatchSelection() const;
    void SetIndex(Windows::UI::Text::TextRangeUnit const& unit, int32_t index, bool extend) const;
    void SetPoint(Windows::Foundation::Point const& point, Windows::UI::Text::PointOptions const& options, bool extend) const;
    void SetRange(int32_t startPosition, int32_t endPosition) const;
    void SetText(Windows::UI::Text::TextSetOptions const& options, param::hstring const& value) const;
    void SetTextViaStream(Windows::UI::Text::TextSetOptions const& options, Windows::Storage::Streams::IRandomAccessStream const& value) const;
    int32_t StartOf(Windows::UI::Text::TextRangeUnit const& unit, bool extend) const;
};
template <> struct consume<Windows::UI::Text::ITextRange> { template <typename D> using type = consume_Windows_UI_Text_ITextRange<D>; };

template <typename D>
struct consume_Windows_UI_Text_ITextSelection
{
    Windows::UI::Text::SelectionOptions Options() const noexcept;
    void Options(Windows::UI::Text::SelectionOptions const& value) const noexcept;
    Windows::UI::Text::SelectionType Type() const noexcept;
    int32_t EndKey(Windows::UI::Text::TextRangeUnit const& unit, bool extend) const;
    int32_t HomeKey(Windows::UI::Text::TextRangeUnit const& unit, bool extend) const;
    int32_t MoveDown(Windows::UI::Text::TextRangeUnit const& unit, int32_t count, bool extend) const;
    int32_t MoveLeft(Windows::UI::Text::TextRangeUnit const& unit, int32_t count, bool extend) const;
    int32_t MoveRight(Windows::UI::Text::TextRangeUnit const& unit, int32_t count, bool extend) const;
    int32_t MoveUp(Windows::UI::Text::TextRangeUnit const& unit, int32_t count, bool extend) const;
    void TypeText(param::hstring const& value) const;
};
template <> struct consume<Windows::UI::Text::ITextSelection> { template <typename D> using type = consume_Windows_UI_Text_ITextSelection<D>; };

template <> struct abi<Windows::UI::Text::IFontWeights>{ struct type : ::IInspectable
{
};};

template <> struct abi<Windows::UI::Text::IFontWeightsStatics>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Black(struct_of<2>* value) = 0;
    virtual HRESULT __stdcall get_Bold(struct_of<2>* value) = 0;
    virtual HRESULT __stdcall get_ExtraBlack(struct_of<2>* value) = 0;
    virtual HRESULT __stdcall get_ExtraBold(struct_of<2>* value) = 0;
    virtual HRESULT __stdcall get_ExtraLight(struct_of<2>* value) = 0;
    virtual HRESULT __stdcall get_Light(struct_of<2>* value) = 0;
    virtual HRESULT __stdcall get_Medium(struct_of<2>* value) = 0;
    virtual HRESULT __stdcall get_Normal(struct_of<2>* value) = 0;
    virtual HRESULT __stdcall get_SemiBold(struct_of<2>* value) = 0;
    virtual HRESULT __stdcall get_SemiLight(struct_of<2>* value) = 0;
    virtual HRESULT __stdcall get_Thin(struct_of<2>* value) = 0;
};};

template <> struct abi<Windows::UI::Text::ITextCharacterFormat>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_AllCaps(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_AllCaps(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_BackgroundColor(struct_of<4>* value) = 0;
    virtual HRESULT __stdcall put_BackgroundColor(struct_of<4> value) = 0;
    virtual HRESULT __stdcall get_Bold(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_Bold(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_FontStretch(Windows::UI::Text::FontStretch* value) = 0;
    virtual HRESULT __stdcall put_FontStretch(Windows::UI::Text::FontStretch value) = 0;
    virtual HRESULT __stdcall get_FontStyle(Windows::UI::Text::FontStyle* value) = 0;
    virtual HRESULT __stdcall put_FontStyle(Windows::UI::Text::FontStyle value) = 0;
    virtual HRESULT __stdcall get_ForegroundColor(struct_of<4>* value) = 0;
    virtual HRESULT __stdcall put_ForegroundColor(struct_of<4> value) = 0;
    virtual HRESULT __stdcall get_Hidden(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_Hidden(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_Italic(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_Italic(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_Kerning(float* value) = 0;
    virtual HRESULT __stdcall put_Kerning(float value) = 0;
    virtual HRESULT __stdcall get_LanguageTag(HSTRING* value) = 0;
    virtual HRESULT __stdcall put_LanguageTag(HSTRING value) = 0;
    virtual HRESULT __stdcall get_LinkType(Windows::UI::Text::LinkType* value) = 0;
    virtual HRESULT __stdcall get_Name(HSTRING* value) = 0;
    virtual HRESULT __stdcall put_Name(HSTRING value) = 0;
    virtual HRESULT __stdcall get_Outline(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_Outline(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_Position(float* value) = 0;
    virtual HRESULT __stdcall put_Position(float value) = 0;
    virtual HRESULT __stdcall get_ProtectedText(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_ProtectedText(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_Size(float* value) = 0;
    virtual HRESULT __stdcall put_Size(float value) = 0;
    virtual HRESULT __stdcall get_SmallCaps(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_SmallCaps(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_Spacing(float* value) = 0;
    virtual HRESULT __stdcall put_Spacing(float value) = 0;
    virtual HRESULT __stdcall get_Strikethrough(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_Strikethrough(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_Subscript(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_Subscript(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_Superscript(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_Superscript(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_TextScript(Windows::UI::Text::TextScript* value) = 0;
    virtual HRESULT __stdcall put_TextScript(Windows::UI::Text::TextScript value) = 0;
    virtual HRESULT __stdcall get_Underline(Windows::UI::Text::UnderlineType* value) = 0;
    virtual HRESULT __stdcall put_Underline(Windows::UI::Text::UnderlineType value) = 0;
    virtual HRESULT __stdcall get_Weight(int32_t* value) = 0;
    virtual HRESULT __stdcall put_Weight(int32_t value) = 0;
    virtual HRESULT __stdcall SetClone(::IUnknown* value) = 0;
    virtual HRESULT __stdcall GetClone(::IUnknown** value) = 0;
    virtual HRESULT __stdcall IsEqual(::IUnknown* format, bool* value) = 0;
};};

template <> struct abi<Windows::UI::Text::ITextConstantsStatics>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_AutoColor(struct_of<4>* value) = 0;
    virtual HRESULT __stdcall get_MinUnitCount(int32_t* value) = 0;
    virtual HRESULT __stdcall get_MaxUnitCount(int32_t* value) = 0;
    virtual HRESULT __stdcall get_UndefinedColor(struct_of<4>* value) = 0;
    virtual HRESULT __stdcall get_UndefinedFloatValue(float* value) = 0;
    virtual HRESULT __stdcall get_UndefinedInt32Value(int32_t* value) = 0;
    virtual HRESULT __stdcall get_UndefinedFontStretch(Windows::UI::Text::FontStretch* value) = 0;
    virtual HRESULT __stdcall get_UndefinedFontStyle(Windows::UI::Text::FontStyle* value) = 0;
};};

template <> struct abi<Windows::UI::Text::ITextDocument>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_CaretType(Windows::UI::Text::CaretType* value) = 0;
    virtual HRESULT __stdcall put_CaretType(Windows::UI::Text::CaretType value) = 0;
    virtual HRESULT __stdcall get_DefaultTabStop(float* value) = 0;
    virtual HRESULT __stdcall put_DefaultTabStop(float value) = 0;
    virtual HRESULT __stdcall get_Selection(::IUnknown** value) = 0;
    virtual HRESULT __stdcall get_UndoLimit(uint32_t* value) = 0;
    virtual HRESULT __stdcall put_UndoLimit(uint32_t value) = 0;
    virtual HRESULT __stdcall CanCopy(bool* value) = 0;
    virtual HRESULT __stdcall CanPaste(bool* value) = 0;
    virtual HRESULT __stdcall CanRedo(bool* value) = 0;
    virtual HRESULT __stdcall CanUndo(bool* value) = 0;
    virtual HRESULT __stdcall ApplyDisplayUpdates(int32_t* count) = 0;
    virtual HRESULT __stdcall BatchDisplayUpdates(int32_t* count) = 0;
    virtual HRESULT __stdcall BeginUndoGroup() = 0;
    virtual HRESULT __stdcall EndUndoGroup() = 0;
    virtual HRESULT __stdcall GetDefaultCharacterFormat(::IUnknown** value) = 0;
    virtual HRESULT __stdcall GetDefaultParagraphFormat(::IUnknown** value) = 0;
    virtual HRESULT __stdcall GetRange(int32_t startPosition, int32_t endPosition, ::IUnknown** value) = 0;
    virtual HRESULT __stdcall GetRangeFromPoint(Windows::Foundation::Point point, Windows::UI::Text::PointOptions options, ::IUnknown** value) = 0;
    virtual HRESULT __stdcall GetText(Windows::UI::Text::TextGetOptions options, HSTRING* value) = 0;
    virtual HRESULT __stdcall LoadFromStream(Windows::UI::Text::TextSetOptions options, ::IUnknown* value) = 0;
    virtual HRESULT __stdcall Redo() = 0;
    virtual HRESULT __stdcall SaveToStream(Windows::UI::Text::TextGetOptions options, ::IUnknown* value) = 0;
    virtual HRESULT __stdcall SetDefaultCharacterFormat(::IUnknown* value) = 0;
    virtual HRESULT __stdcall SetDefaultParagraphFormat(::IUnknown* value) = 0;
    virtual HRESULT __stdcall SetText(Windows::UI::Text::TextSetOptions options, HSTRING value) = 0;
    virtual HRESULT __stdcall Undo() = 0;
};};

template <> struct abi<Windows::UI::Text::ITextDocument2>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_AlignmentIncludesTrailingWhitespace(bool* value) = 0;
    virtual HRESULT __stdcall put_AlignmentIncludesTrailingWhitespace(bool value) = 0;
    virtual HRESULT __stdcall get_IgnoreTrailingCharacterSpacing(bool* value) = 0;
    virtual HRESULT __stdcall put_IgnoreTrailingCharacterSpacing(bool value) = 0;
};};

template <> struct abi<Windows::UI::Text::ITextParagraphFormat>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Alignment(Windows::UI::Text::ParagraphAlignment* value) = 0;
    virtual HRESULT __stdcall put_Alignment(Windows::UI::Text::ParagraphAlignment value) = 0;
    virtual HRESULT __stdcall get_FirstLineIndent(float* value) = 0;
    virtual HRESULT __stdcall get_KeepTogether(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_KeepTogether(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_KeepWithNext(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_KeepWithNext(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_LeftIndent(float* value) = 0;
    virtual HRESULT __stdcall get_LineSpacing(float* value) = 0;
    virtual HRESULT __stdcall get_LineSpacingRule(Windows::UI::Text::LineSpacingRule* value) = 0;
    virtual HRESULT __stdcall get_ListAlignment(Windows::UI::Text::MarkerAlignment* value) = 0;
    virtual HRESULT __stdcall put_ListAlignment(Windows::UI::Text::MarkerAlignment value) = 0;
    virtual HRESULT __stdcall get_ListLevelIndex(int32_t* value) = 0;
    virtual HRESULT __stdcall put_ListLevelIndex(int32_t value) = 0;
    virtual HRESULT __stdcall get_ListStart(int32_t* value) = 0;
    virtual HRESULT __stdcall put_ListStart(int32_t value) = 0;
    virtual HRESULT __stdcall get_ListStyle(Windows::UI::Text::MarkerStyle* value) = 0;
    virtual HRESULT __stdcall put_ListStyle(Windows::UI::Text::MarkerStyle value) = 0;
    virtual HRESULT __stdcall get_ListTab(float* value) = 0;
    virtual HRESULT __stdcall put_ListTab(float value) = 0;
    virtual HRESULT __stdcall get_ListType(Windows::UI::Text::MarkerType* value) = 0;
    virtual HRESULT __stdcall put_ListType(Windows::UI::Text::MarkerType value) = 0;
    virtual HRESULT __stdcall get_NoLineNumber(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_NoLineNumber(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_PageBreakBefore(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_PageBreakBefore(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_RightIndent(float* value) = 0;
    virtual HRESULT __stdcall put_RightIndent(float value) = 0;
    virtual HRESULT __stdcall get_RightToLeft(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_RightToLeft(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_Style(Windows::UI::Text::ParagraphStyle* value) = 0;
    virtual HRESULT __stdcall put_Style(Windows::UI::Text::ParagraphStyle value) = 0;
    virtual HRESULT __stdcall get_SpaceAfter(float* value) = 0;
    virtual HRESULT __stdcall put_SpaceAfter(float value) = 0;
    virtual HRESULT __stdcall get_SpaceBefore(float* value) = 0;
    virtual HRESULT __stdcall put_SpaceBefore(float value) = 0;
    virtual HRESULT __stdcall get_WidowControl(Windows::UI::Text::FormatEffect* value) = 0;
    virtual HRESULT __stdcall put_WidowControl(Windows::UI::Text::FormatEffect value) = 0;
    virtual HRESULT __stdcall get_TabCount(int32_t* value) = 0;
    virtual HRESULT __stdcall AddTab(float position, Windows::UI::Text::TabAlignment align, Windows::UI::Text::TabLeader leader) = 0;
    virtual HRESULT __stdcall ClearAllTabs() = 0;
    virtual HRESULT __stdcall DeleteTab(float position) = 0;
    virtual HRESULT __stdcall GetClone(::IUnknown** value) = 0;
    virtual HRESULT __stdcall GetTab(int32_t index, float* position, Windows::UI::Text::TabAlignment* align, Windows::UI::Text::TabLeader* leader) = 0;
    virtual HRESULT __stdcall IsEqual(::IUnknown* format, bool* value) = 0;
    virtual HRESULT __stdcall SetClone(::IUnknown* format) = 0;
    virtual HRESULT __stdcall SetIndents(float start, float left, float right) = 0;
    virtual HRESULT __stdcall SetLineSpacing(Windows::UI::Text::LineSpacingRule rule, float spacing) = 0;
};};

template <> struct abi<Windows::UI::Text::ITextRange>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Character(char16_t* value) = 0;
    virtual HRESULT __stdcall put_Character(char16_t value) = 0;
    virtual HRESULT __stdcall get_CharacterFormat(::IUnknown** value) = 0;
    virtual HRESULT __stdcall put_CharacterFormat(::IUnknown* value) = 0;
    virtual HRESULT __stdcall get_FormattedText(::IUnknown** value) = 0;
    virtual HRESULT __stdcall put_FormattedText(::IUnknown* value) = 0;
    virtual HRESULT __stdcall get_EndPosition(int32_t* value) = 0;
    virtual HRESULT __stdcall put_EndPosition(int32_t value) = 0;
    virtual HRESULT __stdcall get_Gravity(Windows::UI::Text::RangeGravity* value) = 0;
    virtual HRESULT __stdcall put_Gravity(Windows::UI::Text::RangeGravity value) = 0;
    virtual HRESULT __stdcall get_Length(int32_t* length) = 0;
    virtual HRESULT __stdcall get_Link(HSTRING* value) = 0;
    virtual HRESULT __stdcall put_Link(HSTRING value) = 0;
    virtual HRESULT __stdcall get_ParagraphFormat(::IUnknown** value) = 0;
    virtual HRESULT __stdcall put_ParagraphFormat(::IUnknown* value) = 0;
    virtual HRESULT __stdcall get_StartPosition(int32_t* value) = 0;
    virtual HRESULT __stdcall put_StartPosition(int32_t value) = 0;
    virtual HRESULT __stdcall get_StoryLength(int32_t* value) = 0;
    virtual HRESULT __stdcall get_Text(HSTRING* value) = 0;
    virtual HRESULT __stdcall put_Text(HSTRING value) = 0;
    virtual HRESULT __stdcall CanPaste(int32_t format, bool* value) = 0;
    virtual HRESULT __stdcall ChangeCase(Windows::UI::Text::LetterCase value) = 0;
    virtual HRESULT __stdcall Collapse(bool value) = 0;
    virtual HRESULT __stdcall Copy() = 0;
    virtual HRESULT __stdcall Cut() = 0;
    virtual HRESULT __stdcall Delete(Windows::UI::Text::TextRangeUnit unit, int32_t count, int32_t* delta) = 0;
    virtual HRESULT __stdcall EndOf(Windows::UI::Text::TextRangeUnit unit, bool extend, int32_t* delta) = 0;
    virtual HRESULT __stdcall Expand(Windows::UI::Text::TextRangeUnit unit, int32_t* delta) = 0;
    virtual HRESULT __stdcall FindText(HSTRING value, int32_t scanLength, Windows::UI::Text::FindOptions options, int32_t* length) = 0;
    virtual HRESULT __stdcall GetCharacterUtf32(uint32_t* value, int32_t offset) = 0;
    virtual HRESULT __stdcall GetClone(::IUnknown** value) = 0;
    virtual HRESULT __stdcall GetIndex(Windows::UI::Text::TextRangeUnit unit, int32_t* index) = 0;
    virtual HRESULT __stdcall GetPoint(Windows::UI::Text::HorizontalCharacterAlignment horizontalAlign, Windows::UI::Text::VerticalCharacterAlignment verticalAlign, Windows::UI::Text::PointOptions options, Windows::Foundation::Point* point) = 0;
    virtual HRESULT __stdcall GetRect(Windows::UI::Text::PointOptions options, Windows::Foundation::Rect* rect, int32_t* hit) = 0;
    virtual HRESULT __stdcall GetText(Windows::UI::Text::TextGetOptions options, HSTRING* value) = 0;
    virtual HRESULT __stdcall GetTextViaStream(Windows::UI::Text::TextGetOptions options, ::IUnknown* value) = 0;
    virtual HRESULT __stdcall InRange(::IUnknown* range, bool* value) = 0;
    virtual HRESULT __stdcall InsertImage(int32_t width, int32_t height, int32_t ascent, Windows::UI::Text::VerticalCharacterAlignment verticalAlign, HSTRING alternateText, ::IUnknown* value) = 0;
    virtual HRESULT __stdcall InStory(::IUnknown* range, bool* value) = 0;
    virtual HRESULT __stdcall IsEqual(::IUnknown* range, bool* value) = 0;
    virtual HRESULT __stdcall Move(Windows::UI::Text::TextRangeUnit unit, int32_t count, int32_t* delta) = 0;
    virtual HRESULT __stdcall MoveEnd(Windows::UI::Text::TextRangeUnit unit, int32_t count, int32_t* delta) = 0;
    virtual HRESULT __stdcall MoveStart(Windows::UI::Text::TextRangeUnit unit, int32_t count, int32_t* delta) = 0;
    virtual HRESULT __stdcall Paste(int32_t format) = 0;
    virtual HRESULT __stdcall ScrollIntoView(Windows::UI::Text::PointOptions value) = 0;
    virtual HRESULT __stdcall MatchSelection() = 0;
    virtual HRESULT __stdcall SetIndex(Windows::UI::Text::TextRangeUnit unit, int32_t index, bool extend) = 0;
    virtual HRESULT __stdcall SetPoint(Windows::Foundation::Point point, Windows::UI::Text::PointOptions options, bool extend) = 0;
    virtual HRESULT __stdcall SetRange(int32_t startPosition, int32_t endPosition) = 0;
    virtual HRESULT __stdcall SetText(Windows::UI::Text::TextSetOptions options, HSTRING value) = 0;
    virtual HRESULT __stdcall SetTextViaStream(Windows::UI::Text::TextSetOptions options, ::IUnknown* value) = 0;
    virtual HRESULT __stdcall StartOf(Windows::UI::Text::TextRangeUnit unit, bool extend, int32_t* delta) = 0;
};};

template <> struct abi<Windows::UI::Text::ITextSelection>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Options(Windows::UI::Text::SelectionOptions* value) = 0;
    virtual HRESULT __stdcall put_Options(Windows::UI::Text::SelectionOptions value) = 0;
    virtual HRESULT __stdcall get_Type(Windows::UI::Text::SelectionType* value) = 0;
    virtual HRESULT __stdcall EndKey(Windows::UI::Text::TextRangeUnit unit, bool extend, int32_t* delta) = 0;
    virtual HRESULT __stdcall HomeKey(Windows::UI::Text::TextRangeUnit unit, bool extend, int32_t* delta) = 0;
    virtual HRESULT __stdcall MoveDown(Windows::UI::Text::TextRangeUnit unit, int32_t count, bool extend, int32_t* delta) = 0;
    virtual HRESULT __stdcall MoveLeft(Windows::UI::Text::TextRangeUnit unit, int32_t count, bool extend, int32_t* delta) = 0;
    virtual HRESULT __stdcall MoveRight(Windows::UI::Text::TextRangeUnit unit, int32_t count, bool extend, int32_t* delta) = 0;
    virtual HRESULT __stdcall MoveUp(Windows::UI::Text::TextRangeUnit unit, int32_t count, bool extend, int32_t* delta) = 0;
    virtual HRESULT __stdcall TypeText(HSTRING value) = 0;
};};

}
