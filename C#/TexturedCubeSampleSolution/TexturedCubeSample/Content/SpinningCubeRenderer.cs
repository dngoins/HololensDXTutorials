using System;
using System.Numerics;
using TexturedCubeSample.Common;
using Windows.UI.Input.Spatial;

namespace TexturedCubeSample.Content
{
    /// <summary>
    /// This sample renderer instantiates a basic rendering pipeline.
    /// </summary>
    internal class SpinningCubeRenderer : Disposer
    {
        // Cached reference to device resources.
        private DeviceResources                     deviceResources;

        // Direct3D resources for cube geometry.
        private SharpDX.Direct3D11.InputLayout      inputLayout;
        private SharpDX.Direct3D11.Buffer           vertexBuffer;
        private SharpDX.Direct3D11.Buffer           indexBuffer;
        private SharpDX.Direct3D11.VertexShader     vertexShader;
        private SharpDX.Direct3D11.GeometryShader   geometryShader;
        private SharpDX.Direct3D11.PixelShader      pixelShader;
        private SharpDX.Direct3D11.Buffer           modelConstantBuffer;

        //TODO: Add variables
        private SharpDX.Direct3D11.ShaderResourceView textureResource;
        private SharpDX.Direct3D11.SamplerState samplerState;


        // System resources for cube geometry.
        private ModelConstantBuffer                 modelConstantBufferData;
        private int                                 indexCount = 0;
        private Vector3                             position = new Vector3(0.0f, 0.0f, -2.0f);

        // Variables used with the rendering loop.
        private bool                                loadingComplete = false;
        private float                               degreesPerSecond = 45.0f;


        // If the current D3D Device supports VPRT, we can avoid using a geometry
        // shader just to set the render target array index.
        private bool                                usingVprtShaders = false;

        /// <summary>
        /// Loads vertex and pixel shaders from files and instantiates the cube geometry.
        /// </summary>
        public SpinningCubeRenderer(DeviceResources deviceResources)
        {
            this.deviceResources  = deviceResources;

            this.CreateDeviceDependentResourcesAsync();
        }

        // This function uses a SpatialPointerPose to position the world-locked hologram
        // two meters in front of the user's heading.
        public void PositionHologram(SpatialPointerPose pointerPose)
        {
            if (null != pointerPose)
            {
                // Get the gaze direction relative to the given coordinate system.
                Vector3 headPosition        = pointerPose.Head.Position;
                Vector3 headDirection       = pointerPose.Head.ForwardDirection;

                // The hologram is positioned two meters along the user's gaze direction.
                float   distanceFromUser    = 2.0f; // meters
                Vector3 gazeAtTwoMeters     = headPosition + (distanceFromUser * headDirection);

                // This will be used as the translation component of the hologram's
                // model transform.
                this.position = gazeAtTwoMeters;
            }
        }

        /// <summary>
        /// Called once per frame, rotates the cube and calculates the model and view matrices.
        /// </summary>
        public void Update(StepTimer timer)
        {
            // Rotate the cube.
            // Convert degrees to radians, then convert seconds to rotation angle.
            float     radiansPerSecond  = this.degreesPerSecond * ((float)Math.PI / 180.0f);
            double    totalRotation     = timer.TotalSeconds * radiansPerSecond;
            float     radians           = (float)System.Math.IEEERemainder(totalRotation, 2 * Math.PI);
            Matrix4x4 modelRotation     = Matrix4x4.CreateFromAxisAngle(new Vector3(0, 1, 0), -radians);


            // Position the cube.
            Matrix4x4 modelTranslation  = Matrix4x4.CreateTranslation(position);


            // Multiply to get the transform matrix.
            // Note that this transform does not enforce a particular coordinate system. The calling
            // class is responsible for rendering this content in a consistent manner.
            Matrix4x4 modelTransform    = modelRotation * modelTranslation;

            // The view and projection matrices are provided by the system; they are associated
            // with holographic cameras, and updated on a per-camera basis.
            // Here, we provide the model transform for the sample hologram. The model transform
            // matrix is transposed to prepare it for the shader.
            this.modelConstantBufferData.model = Matrix4x4.Transpose(modelTransform);

            // Loading is asynchronous. Resources must be created before they can be updated.
            if (!loadingComplete)
            {
                return;
            }

            // Use the D3D device context to update Direct3D device-based resources.
            var context = this.deviceResources.D3DDeviceContext;

            // Update the model transform buffer for the hologram.
            context.UpdateSubresource(ref this.modelConstantBufferData, this.modelConstantBuffer);
        }

