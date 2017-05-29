#pragma once

#include <windows.h>
#include <exception>

namespace MatMeshModLibrary
{
    class GameTime;

    class GameClock
    {
    public:
        GameClock();

		GameClock(const GameClock& rhs) = delete;
		GameClock& operator=(const GameClock& rhs) = delete;

        const LARGE_INTEGER& StartTime() const;
        const LARGE_INTEGER& CurrentTime() const;
        const LARGE_INTEGER& LastTime() const;

        void Reset();
        double GetFrequency() const;
        void GetTime(LARGE_INTEGER& time) const;
        void UpdateGameTime(GameTime& gameTime);

    private:
        LARGE_INTEGER mStartTime;
        LARGE_INTEGER mCurrentTime;
        LARGE_INTEGER mLastTime;
        double mFrequency;
    };
}
