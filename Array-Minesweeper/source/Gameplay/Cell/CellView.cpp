#include "../../../header/Gameplay/Cell/CellView.h"
#include "../../../header/Global/Config.h"

using namespace UI::UIElement;
using namespace Global;
;
namespace Gameplay
{
	namespace Cell
	{
		CellView::CellView(CellController* controller)
		{
			cell_controller = controller;
			cell_button = new ButtonView;
		}

		CellView::~CellView()
		{
			delete(cell_button);
		}

		void CellView::initialize()
		{
			initializeButtonImage(tile_size * 3, tile_size * 3);
		}

		void CellView::render()
		{
			cell_button->render();
		}

		void CellView::update()
		{
			cell_button->update();
		}

		void CellView::initializeButtonImage(float width, float height)
		{
			cell_button->initialize("Cell", Config::cells_texture_path, width, height, Vector2f(0, 0));
		}

	}
}