#pragma once
#include <SFML/Graphics.hpp>

#define tile_X horizLine_LENGTH * cellHeight
#define tile_Y vertLine_LENGTH * cellLength

class tile
{
	sf::Texture* blackTile_01;

	sf::Texture* blueTile_01;
	sf::Texture* blueTile_02;

	/*
	sf::Texture* greenTile_01;
	sf::Texture* greenTile_02;

	sf::Texture* greyTile_01;
	*/

	sf::Texture* orangeTile_01;
	sf::Texture* orangeTile_02;

	/*
	sf::Texture* pinkTile_01;
	sf::Texture* pinkTile_02;

	sf::Texture* redTile_01;
	sf::Texture* redTile_02;
	*/

	sf::Texture* whiteTile_01;

	sf::Texture* yellowTile_01;
	sf::Texture* yellowTile_02;

};

