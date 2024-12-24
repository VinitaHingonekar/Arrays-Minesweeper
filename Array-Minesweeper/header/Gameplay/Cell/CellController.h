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
			CellController();
			~CellController();

			void initialize();
			void render();
			void update();

			void reset();

			CellState getCellState();
			CellValue getCellValue();
			sf::Vector2i getCellPosition();
		};
	}
}