//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

Texture2D ColorTexture;
SamplerState ColorSampler;

// A constant buffer that stores per-mesh data.
cbuffer ModelConstantBuffer : register(b0)
{
    float4x4      modelToWorld;
    min16float4x4 normalToWorld;
    min16float4   colorFadeFactor;
};

// Per-pixel data.
struct PixelShaderInput
{    
	min16float4 screenPos   : SV_POSITION;
	min16float3 worldPos    : POSITION0;
	min16float3 worldNorm   : NORMAL0;
	min16float3 color       : COLOR0;
	uint        idx         : TEXCOORD1;
	min16float2 textCoord	: TEXCOORD0;
	uint        rtvId       : SV_RenderTargetArrayIndex;
};

// The pixel shader returns a solid color (red).
min16float4 main(PixelShaderInput input) : SV_TARGET
{
    // In this example, new surfaces are treated differently by highlighting them in a different
    // color. This allows you to observe changes in the spatial map that are due to new meshes,
    // as opposed to mesh updates.
//	min16float3 inputColor = input.color;
   min16float3 inputColor = (min16float4)ColorTexture.Sample(ColorSampler, input.textCoord);
    const min16float3 oneMinusColorFadeFactor = min16float3(1.f, 1.f, 1.f) - (min16float3)colorFadeFactor;
    const min16float3 fadedColor = (inputColor * oneMinusColorFadeFactor) + (min16float3(0.75f, 0.1f, 0.1f) * (min16float3)colorFadeFactor);

	//return (min16float4)ColorTexture.Sample(ColorSampler, input.textCoord);
    return min16float4(fadedColor, 1.f);
}
