#include "LevelSelector.h"
#include "SceneManager.h"
#include "Keyboard.h"
LevelSelector::~LevelSelector()
{
}

void LevelSelector::Update()
{
	static bool  homeKey = false;

	if (!(SceneManager::GetCurrentScene() == Scene::Name::FIRST_LEVEL)
		&& Keyboard::GetKeyState(AZUL_KEY::KEY_1))
	{
		SceneManager::SetCurrentScene(Scene::Name::FIRST_LEVEL);
	}
	else if (!(SceneManager::GetCurrentScene() == Scene::Name::SECOND_LEVEL)
		&& Keyboard::GetKeyState(AZUL_KEY::KEY_2))
	{
		SceneManager::SetCurrentScene(Scene::Name::SECOND_LEVEL);
	}
	else if (!(SceneManager::GetCurrentScene() == Scene::Name::THIRD_LEVEL)
		&& Keyboard::GetKeyState(AZUL_KEY::KEY_3))
	{
		SceneManager::SetCurrentScene(Scene::Name::THIRD_LEVEL);
	}
	else if (!(SceneManager::GetCurrentScene() == Scene::Name::FOURTH_LEVEL)
		&& Keyboard::GetKeyState(AZUL_KEY::KEY_4))
	{
		SceneManager::SetCurrentScene(Scene::Name::FOURTH_LEVEL);
	}
	else if (!homeKey && Keyboard::GetKeyState(AZUL_KEY::KEY_HOME))
	{
		SceneManager::ResetCurrentScene();
		homeKey = true;
	}

	homeKey = Keyboard::GetKeyState(AZUL_KEY::KEY_HOME);
}


LevelSelector::LevelSelector()
{
}
