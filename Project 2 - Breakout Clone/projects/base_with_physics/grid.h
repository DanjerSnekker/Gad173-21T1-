#pragma once
#include <SFML/Graphics.hpp>

/*--------------------------------------------------
			Grid Variable Definitions
--------------------------------------------------*/

#define gridOFFSET_X 200		//100x is the suggested position
#define gridOFFSET_Y 100			//50y is the suggested position

#define total_X_CELLCOUNT 15
#define total_Y_CELLCOUNT 10

#define cell_X_OFFSET 60
#define cell_Y_OFFSET 40

#define lineWIDTH 4
#define cell_ToLine_OFFSET 1

#define total_CELLCOUNT total_X_CELLCOUNT * total_Y_CELLCOUNT

#define horizLine_LENGTH total_X_CELLCOUNT * cell_X_OFFSET + lineWIDTH
#define vertLine_LENGTH total_Y_CELLCOUNT * cell_Y_OFFSET

#define horizLine total_Y_CELLCOUNT + cell_ToLine_OFFSET
#define vertLine total_X_CELLCOUNT + cell_ToLine_OFFSET

class grid
{
/*--------------------------------------------------
				Class Functions
--------------------------------------------------*/

	
public:
	grid();
	~grid();

	void Update();
	void Draw();
	void Render(sf::RenderWindow& window);

/*--------------------------------------------------
			Initiliazing the Shapes
--------------------------------------------------*/

	sf::RectangleShape lineX[horizLine];
	sf::RectangleShape lineY[vertLine];
};

