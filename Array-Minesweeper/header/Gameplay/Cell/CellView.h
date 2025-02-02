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
			const float cell_top_offset = 274.f;
			const float cell_left_offset = 583.f;

			const int tile_size = 32;
			int slice_count = 12;

			CellController* cell_controller;
			UI::UIElement::ButtonView* cell_button;

			void initializeButtonImage(float width, float height);
			sf::Vector2f getCellScreenPosition(float width, float height);
			void setCellTexture();
			void registerButtonCallback();
			void cellButtonCallback(UI::UIElement::ButtonType button_type);

		public:
			CellView(CellController* controller);
			~CellView();

			void initialize(float width, float height);
			void render();
			void update();

			//sf::Vector2i getCellPosition();
		};
	}
}