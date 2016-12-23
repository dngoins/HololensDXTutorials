#include "Game.h"
#include "GameException.h"

namespace Library
{
	const UINT Game::DefaultScreenWidth = 1024;
	const UINT Game::DefaultScreenHeight = 768;
	const UINT Game::DefaultFrameRate = 60;
	const UINT Game::DefaultMultiSamplingCount = 4;

	Game::Game(HINSTANCE instance, const std::wstring& windowClass,
		const std::wstring& windowTitle, int showCommand)
		: mInstance(instance), mWindowClass(windowClass),
		mWindowTitle(windowTitle), mShowCommand(showCommand),
		mWindowHandle(), mWindow(),
		mScreenWidth(DefaultScreenWidth), mScreenHeight(DefaultScreen
			Height),
		mGameClock(), mGameTime(),
		mFeatureLevel(D3D_FEATURE_LEVEL_9_1),
		mDirect3DDevice(nullptr),
		mDirect3DDeviceContext(nullptr), mSwapChain(nullptr),
		mFrameRate(DefaultFrameRate), mIsFullScreen(false),
		mDepthStencilBufferEnabled(false),
		mMultiSamplingEnabled(false),
		mMultiSamplingCount(DefaultMultiSamplingCount),
		mMultiSamplingQualityLevels(0),
		mDepthStencilBuffer(nullptr), mRenderTargetView(nullptr),
		mDepthStencilView(nullptr), mViewport()
	{
	}

	void Game::Run()
	{
		InitializeWindow();
		InitializeDirectX();
		Initialize();

		MSG message;
		ZeroMemory(&message, sizeof(message));

		mGameClock.Reset();

		while (message.message != WM_QUIT)
		{
			if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			else
			{
				mGameClock.UpdateGameTime(mGameTime);
				Update(mGameTime);
				Draw(mGameTime);
			}
		}

		Shutdown();
	}

	void Game::Shutdown()
	{
		ReleaseObject(mRenderTargetView);
		ReleaseObject(mDepthStencilView);
		ReleaseObject(mSwapChain);
		ReleaseObject(mDepthStencilBuffer);

		if (mDirect3DDeviceContext != nullptr)
		{
			mDirect3DDeviceContext->ClearState();
		}

		ReleaseObject(mDirect3DDeviceContext);
		ReleaseObject(mDirect3DDevice);

		UnregisterClass(mWindowClass.c_str(), mWindow.hInstance);
	}

