#pragma once
//#include "BoardView.h"
#include "../Cell/CellController.h"

namespace Gameplay
{
	namespace Board
	{
		class BoardView;

		class BoardController
		{
		private:
			void createBoard();
			void destroy();
			void deleteBoard();

			BoardView* board_view;
			Gameplay::Cell::CellController* cell;

		public:

			static const int number_of_rows = 9;
			static const int number_of_columns = 9;
			static const int mines_count = 8;


			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();
			void reset();

			void initializeCells();

			Gameplay::Cell::CellController* cells[number_of_columns];
		};
	}
}