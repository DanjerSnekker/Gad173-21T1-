#pragma once

#include "app.h"
#include "grid.h"
#include "tile.h"

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite *m_backgroundSprite;

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

	int tileIDSelected;

	sf::Sprite tiles[150];

	int map[150] =
	{
		1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,

	};

	/*
	int map[150] =
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};
	*/
	grid horizGrid;
	grid vertGrid;
};
