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
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					board[a][b] = new CellController(sf::Vector2i(a, b));
				}
			}
		}

		void BoardController::destroy()
		{
			delete(board_view);
			deleteBoard();
		}

		void BoardController::deleteBoard()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					delete board[a][b];
				}
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
			for (int row = 0; row < number_of_rows; ++row)
			{
				for (int col = 0; col < number_of_columns; ++col)
				{
					board[row][col]->update();
				}
			}
		}

		void BoardController::render()
		{
			board_view->render();
			for (int row = 0; row < number_of_rows; ++row)
			{
				for (int col = 0; col < number_of_columns; ++col)
				{
					board[row][col]->render();
				}
			}
		}

		void BoardController::reset()
		{
			resetBoard();
		}

		void BoardController::resetBoard()
		{
			for (int row = 0; row < number_of_rows; ++row)
			{
				for (int col = 0; col < number_of_columns; ++col)
				{
					board[row][col]->reset();
				}
			}
		}

		void BoardController::initializeCells()
		{
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();

			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					board[a][b]->initialize(cell_width, cell_height);
				}
			}
		}

	}
}