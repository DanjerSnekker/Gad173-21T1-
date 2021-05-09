#pragma once
#include <SFML/Graphics.hpp>
#include <kage2dutil/texture_manager.h>
#include "grid.h"
#include "TileAnimator.h"

//#include "TileAnimator.h"

class tile
{

/*--------------------------------------------------
				Class Functions
--------------------------------------------------*/

public:

	tile();
	~tile();

	void load();
	void LoadMap();

/*--------------------------------------------------
				Tile Textures
--------------------------------------------------*/

	sf::Texture* redEye_Tile;
	sf::Texture* blueScreen_Tile;
	sf::Texture* greenCore_Tile;
	sf::Texture* pinkCable_Tile;
	sf::Texture* yellowCable_Tile;
	sf::Texture* orangeCable_Tile;

/*--------------------------------------------------
			Map Array and tileTexture
--------------------------------------------------*/

	TileAnimator animated_Tiles[total_CELLCOUNT];		//Stores our animated tiles

	//This is the empty tilemap that will be used for creating our own tilemap.

	int tileMapArray[total_CELLCOUNT];

	/*=
	{
		1,2,3,4,5,6,7,8,7,6,
		2,3,4,5,6,7,8,7,6,5,
		3,4,5,6,7,8,7,6,5,4,
		4,5,6,7,8,7,6,5,4,3,
		5,6,7,8,7,6,5,4,3,2,
		6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,
		2,3,4,5,6,7,8,7,6,5,
		3,4,5,6,7,8,7,6,5,4,
		4,5,6,7,8,7,6,5,4,3,
		5,6,7,8,7,6,5,4,3,2,
		6,7,8,7,6,5,4,3,2,1,
		1,2,3,4,5,6,7,8,7,6,
		2,3,4,5,6,7,8,7,6,5,
		3,4,5,6,7,8,7,6,5,4

	};*/

	/*The tilemap grid [that has been commented out] above, is to test if the colors are being rendered on the screen or not.
	It's only active when required for testing*/

};

