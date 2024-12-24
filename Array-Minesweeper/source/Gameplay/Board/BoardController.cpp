#include "../../../header/Gameplay/Board/BoardController.h"
#include "../../../header/Gameplay/Board/BoardView.h"
#include "../../../header/Gameplay/Cell/CellController.h"

using namespace Gameplay::Cell;

namespace Gameplay
{
	namespace Board
	{
		BoardController::BoardController()
		{
			board_view = new BoardView(this);
			createBoard();
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::createBoard()
		{
			cell = new Gameplay::Cell::CellController();
		}

		void BoardController::destroy()
		{
			delete(board_view);
			deleteBoard();
		}

		void BoardController::deleteBoard()
		{
			delete(cell);
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			cell->initialize();
		}

		void BoardController::update()
		{
			board_view->update();
			cell->update();
		}

		void BoardController::render()
		{
			board_view->render();
			cell->render();
		}

		void BoardController::reset()
		{
			cell->reset();
		}

	}
}