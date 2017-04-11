#include "GameTime.h"

namespace Library
{
	GameTime::GameTime(double totalGameTime, double elapsedGameTime)
		: mTotalGameTime(totalGameTime), mElapsedGameTime(elapsedGameTime)
	{
	}

	double GameTime::TotalGameTime() const
	{
		return mTotalGameTime;
	}

	void GameTime::SetTotalGameTime(double totalGameTime)
	{
		mTotalGameTime = totalGameTime;
	}

	double GameTime::ElapsedGameTime() const
	{
		return mElapsedGameTime;
	}

	void GameTime::SetElapsedGameTime(double elapsedGameTime)
	{
		mElapsedGameTime = elapsedGameTime;
	}
}