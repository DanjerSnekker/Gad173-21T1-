#pragma once
#include <SFML/Graphics.hpp>

#define horizLine 16
#define vertLine 11

#define horizLine_LENGTH 604
#define vertLine_LENGTH 600

#define lineWidth 4

#define gridPosition_X 100 //100x is the suggested position
#define gridPosition_Y 50  //50y is the suggested position

#define cellHeight 60
#define cellLength 40

class grid
{
	void Update();
	void Draw();

public:
	grid();
	~grid();

	void Render(sf::RenderWindow& window);

	sf::RectangleShape lineX[horizLine];
	sf::RectangleShape lineY[vertLine];
};

