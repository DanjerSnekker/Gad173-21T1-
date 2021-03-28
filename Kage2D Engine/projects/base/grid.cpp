#include "grid.h"

void grid::Update()
{
}

void grid::Draw()
{
}

grid::grid()
{
	for (size_t i = 0; i < horizLine; i++)
	{
		lineX[i].setSize(sf::Vector2f(horizLine_LENGTH, lineWidth));
		lineX[i].setPosition(sf::Vector2f(gridPosition_X, gridPosition_Y + i * cellLength));
	}

	for (size_t i = 0; i < vertLine; i++)
	{
		lineY[i].setSize(sf::Vector2f(lineWidth, vertLine_LENGTH));
		lineY[i].setPosition(sf::Vector2f(gridPosition_X + i * cellHeight, gridPosition_Y));
	}

}

grid::~grid()
{
}

void grid::Render(sf::RenderWindow& window)
{
	for (size_t i = 0; i < horizLine; i++)
	{
		window.draw(lineX[i]);
	}

	for (size_t i = 0; i < vertLine; i++)
	{
		window.draw(lineY[i]);
	}
}
