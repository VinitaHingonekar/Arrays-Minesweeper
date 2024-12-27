#pragma once
//#include "BoardView.h"
#include "../Cell/CellController.h"
#include "../../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Board
	{
		class BoardView;

		class BoardController
		{
		public:

			static const int number_of_rows = 9;
			static const int number_of_columns = 9;

			static const int mines_count = 8;

			int flagged_cells;


			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();
			void reset();
			
			int getMinesCount();

			void openCell(sf::Vector2i cell_position);
			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
			void flagCell(sf::Vector2i cell_position);


		private:
			BoardView* board_view;
			Cell::CellController* board[number_of_rows][number_of_columns];

			void createBoard();
			void initializeCells();
			void destroy();
			void resetBoard();
			void deleteBoard();

		};
	}
}