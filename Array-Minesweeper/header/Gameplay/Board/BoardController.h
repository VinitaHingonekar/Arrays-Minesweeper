#pragma once
//#include "BoardView.h"
#include "../Cell/CellController.h"
#include "../../../header/UI/UIElement/ButtonView.h"
#include <random>

namespace Gameplay
{
	namespace Board
	{
		class BoardView;

		class BoardController
		{
		public:

			enum class BoardState
			{
				FIRST_CELL,       // The state when the player opens first cell.
				PLAYING,          // The game is in progress.
				COMPLETED,    // The game is over.
			};

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

			void populateBoard(sf::Vector2i cell_position);
			void populateMines(sf::Vector2i cell_position);

			BoardState board_state;
			BoardState getBoardState();
			void setBoardState(BoardState state);

			// To generate random values.
			std::default_random_engine random_engine;

			// To give random seed to generator.
			std::random_device random_device;

			bool isValidCellPosition(sf::Vector2i cell_position);
			int countMinesAround(sf::Vector2i cell_position);

			void populateCells();

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