#include "grid.h"

/*--------------------------------------------------
				Main Constructor
--------------------------------------------------*/
grid::grid()
{

	//For-Loop responsible for creating all the horizontal lines and setting their position
	for (size_t i = 0; i < horizLine; i++)
	{
		lineX[i].setSize(sf::Vector2f(horizLine_LENGTH, lineWIDTH));
		lineX[i].setPosition(sf::Vector2f(gridOFFSET_X, gridOFFSET_Y + i * cell_Y_OFFSET));
	}

	//For-Loop responsible for creating all the vertical lines and setting their position
	for (size_t i = 0; i < vertLine; i++)
	{
		lineY[i].setSize(sf::Vector2f(lineWIDTH, vertLine_LENGTH));
		lineY[i].setPosition(sf::Vector2f(gridOFFSET_X + i * cell_X_OFFSET, gridOFFSET_Y));
	}

}

/*--------------------------------------------------
				Main Deconstructor
--------------------------------------------------*/
grid::~grid()
{
}

/*--------------------------------------------------
				Update Function
--------------------------------------------------*/
void grid::Update()
{
}

/*--------------------------------------------------
				Draw Function
--------------------------------------------------*/
void grid::Draw()
{
}

/*--------------------------------------------------
			Grid Render Function
--------------------------------------------------*/

//This thing is used to render the grid lines in the main window. We don't need it, but for now, I'm letting it stay
void grid::Render(sf::RenderWindow& window)
{
	/*
	//For-Loop responsible for drawing all the horizontal lines in the main window	
	for (size_t i = 0; i < horizLine; i++)
	{
		window.draw(lineX[i]);
	}

	//For-Loop responsible for drawing all the vertical lines in the main window
	for (size_t i = 0; i < vertLine; i++)
	{
		window.draw(lineY[i]);
	}
	*/
}