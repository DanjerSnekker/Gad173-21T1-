#pragma once

#include "Scene.h"

#include "grid.h"
#include "tile.h"

class GameLevel : public Scene
{

/*--------------------------------------------------
			Public Functions & Variables
--------------------------------------------------*/
public:

	GameLevel();
	~GameLevel();

	void Init() override;
	void Load() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;

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