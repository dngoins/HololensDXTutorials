cbuffer CBufferPerObject
{
	float4x4 WorldViewProjection: WORLDVIEWPROJECTION;
};

struct VS_INPUT
{
	float4 ObjectPosition: POSITION;
};

struct VS_OUTPUT
{
	float4 Position: SV_Position;
	float3 TextureCoordinate : TEXCOORD;
};


VS_OUTPUT main( VS_INPUT IN)
{
	VS_OUTPUT result = (VS_OUTPUT)0;
	result.Position = mul(IN.ObjectPosition, WorldViewProjection);
	result.TextureCoordinate = IN.ObjectPosition.xyz;

	return result;
}