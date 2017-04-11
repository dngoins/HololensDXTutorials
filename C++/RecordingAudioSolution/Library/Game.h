#pragma once

#include "Common.h"
#include "GameClock.h"
#include "GameTime.h"
#include "GameComponent.h"
#include "ServiceContainer.h"
#include "RenderTarget.h"

namespace Library
{
    class Game : public RenderTarget
    {
		RTTI_DECLARATIONS(Game, RenderTarget)

    public:
        Game(HINSTANCE instance, const std::wstring& windowClass, const std::wstring& windowTitle, int showCommand);
        virtual ~Game();

		Game(const Game& rhs) = delete;
		Game& operator=(const Game& rhs) = delete;

        HINSTANCE Instance() const;
        HWND WindowHandle() const;
        const WNDCLASSEX& Window() const; 
        const std::wstring& WindowClass() const;
        const std::wstring& WindowTitle() const;
        int ScreenWidth() const;
        int ScreenHeight() const;

        ID3D11Device1* Direct3DDevice() const;
        ID3D11DeviceContext1* Direct3DDeviceContext() const;
        bool DepthStencilBufferEnabled() const;
		ID3D11RenderTargetView* RenderTargetView() const;
		ID3D11DepthStencilView* DepthStencilView() const;
        float AspectRatio() const;
        bool IsFullScreen() const;
        const D3D11_TEXTURE2D_DESC& BackBufferDesc() const;
        const D3D11_VIEWPORT& Viewport() const;
		bool MultiSamplingEnabled() const;
		UINT MultiSamplingCount() const;
		UINT MultiSamplingQualityLevels() const;

		const std::vector<GameComponent*>& Components() const;
		const ServiceContainer& Services() const;

        virtual void Run();
        virtual void Exit();
        virtual void Initialize();		
        virtual void Update(const GameTime& gameTime);
        virtual void Draw(const GameTime& gameTime);

		virtual void ResetRenderTargets();
		virtual void UnbindPixelShaderResources(UINT startSlot, UINT count);

    protected:
		virtual void Begin() override;
		virtual void End() override;
        virtual void InitializeWindow();
		virtual void InitializeDirectX();
		virtual void Shutdown();

        static const UINT DefaultScreenWidth;
        static const UINT DefaultScreenHeight;
		static const UINT DefaultFrameRate;
        static const UINT DefaultMultiSamplingCount;

        HINSTANCE mInstance;
        std::wstring mWindowClass;
        std::wstring mWindowTitle;
        int mShowCommand;
        
        HWND mWindowHandle;
        WNDCLASSEX mWindow;

        UINT mScreenWidth;
        UINT mScreenHeight;

        GameClock mGameClock;
        GameTime mGameTime;
		std::vector<GameComponent*> mComponents;
		ServiceContainer mServices;

        D3D_FEATURE_LEVEL mFeatureLevel;
        ID3D11Device1* mDirect3DDevice;
        ID3D11DeviceContext1* mDirect3DDeviceContext;
        IDXGISwapChain1* mSwapChain;

        UINT mFrameRate;
        bool mIsFullScreen;
        bool mDepthStencilBufferEnabled;
        bool mMultiSamplingEnabled;
        UINT mMultiSamplingCount;
        UINT mMultiSamplingQualityLevels;

        ID3D11Texture2D* mDepthStencilBuffer;
        D3D11_TEXTURE2D_DESC mBackBufferDesc;
        ID3D11RenderTargetView* mRenderTargetView;
        ID3D11DepthStencilView* mDepthStencilView;
        D3D11_VIEWPORT mViewport;

    private:
        POINT CenterWindow(int windowWidth, int windowHeight);
        static LRESULT WINAPI WndProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);		
    };
}