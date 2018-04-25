using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using WinRT_AudioRecording;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace TestingAudioWinRtComponent
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        Utility microhpone;

        public MainPage()
        {
            this.InitializeComponent();
            microhpone = new Utility("Test.mp3");    
        }

        private void StartRecording_Click(object sender, RoutedEventArgs e)
        {
            microhpone.StartCapture();
        }

        private void StopRecording_Click(object sender, RoutedEventArgs e)
        {
            microhpone.StopCapture();
        }
    }
}
