#pragma once

#include "app.h"
#include "grid.h"
#include "tile.h"

class Example : public App
{

/*--------------------------------------------------
				Class Functions
--------------------------------------------------*/

public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();


/*--------------------------------------------------
				Background Sprite
--------------------------------------------------*/
	
	sf::Sprite *m_backgroundSprite;

/*--------------------------------------------------
				Tile ID Variable
--------------------------------------------------*/

	int tileIDSelected = 0;

/*--------------------------------------------------
			Class Reference Variables
--------------------------------------------------*/

	tile tile;

	grid horizGrid;
	grid vertGrid;

};
