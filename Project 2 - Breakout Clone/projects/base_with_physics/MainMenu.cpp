#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
}

void MainMenu::Load()
{
	Scene::Load();


}

void MainMenu::Update()
{
	std::cout << "Testing Main Menu Update Function" << std::endl;
	Scene::Update();
}

void MainMenu::Render(sf::RenderWindow& window)
{
	std::cout << "Testing Main Menu Render Function" << std::endl;
	Scene::Render(window);

}