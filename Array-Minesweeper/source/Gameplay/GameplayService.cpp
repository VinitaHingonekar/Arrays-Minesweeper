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
}