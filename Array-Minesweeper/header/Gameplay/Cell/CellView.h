#pragma once
#include <SFML/Graphics.hpp>
#include <../../header/UI/UIElement/ButtonView.h>
#include "CellController.h"

using namespace sf;

namespace Gameplay
{
	namespace Cell
	{
		class CellController;

		class CellView
		{
		private:
			CellController* cell_controller;
			UI::UIElement::ButtonView* cell_button;

			void initializeButtonImage(float width, float height);
			const int tile_size = 32;

		public:
			CellView(CellController* controller);
			~CellView();

			void initialize();
			void render();
			void update();
		};
	}
}