        /// <summary>
        /// Renders one frame using the vertex and pixel shaders.
        /// On devices that do not support the D3D11_FEATURE_D3D11_OPTIONS3::
        /// VPAndRTArrayIndexFromAnyShaderFeedingRasterizer optional feature,
        /// a pass-through geometry shader is also used to set the render 
        /// target array index.
        /// </summary>
        public void Render()
        {
            // Loading is asynchronous. Resources must be created before drawing can occur.
            if (!this.loadingComplete)
            {
                return;
            }

            var context = this.deviceResources.D3DDeviceContext;
            
            // Each vertex is one instance of the VertexPositionColor struct.
            int stride = SharpDX.Utilities.SizeOf<VertexPositionColor>();
            int offset = 0;
            var bufferBinding = new SharpDX.Direct3D11.VertexBufferBinding(this.vertexBuffer, stride, offset);
            context.InputAssembler.SetVertexBuffers(0, bufferBinding);
            context.InputAssembler.SetIndexBuffer(
                this.indexBuffer,
                SharpDX.DXGI.Format.R16_UInt, // Each index is one 16-bit unsigned integer (short).
                0);
            context.InputAssembler.PrimitiveTopology = SharpDX.Direct3D.PrimitiveTopology.TriangleList;
            context.InputAssembler.InputLayout = this.inputLayout;

            // Attach the vertex shader.
            context.VertexShader.SetShader(this.vertexShader, null, 0);
            // Apply the model constant buffer to the vertex shader.
            context.VertexShader.SetConstantBuffers(0, this.modelConstantBuffer);

            if (!this.usingVprtShaders)
            {
                // On devices that do not support the D3D11_FEATURE_D3D11_OPTIONS3::
                // VPAndRTArrayIndexFromAnyShaderFeedingRasterizer optional feature,
                // a pass-through geometry shader is used to set the render target 
                // array index.
                context.GeometryShader.SetShader(this.geometryShader, null, 0);
            }

            //TODO: Attached Sampler and Texture to PixelShader
            context.PixelShader.SetSampler(0, samplerState);
            context.PixelShader.SetShaderResource(0, textureResource);
            

            // Attach the pixel shader.
            context.PixelShader.SetShader(this.pixelShader, null, 0);

            // Draw the objects.
            context.DrawIndexedInstanced(
                indexCount,     // Index count per instance.
                2,              // Instance count.
                0,              // Start index location.
                0,              // Base vertex location.
                0               // Start instance location.
                );
        }

