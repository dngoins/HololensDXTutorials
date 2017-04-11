#pragma once

#include "GameComponent.h"

namespace Library
{
    class GameTime;

    enum class MouseButtons
    {
        Left = 0,
        Right = 1,
        Middle = 2,
        X1 = 3
    };

    class Mouse : public GameComponent
    {
        RTTI_DECLARATIONS(Mouse, GameComponent)

    public:
        Mouse(Game& game, LPDIRECTINPUT8 directInput);
        ~Mouse();

		Mouse() = delete;

        LPDIMOUSESTATE CurrentState();
        LPDIMOUSESTATE LastState();

        virtual void Initialize() override;
        virtual void Update(const GameTime& gameTime) override;
        
        long X() const;
        long Y() const;
        long Wheel() const;

        bool IsButtonUp(MouseButtons button) const;
        bool IsButtonDown(MouseButtons button) const;		
        bool WasButtonUp(MouseButtons button) const;
        bool WasButtonDown(MouseButtons button) const;	
        bool WasButtonPressedThisFrame(MouseButtons button) const;
        bool WasButtonReleasedThisFrame(MouseButtons button) const;
        bool IsButtonHeldDown(MouseButtons button) const;

    private:
        LPDIRECTINPUT8 mDirectInput;
        LPDIRECTINPUTDEVICE8 mDevice;
        DIMOUSESTATE mCurrentState;
        DIMOUSESTATE mLastState;

        long mX;
        long mY;
        long mWheel;
    };
}