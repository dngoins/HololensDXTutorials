#pragma once

namespace MatMeshModLibrary
{
	class GameTime
	{
	public:
		GameTime(double totalGameTime = 0.0, double elapsedGameTime = 0.0);

		double TotalGameTime() const;
		void SetTotalGameTime(double totalGameTime);

		double ElapsedGameTime() const;
		void SetElapsedGameTime(double elapsedGameTime);

	private:
		double mTotalGameTime;
		double mElapsedGameTime;
	};
}
