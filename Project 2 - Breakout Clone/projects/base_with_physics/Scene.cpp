#include "Scene.h"
#include "../../dev/components/kage2dutil/imgui.cpp"

Scene::Scene() : isSceneActive(false), isSceneLoaded(false)
{
}

Scene::~Scene()
{
}

void Scene::Init()
{
}

void Scene::Load()
{
	isSceneLoaded = true;
	isSceneActive = true;
	std::cout << "Scene hath been Loaded unto your mystical mirror" << std::endl;
}

void Scene::Update()
{
}

void Scene::Render(sf::RenderWindow& window)
{
}
