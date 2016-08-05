using System.Numerics;

namespace TexturedCubeSample.Content
{
    /// <summary>
    /// Constant buffer used to send hologram position transform to the shader pipeline.
    /// </summary>
    internal struct ModelConstantBuffer
    {
        public Matrix4x4 model;
    }

    /// <summary>
    /// Used to send per-vertex data to the vertex shader.
    /// </summary>
    internal struct VertexPositionColor
    {
        public VertexPositionColor(Vector3 pos, Vector3 color)
        {
            this.pos   = pos;
            this.color = color;
        }

        public Vector3 pos;
        public Vector3 color;
    };

    //TODO: Add new structure to hold VertexPositionCoordinates
    //Added to show how to use texture coordinates
    internal struct VertexPositionCoordinate
    {
        public VertexPositionCoordinate(Vector3 pos, Vector3 coord)
        {
            this.pos = pos;
            this.coordinate = coord;
        }

        public Vector3 pos;
        public Vector3 coordinate;
    };
}
