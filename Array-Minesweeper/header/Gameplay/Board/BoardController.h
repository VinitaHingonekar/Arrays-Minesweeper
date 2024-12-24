#pragma once
#include "BoardView.h"

namespace Gameplay
{
	namespace Board
	{
		class BoardController
		{
		private:
			void createBoard();
			void destroy();
			void deleteBoard();

			BoardView* board_view;

		public:

			static const int number_of_rows = 9;
			static const int number_of_colums = 9;
			static const int mines_count = 8;

			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();
			void reset();
		};
	}
}