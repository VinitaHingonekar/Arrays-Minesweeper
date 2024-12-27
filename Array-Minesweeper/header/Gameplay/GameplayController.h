#pragma once

namespace Gameplay
{
	class GameplayController
	{
	private:
		float remaining_time;
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();
		void reset();

		void updateRemainingTime();
		float getRemainingTime();

		int getMinesCount();
	};
}