#include "NextLevelLoader.h"
#include "SceneManager.h"
NextLevelLoader::NextLevelLoader(Scene::Name newName)
	:
	sceneName(newName)
{
}

void NextLevelLoader::Execute(float currTime)
{
	currTime;
	SceneManager::SetCurrentScene(sceneName);
}

NextLevelLoader::~NextLevelLoader()
{
}
