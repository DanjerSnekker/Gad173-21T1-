#include "tile.h"
#include "grid.h"

#include <kage2dutil/texture_manager.h>

void tile::Update()
{

}

void tile::Draw()
{

}

tile::tile()
{
	
}

void tile::load()
{
	blackTile_01 = kage::TextureManager::getTexture("data/Colour_Black_Tile_01 - 000000.png");   //TileID = 1

	blueTile_01 = kage::TextureManager::getTexture("data/Colour_Blue_Tile_01 - 1a29fd.png");   //TileID = 2
	blueTile_02 = kage::TextureManager::getTexture("data/Colour_Blue_Tile_02 - 525dfb.png");   //TileID = 3

	/*
	greenTile_01 = kage::TextureManager::getTexture("data/Colour_Green_Tile_01_04ff00.png");   //TileID =
	greenTile_02 = kage::TextureManager::getTexture("data/Colour_Green_Tile_02_60ff5d.png");   //TileID =

	greyTile_01 = kage::TextureManager::getTexture("data/Colour_Grey_Tile_01_646565.png");   //TileID =
	*/

	orangeTile_01 = kage::TextureManager::getTexture("data/Colour_Orange_Tile_01 - ff9f2e.png");   //TileID = 4
	orangeTile_02 = kage::TextureManager::getTexture("data/Colour_Orange_Tile_02 - fb8d0b.png");   //TileID = 5

	/*
	pinkTile_01 = kage::TextureManager::getTexture("data/Colour_Pink_Tile_01_ff5df7.png");   //TileID =
	pinkTile_02 = kage::TextureManager::getTexture("data/Colour_Pink_Tile_02_ff00f2.png");   //TileID =

	redTile_01 = kage::TextureManager::getTexture("data/Colour_Red_Tile_01_f20909.png");   //TileID =
	redTile_02 = kage::TextureManager::getTexture("data/Colour_Red_Tile_02_fd3838.png");   //TileID =
	*/

	whiteTile_01 = kage::TextureManager::getTexture("data/Colour_White_Tile_01 - ffffff.png");   //TileID = 6

	yellowTile_01 = kage::TextureManager::getTexture("data/Colour_Yellow_Tile_01 - fffc2e.png");   //TileID = 7
	yellowTile_02 = kage::TextureManager::getTexture("data/Colour_Yellow_Tile_02 - fffb00.png");   //TileID = 8

	for (size_t y = 0; y < 10; y++)
	{
		for (size_t x = 0; x < 15; x++)
		{
			int i = x + y * 15;

			/*if (map[i] == 1)
			{
				//tiles[i].setTexture(*blackTile_01);
			}

			if (map[i] == 2)
			{
				//tiles[i].setTexture(*blueTile_01);
			}

			if (map[i] == 3)
			{
				//tiles[i].setTexture(*blueTile_02);
			}

			if (map[i] == 4)
			{
				//tiles[i].setTexture(*orangeTile_01);
			}

			if (map[i] == 5)
			{
				//tiles[i].setTexture(*orangeTile_02);
			}

			if (map[i] == 6)
			{
				//tiles[i].setTexture(*whiteTile_01);
			}

			if (map[i] == 7)
			{
				//tiles[i].setTexture(*yellowTile_01);
			}

			if (map[i] == 8)
			{
				//tiles[i].setTexture(*yellowTile_02);
			}*/

			tiles[i].setPosition(sf::Vector2f(gridPosition_X + x * cellLength, gridPosition_Y + y * cellHeight));

		}
	}
}



tile::~tile()
{

}