#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

using namespace Global;

namespace Gameplay
{

	GameplayController::GameplayController()
	{

	}

	GameplayController::~GameplayController()
	{

	}

	void GameplayController::initialize()
	{

	}

	void GameplayController::update()
	{

	}

	void GameplayController::render()
	{

	}

	void GameplayController::reset()
	{
		ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}

}