	void Game::InitializeDirectX()
	{
		HRESULT hr;
		UINT createDeviceFlags = 0;

#if defined(DEBUG) || defined(_DEBUG)
		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		D3D_FEATURE_LEVEL featureLevels[] = {
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0
		};

		// Step 1: Create the Direct3D device and device context
		interfaces
			ID3D11Device* direct3DDevice = nullptr;
		ID3D11DeviceContext* direct3DDeviceContext = nullptr;
		if (FAILED(hr = D3D11CreateDevice(NULL, D3D_DRIVER_
			TYPE_HARDWARE, NULL, createDeviceFlags, featureLevels,
			ARRAYSIZE(featureLevels), D3D11_SDK_VERSION, &direct3DDevice,
			&mFeatureLevel, &direct3DDeviceContext)))
		{
			throw GameException("D3D11CreateDevice() failed", hr);
		}

		if (FAILED(hr = direct3DDevice->QueryInterface(__
			uuidof(ID3D11Device1), reinterpret_cast<void**>(&mDirect3DDevice))))
		{
			throw GameException("ID3D11Device::QueryInterface()
				failed", hr);
		}

		if (FAILED(hr = direct3DDeviceContext->QueryInterface
		(__uuidof(ID3D11DeviceContext1), reinterpret_cast<void**>
			(&mDirect3DDeviceContext))))
		{
			throw GameException("ID3D11Device::QueryInterface()
				failed", hr);
		}

		ReleaseObject(direct3DDevice);
		ReleaseObject(direct3DDeviceContext);

		// Step 2: Check for multisampling support
		mDirect3DDevice->CheckMultisampleQualityLevels(DXGI_FORMAT_
			R8G8B8A8_UNORM, mMultiSamplingCount, &mMultiSamplingQualityLevels);
		if (mMultiSamplingQualityLevels == 0)
		{
			throw GameException("Unsupported multi-sampling quality");
		}

		DXGI_SWAP_CHAIN_DESC1 swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
		swapChainDesc.Width = mScreenWidth;
		swapChainDesc.Height = mScreenHeight;
		swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

		if (mMultiSamplingEnabled)
		{
			swapChainDesc.SampleDesc.Count = mMultiSamplingCount;
			swapChainDesc.SampleDesc.Quality =
				mMultiSamplingQualityLevels - 1;
		}
		else
		{
			swapChainDesc.SampleDesc.Count = 1;
			swapChainDesc.SampleDesc.Quality = 0;
		}

		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 1;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		// Step 3: Create the swap chain
		IDXGIDevice* dxgiDevice = nullptr;
		if (FAILED(hr = mDirect3DDevice->QueryInterface(__
			uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgiDevice))))
		{
			throw GameException("ID3D11Device::QueryInterface()
				failed", hr);
		}

		IDXGIAdapter *dxgiAdapter = nullptr;
		if (FAILED(hr = dxgiDevice->GetParent(__uuidof(IDXGIAdapter),
			reinterpret_cast<void**>(&dxgiAdapter))))
		{
			ReleaseObject(dxgiDevice);
			throw GameException("IDXGIDevice::GetParent() failed
				retrieving adapter.", hr);
		}

		IDXGIFactory2* dxgiFactory = nullptr;
		if (FAILED(hr = dxgiAdapter->GetParent(__uuidof(IDXGIFactory2),
			reinterpret_cast<void**>(&dxgiFactory))))
		{
			ReleaseObject(dxgiDevice);
			ReleaseObject(dxgiAdapter);
			throw GameException("IDXGIAdapter::GetParent() failed
				retrieving factory.", hr);
		}

		DXGI_SWAP_CHAIN_FULLSCREEN_DESC fullScreenDesc;
		ZeroMemory(&fullScreenDesc, sizeof(fullScreenDesc));
		fullScreenDesc.RefreshRate.Numerator = mFrameRate;
		fullScreenDesc.RefreshRate.Denominator = 1;
		fullScreenDesc.Windowed = !mIsFullScreen;

		if (FAILED(hr = dxgiFactory->CreateSwapChainForHwnd(dxgiDevice,
			mWindowHandle, &swapChainDesc, &fullScreenDesc, nullptr, &mSwapChain)))
		{
			ReleaseObject(dxgiDevice);
			ReleaseObject(dxgiAdapter);
			ReleaseObject(dxgiFactory);
			throw GameException("IDXGIDevice::CreateSwapChainForHwnd()
				failed.", hr);
		}

		ReleaseObject(dxgiDevice);
		ReleaseObject(dxgiAdapter);
		ReleaseObject(dxgiFactory);

		// Step 4: Create the render target view
		ID3D11Texture2D* backBuffer;
		if (FAILED(hr = mSwapChain->GetBuffer(0, __
			uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer))))
		{
			throw GameException("IDXGISwapChain::GetBuffer() failed.", hr);
		}

		backBuffer->GetDesc(&mBackBufferDesc);

		if (FAILED(hr = mDirect3DDevice->CreateRenderTargetView
		(backBuffer, nullptr, &mRenderTargetView)))
		{
			ReleaseObject(backBuffer);
			throw GameException("IDXGIDevice::CreateRenderTargetView()
				failed.", hr);
		}

		ReleaseObject(backBuffer);

		// Step 5: Create the depth-stencil view
		if (mDepthStencilBufferEnabled)
		{
			D3D11_TEXTURE2D_DESC depthStencilDesc;
			ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));
			depthStencilDesc.Width = mScreenWidth;
			depthStencilDesc.Height = mScreenHeight;
			depthStencilDesc.MipLevels = 1;
			depthStencilDesc.ArraySize = 1;
			depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
			depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
			depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;

			if (mMultiSamplingEnabled)
			{
				depthStencilDesc.SampleDesc.Count =
					mMultiSamplingCount;
				depthStencilDesc.SampleDesc.Quality =
					mMultiSamplingQualityLevels - 1;
			}
			else
			{
				depthStencilDesc.SampleDesc.Count = 1;
				depthStencilDesc.SampleDesc.Quality = 0;
			}

			if (FAILED(hr = mDirect3DDevice->CreateTexture2D
			(&depthStencilDesc, nullptr, &mDepthStencilBuffer)))
			{
				throw GameException("IDXGIDevice::CreateTexture2D()
					failed.", hr);
			}

			if (FAILED(hr = mDirect3DDevice->CreateDepthStencilView
			(mDepthStencilBuffer, nullptr, &mDepthStencilView)))
			{
				throw GameException("IDXGIDevice::CreateDepthStencilView()
					failed.", hr);
			}
		}

		// Step 6: Bind the render target and depth-stencil views to OM
		stage
			mDirect3DDeviceContext->OMSetRenderTargets(1,
				&mRenderTargetView, mDepthStencilView);

		mViewport.TopLeftX = 0.0f;
		mViewport.TopLeftY = 0.0f;
		mViewport.Width = static_cast<float>(mScreenWidth);
		mViewport.Height = static_cast<float>(mScreenHeight);
		mViewport.MinDepth = 0.0f;
		mViewport.MaxDepth = 1.0f;

		// Step 7: Set the viewport
		mDirect3DDeviceContext->RSSetViewports(1, &mViewport);
	}

	void Game::Initialize()
	{
		for (GameComponent* component : mComponents)
		{
			component->Initialize();
		}
	}

	void Game::Update(const GameTime& gameTime)
	{
		for (GameComponent* component : mComponents)
		{
			if (component->Enabled())
			{
				component->Update(gameTime);
			}
		}
	}

	void Game::Draw(const GameTime& gameTime)
	{
		for (GameComponent* component : mComponents)
		{
			DrawableGameComponent* drawableGameComponent =
				component->As<DrawableGameComponent>();
			if (drawableGameComponent != nullptr &&
				drawableGameComponent->Visible())
			{
				drawableGameComponent->Draw(gameTime);
			}
		}
	}