#pragma once
#include <sfml/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
		class CellView;
		class CellModel;

		enum class CellState;
		enum class CellType;
		enum class CellValue;

		class CellController
		{
		private:
			CellView* cell_view;
			CellModel* cell_model;

			void destroy();

		public:
			CellController(sf::Vector2i position);
			~CellController();

			void initialize(float cell_width, float cell_height);
			void render();
			void update();

			void reset();

			CellState getCellState();
			CellValue getCellValue();
			void setCellValue(CellValue type);
			sf::Vector2i getCellPosition();

			void openCell();
			void flagCell();

			bool canOpenCell();
		};
	}
}