#include "../../../header/Gameplay/Cell/CellController.h"
#include "../../../header/Gameplay/Cell/CellView.h"
#include "../../../header/Gameplay/Cell/CellModel.h"
#include "../../../header/Global/ServiceLocator.h"
#include "../../../header/Sound/SoundService.h"

using namespace Global;
using namespace Sound;

namespace Gameplay
{
	namespace Cell
	{
		CellController::CellController(Vector2i position)
		{
			cell_model = new CellModel(position);
			cell_view = new CellView(this);
		}

		CellController::~CellController()
		{
			destroy();
		}

		void CellController::initialize(float cell_width, float cell_height)
		{
			cell_view->initialize(cell_width, cell_height);
		}

		void CellController::render()
		{
			cell_view->render();
		}

		void CellController::update()
		{
			cell_view->update();
		}

		void CellController::destroy()
		{
			delete(cell_view);
			delete (cell_model);
		}

		void CellController::reset()
		{
			cell_model->reset();
		}

		Vector2i CellController::getCellPosition()
		{
			return cell_model->position;
		}

		CellState CellController::getCellState()
		{
			return cell_model->getCellState();
		}

		CellValue CellController::getCellValue()
		{
			return cell_model->getCellValue();
		}

		void CellController::openCell()
		{
			if (cell_model->getCellState() != CellState::FLAGGED)
			{
				cell_model->setCellState(CellState::OPEN);
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			}
		}

		void CellController::flagCell()
		{
			switch (cell_model->getCellState())
			{
			case::Gameplay::Cell::CellState::FLAGGED:
				cell_model->setCellState(CellState::HIDDEN);
				break;
			case::Gameplay::Cell::CellState::HIDDEN:
				cell_model->setCellState(CellState::FLAGGED);
				break;
			}

			//ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::FLAG);
		}

	}
}