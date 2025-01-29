#pragma once
#include "../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	using namespace Gameplay::Board;

	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayController
	{
	private:
		const float max_level_duration = 301.0f;
		const float game_over_time = 11.f;
		float remaining_time;

		Board::BoardService* board_service;
		GameResult game_result;

		void updateRemainingTime();
		void beginGameOverTimer();

		void showCredits();
		void gameLost();
		void gameWon();

	public:
		//GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();
		void reset();

		int getMinesCount();
		float getRemainingTime();

		void endGame(Gameplay::GameResult result);

	};
}