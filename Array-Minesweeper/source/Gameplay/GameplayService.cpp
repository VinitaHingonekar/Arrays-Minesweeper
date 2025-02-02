#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Global/ServiceLocator.h"

using namespace Global;

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{

	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update()
	{

	}

	void GameplayService::render()
	{

	}

	void GameplayService::startGame()
	{
		gameplay_controller->reset();
	}

	float GameplayService::getRemainingTime()
	{
		return gameplay_controller->getRemainingTime();
	}

	int GameplayService::getMinesCount()
	{
		//return gameplay_controller->getMinesCount();
		return 11;
	}

	// This is part of the Gameplay Service layer that interacts with the GameplayController.
	void GameplayService::endGame(GameResult result)
	{
		// This function forwards the result of the game to the controller's endGame function.
		gameplay_controller->endGame(result); // Trigger the endGame logic in the controller.
	}
}