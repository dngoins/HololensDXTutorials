// Per-vertex data from the vertex shader.
struct GeometryShaderInput
{
    min16float4 pos     : SV_POSITION;
	//TODO: Change the geometry input variable and semantic to coordinates
    min16float3 coord   : TEXCOORD0;
	//TODO: rename the geometry input semantic so it doesn't crash
    uint        instId  : TEXCOORD1;
};

// Per-vertex data passed to the rasterizer.
struct GeometryShaderOutput
{
    min16float4 pos     : SV_POSITION;
	//TODO: change the geometry output variable and semantic for passing into pixel shader
    min16float3 coord   : TEXCOORD0;
    uint        rtvId   : SV_RenderTargetArrayIndex;
};

// This geometry shader is a pass-through that leaves the geometry unmodified 
// and sets the render target array index.
[maxvertexcount(3)]
void main(triangle GeometryShaderInput input[3], inout TriangleStream<GeometryShaderOutput> outStream)
{
    GeometryShaderOutput output;
    [unroll(3)]
    for (int i = 0; i < 3; ++i)
    {
        output.pos = input[i].pos;
		//TODO: just do a passthrough on the coordinates of the geometry shader output
        output.coord = input[i].coord;
        output.rtvId = input[i].instId;
        outStream.Append(output);
    }
}
