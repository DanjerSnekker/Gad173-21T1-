#pragma once
#include <SFML/Graphics.hpp>
#include <kage2dutil/texture_manager.h>
#include "grid.h"



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

	sf::Texture* blackTile_01;

	sf::Texture* blueTile_01;
	sf::Texture* blueTile_02;

	sf::Texture* orangeTile_01;
	sf::Texture* orangeTile_02;

	sf::Texture* whiteTile_01;

	sf::Texture* yellowTile_01;
	sf::Texture* yellowTile_02;

	sf::Texture* greenTile_01;
	sf::Texture* greenTile_02;

	sf::Texture* greyTile_01;

	sf::Texture* pinkTile_01;
	sf::Texture* pinkTile_02;

	sf::Texture* redTile_01;
	sf::Texture* redTile_02;

/*--------------------------------------------------
			Map Array and tileTexture
--------------------------------------------------*/

	sf::Sprite tileTexture[total_X_CELLCOUNT * total_Y_CELLCOUNT];			//Used to load our textures into. 
				
				//I like to call it the bane of my existence 
				//Spent a whole week trying to fix the damn thing.

	
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

