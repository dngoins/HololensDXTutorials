#pragma once

#include <pch.h>
#include <windows.h>
#include <string>
#include "GameClock.h"
#include "GameTime.h"

namespace Library
{
	class Game
	{
	public:
		Game(HINSTANCE instance, const std::wstring& windowClass, const
			std::wstring& windowTitle, int showCommand);
		virtual ~Game();

		HINSTANCE Instance() const;
		HWND WindowHandle() const;
		const WNDCLASSEX& Window() const;
		const std::wstring& WindowClass() const;
		const std::wstring& WindowTitle() const;
		int ScreenWidth() const;
		int ScreenHeight() const;

		virtual void Run();
		virtual void Exit();
		virtual void Initialize();
		virtual void Update(const GameTime& gameTime);
		virtual void Draw(const GameTime& gameTime);

		const std::vector<GameComponent*>& Components() const;


	protected:
		virtual void InitializeWindow();
		virtual void Shutdown();
		std::vector<GameComponent*> mComponents;

		static const UINT DefaultScreenWidth;
		static const UINT DefaultScreenHeight;

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

	private:
		Game(const Game& rhs);
		Game& operator=(const Game& rhs);

		POINT CenterWindow(int windowWidth, int windowHeight);
		static LRESULT WINAPI WndProc(HWND windowHandle, UINT message,
			WPARAM, LPARAM lParam);
	};
}