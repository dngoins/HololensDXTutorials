﻿using System;
using System.Threading.Tasks;
using Windows.ApplicationModel;
using Windows.ApplicationModel.Activation;
using Windows.ApplicationModel.Core;
using Windows.Graphics.Holographic;
using Windows.UI.Core;
using TexturedCubeSample.Common;

namespace TexturedCubeSample
{
    /// <summary>
    /// The IFrameworkView connects the app with Windows and handles application lifecycle events.
    /// </summary>
    internal class AppView : IFrameworkView, IDisposable
    {
        private TexturedCubeSampleMain main;

        private DeviceResources         deviceResources;
        private bool                    windowClosed        = false;
        private bool                    windowVisible       = true;

        // The holographic space the app will use for rendering.
        private HolographicSpace        holographicSpace    = null;

        public AppView()
        {
            windowVisible = true;
        }

        public void Dispose()
        {
            if (deviceResources != null)
            {
                deviceResources.Dispose();
                deviceResources = null;
            }

            if (main != null)
            {
                main.Dispose();
                main = null;
            }
        }

        #region IFrameworkView Members

        /// <summary>
        /// The first method called when the IFrameworkView is being created.
        /// Use this method to subscribe for Windows shell events and to initialize your app.
        /// </summary>
        public void Initialize(CoreApplicationView applicationView)
        {
            applicationView.Activated += this.OnViewActivated;

            // Register event handlers for app lifecycle.
            CoreApplication.Suspending += this.OnSuspending;
            CoreApplication.Resuming += this.OnResuming;

            // At this point we have access to the device and we can create device-dependent
            // resources.
            deviceResources = new DeviceResources();

            main = new TexturedCubeSampleMain(deviceResources);
        }

        /// <summary>
        /// Called when the CoreWindow object is created (or re-created).
        /// </summary>
        public void SetWindow(CoreWindow window)
        {
            // Register for keypress notifications.
            window.KeyDown += this.OnKeyPressed;

            // Register for notification that the app window is being closed.
            window.Closed += this.OnWindowClosed;

            // Register for notifications that the app window is losing focus.
            window.VisibilityChanged += this.OnVisibilityChanged;

            // Create a holographic space for the core window for the current view.
            // Presenting holographic frames that are created by this holographic space will put
            // the app into exclusive mode.
            holographicSpace = HolographicSpace.CreateForCoreWindow(window);

            // The DeviceResources class uses the preferred DXGI adapter ID from the holographic
            // space (when available) to create a Direct3D device. The HolographicSpace
            // uses this ID3D11Device to create and manage device-based resources such as
            // swap chains.
            deviceResources.SetHolographicSpace(holographicSpace);

            // The main class uses the holographic space for updates and rendering.
            main.SetHolographicSpace(holographicSpace);
        }


        /// <summary>
        /// The Load method can be used to initialize scene resources or to load a
        /// previously saved app state.
        /// </summary>
        public void Load(string entryPoint)
        {
        }

        /// <summary>
        /// This method is called after the window becomes active. It oversees the
        /// update, draw, and present loop, and also oversees window message processing.
        /// </summary>
        public void Run()
        {
            while (!windowClosed)
            {
                if (windowVisible && (null != holographicSpace))
                {
                    CoreWindow.GetForCurrentThread().Dispatcher.ProcessEvents(CoreProcessEventsOption.ProcessAllIfPresent);
                    
                    HolographicFrame frame = main.Update();

                    if (main.Render(ref frame))
                    {
                        deviceResources.Present(ref frame);
                    }
                }
                else
                {
                    CoreWindow.GetForCurrentThread().Dispatcher.ProcessEvents(CoreProcessEventsOption.ProcessOneAndAllPending);
                }
            }
        }

        /// <summary>
        /// Terminate events do not cause Uninitialize to be called. It will be called if your IFrameworkView
        /// class is torn down while the app is in the foreground.
        // This method is not often used, but IFrameworkView requires it and it will be called for
        // holographic apps.
        /// </summary>
        public void Uninitialize()
        {
        }

        #endregion

        #region Application lifecycle event handlers

        /// <summary>
        /// Called when the app view is activated. Activates the app's CoreWindow.
        /// </summary>
        private void OnViewActivated(CoreApplicationView sender, IActivatedEventArgs args)
        {
            // Run() won't start until the CoreWindow is activated.
            sender.CoreWindow.Activate();
        }

        private void OnSuspending(object sender, SuspendingEventArgs args)
        {
            // Save app state asynchronously after requesting a deferral. Holding a deferral
            // indicates that the application is busy performing suspending operations. Be
            // aware that a deferral may not be held indefinitely; after about five seconds,
            // the app will be forced to exit.
            var deferral = args.SuspendingOperation.GetDeferral();

            Task.Run(() =>
                {
                    deviceResources.Trim();

                    if (null != main)
                    {
                        main.SaveAppState();
                    }

                    //
                    // TODO: Insert code here to save your app state.
                    //

                    deferral.Complete();
                });
        }

        private void OnResuming(object sender, object args)
        {
            // Restore any data or state that was unloaded on suspend. By default, data
            // and state are persisted when resuming from suspend. Note that this event
            // does not occur if the app was previously terminated.

            if (null != main)
            {
                main.LoadAppState();
            }

            //
            // TODO: Insert code here to load your app state.
            //
        }

        #endregion;

        #region Window event handlers

        private void OnVisibilityChanged(CoreWindow sender, VisibilityChangedEventArgs args)
        {
            windowVisible = args.Visible;
        }

        private void OnWindowClosed(CoreWindow sender, CoreWindowEventArgs arg)
        {
            windowClosed = true;
        }

        #endregion

        #region Input event handlers

        private void OnKeyPressed(CoreWindow sender, KeyEventArgs args)
        {
            //
            // TODO: Bluetooth keyboards are supported by HoloLens. You can use this method for
            //       keyboard input if you want to support it as an optional input method for
            //       your holographic app.
            //
        }

        #endregion
    }
}
