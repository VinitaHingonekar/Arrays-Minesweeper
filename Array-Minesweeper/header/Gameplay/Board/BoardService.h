#pragma once
#include "../../../header/Gameplay/Board/BoardController.h"
#include "../../../header/Gameplay/Cell/CellController.h"

namespace Gameplay
{
	namespace Board
	{
		enum class ButtonType;

		class BoardService
		{
		private:
			Board::BoardController* board_controller;

			void destroy();

		public:
			BoardService();
			~BoardService();
			void initialize();
			void update();
			void render();

			void resetBoard();
			void showBoard();

			void setBoardState(BoardState COMPLETED);
			BoardState getBoardState();

			int getMinesCount();
			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);

			//void flagAllMines();
		};
	}
}