#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(int sceneIndex)
{
	currentSceneIndex = sceneIndex;

	if (!scenes_List[currentSceneIndex]->getLoadedScene())
		scenes_List[currentSceneIndex]->Load();

}

void SceneManager::AddScene(Scene* scene)
{
	scenes_List.push_back(scene);
}

void SceneManager::RemoveScene(int sceneIndex)
{
}

void SceneManager::Load()
{
}

void SceneManager::Update()
{
	if (scenes_List.size() > 0)
		scenes_List[currentSceneIndex]->Update();

}

void SceneManager::Render(sf::RenderWindow& window)
{
	if (scenes_List.size() > 0)
		scenes_List[currentSceneIndex]->Render(window);
}
