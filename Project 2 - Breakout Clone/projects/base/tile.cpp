#include "tile.h"
#include <iostream>


/*--------------------------------------------------
				Main Constructor
--------------------------------------------------*/
tile::tile()
{

}

/*--------------------------------------------------
			Texture Loading Function
--------------------------------------------------*/
void tile::load()
{
		 
	//This is where the static tiles were loaded
	/*blackTile_01 = kage::TextureManager::getTexture("data/Colour_Black_Tile_01 - 000000.png");

	blueTile_01 = kage::TextureManager::getTexture("data/Colour_Blue_Tile_01 - 1a29fd.png");
	blueTile_02 = kage::TextureManager::getTexture("data/Colour_Blue_Tile_02 - 525dfb.png");

	orangeTile_01 = kage::TextureManager::getTexture("data/Colour_Orange_Tile_01 - ff9f2e.png");
	orangeTile_02 = kage::TextureManager::getTexture("data/Colour_Orange_Tile_02 - fb8d0b.png");

	whiteTile_01 = kage::TextureManager::getTexture("data/Colour_White_Tile_01 - ffffff.png");

	yellowTile_01 = kage::TextureManager::getTexture("data/Colour_Yellow_Tile_01 - fffc2e.png");
	yellowTile_02 = kage::TextureManager::getTexture("data/Colour_Yellow_Tile_02 - fffb00.png");


	greenTile_01 = kage::TextureManager::getTexture("data/Colour_Green_Tile_01 - 04ff00.png");
	greenTile_02 = kage::TextureManager::getTexture("data/Colour_Green_Tile_02 - 60ff5d.png");

	greyTile_01 = kage::TextureManager::getTexture("data/Colour_Grey_Tile_01 - 646565.png");

	pinkTile_01 = kage::TextureManager::getTexture("data/Colour_Pink_Tile_01 - ff5df7.png");
	pinkTile_02 = kage::TextureManager::getTexture("data/Colour_Pink_Tile_02 - ff00f2.png");

	redTile_01 = kage::TextureManager::getTexture("data/Colour_Red_Tile_01 - f20909.png");
	redTile_02 = kage::TextureManager::getTexture("data/Colour_Red_Tile_02 - fd3838.png");*/

	//This is to load the png for the tiles to be used by the image buttons.
	redEye_Tile = kage::TextureManager::getTexture("data/RedEye_StaticTile - v1.png");	//TileID = 1
	blueScreen_Tile = kage::TextureManager::getTexture("data/BlueScreen_StaticTile - v1.png");	//TileID = 2
	greenCore_Tile = kage::TextureManager::getTexture("data/GreenCore_StaticTile - v1.png");	//TileID = 3
	pinkCable_Tile = kage::TextureManager::getTexture("data/PinkCable_StaticTile - v1.png");	//TileID = 4
	yellowCable_Tile = kage::TextureManager::getTexture("data/YellowCable_StaticTile - v1.png");	//TileID = 5
	orangeCable_Tile = kage::TextureManager::getTexture("data/OrangeCable_StaticTile - v1.png");	//TileID = 6
	
}

/*--------------------------------------------------
			Tile Loading Function
--------------------------------------------------*/
void tile::LoadMap()
{

	//For-Loop that cycles through the grid columns

	for (size_t y = 0; y < total_Y_CELLCOUNT; y++)
	{

		/*For-Loop that cycles through the grid rows.
		The For-Loop above will only repeat itself once this loop finishes a single cycle*/

		for (size_t x = 0; x < total_X_CELLCOUNT; x++)
		{
			int i = x + y * total_X_CELLCOUNT;

			/*Combines the current X & Y values from the loop with the no. of cells in a single row
			in order to create a single value called "i". Each possible version of i represents a different
			tile.*/
			
			/*if (tileMapArray[i] == 1)
			{
				tileTexture[i].setTexture(*blackTile_01);
			}

			if (tileMapArray[i] == 2)
			{
				tileTexture[i].setTexture(*blueTile_01);
			}

			if (tileMapArray[i] == 3)
			{
				tileTexture[i].setTexture(*blueTile_02);
			}

			if (tileMapArray[i] == 4)
			{
				tileTexture[i].setTexture(*orangeTile_01);
			}

			if (tileMapArray[i] == 5)
			{
				tileTexture[i].setTexture(*orangeTile_02);
			}

			if (tileMapArray[i] == 6)
			{
				tileTexture[i].setTexture(*whiteTile_01);
			}

			if (tileMapArray[i] == 7)
			{
				tileTexture[i].setTexture(*yellowTile_01);
			}

			if (tileMapArray[i] == 8)
			{
				tileTexture[i].setTexture(*yellowTile_02);
			}

			if (tileMapArray[i] == 9)
			{
				tileTexture[i].setTexture(*greenTile_01);
			}

			if (tileMapArray[i] == 10)
			{
				tileTexture[i].setTexture(*greenTile_02);
			}

			if (tileMapArray[i] == 11)
			{
				tileTexture[i].setTexture(*greyTile_01);
			}

			if (tileMapArray[i] == 12)
			{
				tileTexture[i].setTexture(*pinkTile_01);
			}

			if (tileMapArray[i] == 13)
			{
				tileTexture[i].setTexture(*pinkTile_02);
			}

			if (tileMapArray[i] == 14)
			{
				tileTexture[i].setTexture(*redTile_01);
			}

			if (tileMapArray[i] == 15)
			{
				tileTexture[i].setTexture(*redTile_02);
			}*/

			//Loads the animated tiles on the grid based on the tile id in each cell.

			if (tileMapArray[i] == 0)
			{
				animated_Tiles[i].StartAnim(sf::Vector2i(8, 1), sf::Vector2i(8, 1), 105);
			}
			
			if (tileMapArray[i] == 1)
			{
				animated_Tiles[i].StartAnim(sf::Vector2i(0, 0), sf::Vector2i(8, 0), 105);
			}

			if (tileMapArray[i] == 2) 
			{
				animated_Tiles[i].StartAnim(sf::Vector2i(0, 1), sf::Vector2i(4, 1), 105);

			}

			if (tileMapArray[i] == 3)
			{
				animated_Tiles[i].StartAnim(sf::Vector2i(0, 2), sf::Vector2i(6, 2), 105);

			}

			if (tileMapArray[i] == 4) 
			{
				animated_Tiles[i].StartAnim(sf::Vector2i(0, 3), sf::Vector2i(0, 3), 105);
			}

			if (tileMapArray[i] == 5)
			{
				animated_Tiles[i].StartAnim(sf::Vector2i(0, 4), sf::Vector2i(0, 4), 105);
			}

			if (tileMapArray[i] == 6)
			{
				animated_Tiles[i].StartAnim(sf::Vector2i(0, 5), sf::Vector2i(0, 5), 105);
			}

			//tileTexture[i].setPosition(sf::Vector2f(gridOFFSET_X + x * cell_X_OFFSET, gridOFFSET_Y + y * cell_Y_OFFSET));

			animated_Tiles[i].spritesheet.setPosition(sf::Vector2f(gridOFFSET_X + x * cell_X_OFFSET, gridOFFSET_Y + y * cell_Y_OFFSET));

			//Used to set the position of the tile in the grid
		}

		std::cout << "/n";
	}
}

/*--------------------------------------------------
				Main Deconstructor
--------------------------------------------------*/
tile::~tile()
{

}