        /// <summary>
        /// Creates device-based resources to store a constant buffer, cube
        /// geometry, and vertex and pixel shaders. In some cases this will also 
        /// store a geometry shader.
        /// </summary>
        public async void CreateDeviceDependentResourcesAsync()
        {
            ReleaseDeviceDependentResources();

            usingVprtShaders = deviceResources.D3DDeviceSupportsVprt;

            var folder = Windows.ApplicationModel.Package.Current.InstalledLocation;
            
            // On devices that do support the D3D11_FEATURE_D3D11_OPTIONS3::
            // VPAndRTArrayIndexFromAnyShaderFeedingRasterizer optional feature
            // we can avoid using a pass-through geometry shader to set the render
            // target array index, thus avoiding any overhead that would be 
            // incurred by setting the geometry shader stage.
            var vertexShaderFileName = usingVprtShaders ? "Content\\Shaders\\VPRTVertexShader.cso" : "Content\\Shaders\\VertexShader.cso";

            // Load the compiled vertex shader.
            var vertexShaderByteCode = await DirectXHelper.ReadDataAsync(await folder.GetFileAsync(vertexShaderFileName));

            // After the vertex shader file is loaded, create the shader and input layout.
            vertexShader = this.ToDispose(new SharpDX.Direct3D11.VertexShader(
                deviceResources.D3DDevice,
                vertexShaderByteCode));

            //TODO: Change VertexDesc to use new structure: VertexPositionTextureCoordinates
            SharpDX.Direct3D11.InputElement[] vertexDesc =
            {
                new SharpDX.Direct3D11.InputElement("POSITION", 0, SharpDX.DXGI.Format.R32G32B32_Float,  0, 0, SharpDX.Direct3D11.InputClassification.PerVertexData, 0),
                new SharpDX.Direct3D11.InputElement("TEXCOORD",    0, SharpDX.DXGI.Format.R32G32B32_Float, 12, 0, SharpDX.Direct3D11.InputClassification.PerVertexData, 0),
            };


            inputLayout = this.ToDispose(new SharpDX.Direct3D11.InputLayout(
                deviceResources.D3DDevice,
                vertexShaderByteCode,
                vertexDesc));
            
            if (!usingVprtShaders)
            {
                // Load the compiled pass-through geometry shader.
                var geometryShaderByteCode = await DirectXHelper.ReadDataAsync(await folder.GetFileAsync("Content\\Shaders\\GeometryShader.cso"));

                // After the pass-through geometry shader file is loaded, create the shader.
                geometryShader = this.ToDispose(new SharpDX.Direct3D11.GeometryShader(
                    deviceResources.D3DDevice,
                    geometryShaderByteCode));
            }

            // Load the compiled pixel shader.
            var pixelShaderByteCode = await DirectXHelper.ReadDataAsync(await folder.GetFileAsync("Content\\Shaders\\PixelShader.cso"));

            // After the pixel shader file is loaded, create the shader.
            pixelShader = this.ToDispose(new SharpDX.Direct3D11.PixelShader(
                deviceResources.D3DDevice,
                pixelShaderByteCode));

            //TODO: Use a photo editing app to create a texture, like GIMP2 with DDS Plugin, make sure photo width & height divisible by 4, for a cube must be an exact square
            //used Gimp 2 with DDS Plugin to create a 2000x2000 image and export at .dds file.
            //in the export options I used BC3_UNorm format, along with automatic MIP levels
            string textureName2 = "Content\\Textures\\nuwaupian_holding_fire3.dds";

            //TODO: Create the SamplerState
            var samplerStateDescription = new SharpDX.Direct3D11.SamplerStateDescription();
            samplerStateDescription.Filter = SharpDX.Direct3D11.Filter.MinMagMipLinear;
            samplerStateDescription.AddressU = SharpDX.Direct3D11.TextureAddressMode.Wrap;
            samplerStateDescription.AddressV = SharpDX.Direct3D11.TextureAddressMode.Wrap;
            samplerStateDescription.AddressW = SharpDX.Direct3D11.TextureAddressMode.Wrap;
            samplerStateDescription.BorderColor = new SharpDX.Mathematics.Interop.RawColor4(0f, 0f, 0f, 1f);

            samplerState = new SharpDX.Direct3D11.SamplerState(deviceResources.D3DDevice, samplerStateDescription);

            //TODO: Use the TextureLoader class to create a bitmap source from a .DDS texture file
            //Retreived TextureLoader from DirectXTK or DirectText Tool
            var bitmapSource2 = TextureLoader.LoadBitmap(new SharpDX.WIC.ImagingFactory2(), textureName2);

            //TODO: Create a Texture Description to describe the texture you'll be using or converting to
            var textDesc = new SharpDX.Direct3D11.Texture2DDescription()
            {
                Width = bitmapSource2.Size.Width,
                Height = bitmapSource2.Size.Height,
                ArraySize = 6,
                BindFlags = SharpDX.Direct3D11.BindFlags.ShaderResource,
                Usage = SharpDX.Direct3D11.ResourceUsage.Default,
                CpuAccessFlags = SharpDX.Direct3D11.CpuAccessFlags.None,
                Format = SharpDX.DXGI.Format.R8G8B8A8_UNorm,
                MipLevels = 1,
                OptionFlags = SharpDX.Direct3D11.ResourceOptionFlags.TextureCube,
                SampleDescription = new SharpDX.DXGI.SampleDescription(1, 0),
            };

            //TODO: Create Shader Resource View 
            var shaderResourceDesc = new SharpDX.Direct3D11.ShaderResourceViewDescription()
            {
                Format = textDesc.Format,
                Dimension = SharpDX.Direct3D.ShaderResourceViewDimension.TextureCube,
                TextureCube = new SharpDX.Direct3D11.ShaderResourceViewDescription.TextureCubeResource() { MipLevels = textDesc.MipLevels, MostDetailedMip = 0 }
            };

            //TODO: Create 6 pointers for the 6 sides of the cube, each pointing to an 2000x2000 image you want to display
            IntPtr[] ptrImages = new IntPtr[6];

            //TODO: Get the Stride of each image - stride is the size of 1 row pixels
            int stride = bitmapSource2.Size.Width * 4;

            //TODO: for each of the 6 pointers, create a buffer to hold the pixels using the DataStream object,
            using (var buffer = new SharpDX.DataStream(bitmapSource2.Size.Height * stride, true, true))
            {
                //TODO: for each of the 6 data streams, copy the pixels into a buffer
                // Copy the content of the WIC to the buffer
                bitmapSource2.CopyPixels(stride, buffer);

                //TODO: for each of the 6 pointers get the IntPtr to the buffers, taking care not get rid of the buffers, pointers, or datastreams before we can create the texture cube
                ptrImages[0] = buffer.DataPointer;


                using (var buffer1 = new SharpDX.DataStream(bitmapSource2.Size.Height * stride, true, true))
                {
                    // Copy the content of the WIC to the buffer
                    bitmapSource2.CopyPixels(stride, buffer1);
                    ptrImages[1] = buffer1.DataPointer;


                    using (var buffer2 = new SharpDX.DataStream(bitmapSource2.Size.Height * stride, true, true))
                    {
                        // Copy the content of the WIC to the buffer
                        bitmapSource2.CopyPixels(stride, buffer2);
                        ptrImages[2] = buffer2.DataPointer;

                        using (var buffer3 = new SharpDX.DataStream(bitmapSource2.Size.Height * stride, true, true))
                        {
                            // Copy the content of the WIC to the buffer
                            bitmapSource2.CopyPixels(stride, buffer3);
                            ptrImages[3] = buffer3.DataPointer;

                            using (var buffer4 = new SharpDX.DataStream(bitmapSource2.Size.Height * stride, true, true))
                            {
                                // Copy the content of the WIC to the buffer
                                bitmapSource2.CopyPixels(stride, buffer4);
                                ptrImages[4] = buffer4.DataPointer;

                                using (var buffer5 = new SharpDX.DataStream(bitmapSource2.Size.Height * stride, true, true))
                                {
                                    // Copy the content of the WIC to the buffer
                                    bitmapSource2.CopyPixels(stride, buffer5);
                                    ptrImages[5] = buffer5.DataPointer;


                                    //TODO: create a DataBox of the 6 pixel buffers. The DataBox is the typed array which we described in the TextureDescription and ShaderResource Description to hold the 6 sides
                                    var dataRects = new SharpDX.DataBox[] { new SharpDX.DataBox(ptrImages[0], stride, 0),
                new SharpDX.DataBox(ptrImages[1], stride, 0),
                new SharpDX.DataBox(ptrImages[2], stride, 0),
                new SharpDX.DataBox(ptrImages[3], stride, 0),
                new SharpDX.DataBox(ptrImages[4], stride, 0),
                new SharpDX.DataBox(ptrImages[5], stride, 0)};

                                    //TODO: Now create the TextureCube 
                                    var texture2D = new SharpDX.Direct3D11.Texture2D(deviceResources.D3DDevice, textDesc, dataRects);

                                    //TODO: Now create the TextureShaderResourceView - which will be used in the PixelShader, after this point we can release all the buffers
                                    textureResource = new SharpDX.Direct3D11.ShaderResourceView(deviceResources.D3DDevice, texture2D, shaderResourceDesc);
                                }
                            }
                        }
                    }
                }
            }

            //TODO: Change to VertexPositionCoordinate
            // Load mesh vertices. Each vertex has a position and a color.
            // Note that the cube size has changed from the default DirectX app
            // template. Windows Holographic is scaled in meters, so to draw the
            // cube at a comfortable size we made the cube width 0.2 m (20 cm).
            VertexPositionCoordinate[] cubeVertices =
            {
                new VertexPositionCoordinate(new Vector3(-0.1f, -0.1f, -0.1f), new Vector3(0.0f, 0.0f, 0.0f)),
                new VertexPositionCoordinate(new Vector3(-0.1f, -0.1f,  0.1f), new Vector3(0.0f, 0.0f, 1.0f)),
                new VertexPositionCoordinate(new Vector3(-0.1f,  0.1f, -0.1f), new Vector3(0.0f, 1.0f, 0.0f)),
                new VertexPositionCoordinate(new Vector3(-0.1f,  0.1f,  0.1f), new Vector3(0.0f, 1.0f, 1.0f)),
                new VertexPositionCoordinate(new Vector3( 0.1f, -0.1f, -0.1f), new Vector3(1.0f, 0.0f, 0.0f)),
                new VertexPositionCoordinate(new Vector3( 0.1f, -0.1f,  0.1f), new Vector3(1.0f, 0.0f, 1.0f)),
                new VertexPositionCoordinate(new Vector3( 0.1f,  0.1f, -0.1f), new Vector3(1.0f, 1.0f, 0.0f)),
                new VertexPositionCoordinate(new Vector3( 0.1f,  0.1f,  0.1f), new Vector3(1.0f, 1.0f, 1.0f)),
            };

            vertexBuffer = this.ToDispose(SharpDX.Direct3D11.Buffer.Create(
                deviceResources.D3DDevice,
                SharpDX.Direct3D11.BindFlags.VertexBuffer,
                cubeVertices));

            // Load mesh indices. Each trio of indices represents
            // a triangle to be rendered on the screen.
            // For example: 0,2,1 means that the vertices with indexes
            // 0, 2 and 1 from the vertex buffer compose the 
            // first triangle of this mesh.
            ushort[] cubeIndices =
            {
                2,1,0, // -x
                2,3,1,

                6,4,5, // +x
                6,5,7,

                0,1,5, // -y
                0,5,4,

                2,6,7, // +y
                2,7,3,

                0,4,6, // -z
                0,6,2,

                1,3,7, // +z
                1,7,5,
            };

            indexCount = cubeIndices.Length;

            indexBuffer = this.ToDispose(SharpDX.Direct3D11.Buffer.Create(
                deviceResources.D3DDevice,
                SharpDX.Direct3D11.BindFlags.IndexBuffer,
                cubeIndices));

            // Create a constant buffer to store the model matrix.
            modelConstantBuffer = this.ToDispose(SharpDX.Direct3D11.Buffer.Create(
                deviceResources.D3DDevice,
                SharpDX.Direct3D11.BindFlags.ConstantBuffer,
                ref modelConstantBufferData));

            // Once the cube is loaded, the object is ready to be rendered.
            loadingComplete = true;
        }

        /// <summary>
        /// Releases device-based resources.
        /// </summary>
        public void ReleaseDeviceDependentResources()
        {
            loadingComplete = false;
            usingVprtShaders = false;
            this.RemoveAndDispose(ref vertexShader);
            this.RemoveAndDispose(ref inputLayout);
            this.RemoveAndDispose(ref pixelShader);
            this.RemoveAndDispose(ref geometryShader);
            this.RemoveAndDispose(ref modelConstantBuffer);
            this.RemoveAndDispose(ref vertexBuffer);
            this.RemoveAndDispose(ref indexBuffer);

            //TODO: Release the Sampler and ColorResource
            this.RemoveAndDispose(ref samplerState);
            this.RemoveAndDispose(ref textureResource);

        }

        public Vector3 Position
        {
            get { return position; }
            set { position = value; }
        }
    }
}
