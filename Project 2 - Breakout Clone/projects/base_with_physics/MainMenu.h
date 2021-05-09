#pragma once
#include "Scene.h"
#include "app.h"
#include "tile.h"
#include "SceneManager.h"

class MainMenu : public Scene
{
private:



public:

	MainMenu();
	~MainMenu();

	void Init() override;
	void Load() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;

/*--------------------------------------------------
			Class Reference Variables
--------------------------------------------------*/

	//tile tile;

	//SceneManager manager_OfScenes;
};