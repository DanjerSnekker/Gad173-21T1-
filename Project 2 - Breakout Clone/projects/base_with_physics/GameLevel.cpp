#include "GameLevel.h"
#include "LoadLevel.h"

GameLevel::GameLevel()
{
}

GameLevel::~GameLevel()
{
}

void GameLevel::Init()
{
}

void GameLevel::Load()
{
	Scene::Load();
	std::cout << "GameLevel loaded." << std::endl;

/*--------------------------------------------------
				Tile & Map Load Functions
--------------------------------------------------*/

	LoadLevel::LoadFile("data/MapSaves/MapTiles.txt", tile.tileMapArray, total_X_CELLCOUNT, total_Y_CELLCOUNT);
	tile.load();
	tile.LoadMap();

	for (size_t i = 0; i < total_CELLCOUNT; i++)
	{
		tile.animated_Tiles[i].Init();
		tile.animated_Tiles[i].Load("data/GAD173 - AnimTile_SpriteSheet v3.png");
	}

	return;
}

void GameLevel::Update()
{
	std::cout << "Testing Game Level Update Function" << std::endl;
	//This will be replaced by most of the update code currently in the example.cpp file

	Scene::Update();

	//Updates the animated tiles every frame by looping through each tile
	for (size_t i = 0; i < total_CELLCOUNT; i++)
	{
		tile.animated_Tiles[i].Update();
	}
}

void GameLevel::Render(sf::RenderWindow& window)
{
	std::cout << "Testing Game Level Render Function" << std::endl;
	//This will be replaced by most of the render code currently in the example.cpp file
	Scene::Render(window);

//For-Loop that draws the tiles on the grid
	for (size_t i = 0; i < total_CELLCOUNT; i++)
	{
		tile.animated_Tiles[i].Render(window);
	}

}