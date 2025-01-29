#include "../../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		enum class BoardState;

		BoardService::BoardService()
		{
			board_controller = nullptr;
		}

		BoardService::~BoardService()
		{
			destroy();
		}

		void BoardService::initialize()
		{
			board_controller = new BoardController();
			board_controller->initialize();
		}

		void BoardService::update()
		{
			board_controller->update();
		}

		void BoardService::render()
		{
			board_controller->render();
		}

		void BoardService::destroy()
		{
			delete(board_controller);
		}

		void BoardService::resetBoard()
		{
			board_controller->reset();
		}

		void BoardService::showBoard()
		{
			board_controller->showBoard();
		}

		BoardState BoardService::getBoardState()
		{
			return board_controller->getBoardState();
		}

		void BoardService::setBoardState(BoardState state)
		{
			board_controller->setBoardState(state);
		}

		int BoardService::getMinesCount()
		{
			return board_controller->getMinesCount();
		}

		void BoardService::processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type)
		{
			board_controller->processCellInput(cell_controller, button_type);
		}

		void BoardService::flagAllMines()
		{
			board_controller->flagAllMines();
		}
	}
}