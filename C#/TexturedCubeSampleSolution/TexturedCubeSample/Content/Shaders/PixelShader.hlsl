//TODO: Add the SamplerState and TextureCube resource
TextureCube ColorTexture;
SamplerState ColorSampler;

// Per-pixel color data passed through the pixel shader.
struct PixelShaderInput
{
    min16float4 pos   : SV_POSITION;
	//TODO: change the color to coordinates in the pixel shader
	min16float3 coord : TEXCOORD0;
};

// The pixel shader passes through the color data. The color data from 
// is interpolated and assigned to a pixel at the rasterization step.
min16float4 main(PixelShaderInput input) : SV_TARGET
{
	//TODO: In the Pixel Shader, return the TextureCube lookup colors by using the .Sample() method and passing in the samplerstate and coordinates to lookup 
    return ColorTexture.Sample(ColorSampler, input.coord);
}
