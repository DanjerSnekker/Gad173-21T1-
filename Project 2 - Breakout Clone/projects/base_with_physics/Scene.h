#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Scene
{
private:

	//Note: Its possible to assign the bool val here, but it's also possible to do it in the .cpp file as a constructor intialization.
	bool isSceneActive;
	bool isSceneLoaded;

public:

	Scene();
	~Scene();

	virtual void Init();
	virtual void Load();
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);
	//These functions are marked as virtual because it allows me to modify their behaviour

	inline bool getLoadedScene() { return isSceneLoaded; }
};