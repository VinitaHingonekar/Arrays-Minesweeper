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
			//cell = new Gameplay::Cell::CellController();
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i] = new CellController(i); //Passing Cell Index in Cell Controller's constructor
			}
		}

		void BoardController::destroy()
		{
			delete(board_view);
			deleteBoard();
		}

		void BoardController::deleteBoard()
		{
			for (int i = 0; i < number_of_columns; i++)
			{
				delete(cells[i]);
			}
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			initializeCells();
		}

		void BoardController::update()
		{
			board_view->update();
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->update();
			}
		}

		void BoardController::render()
		{
			board_view->render();
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->render();
			}
		}

		void BoardController::reset()
		{
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->reset();
			}
		}

		void BoardController::initializeCells()
		{
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();

			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->initialize(cell_width, cell_height);
			}
		}

	}
}