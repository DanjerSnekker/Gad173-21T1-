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

			//Used to set the position of the tile in the grid
			animated_Tiles[i].spritesheet.setPosition(sf::Vector2f(gridOFFSET_X + x * cell_X_OFFSET, gridOFFSET_Y + y * cell_Y_OFFSET));
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