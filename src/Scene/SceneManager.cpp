#include "SceneManager.h"
#include "TimerMan.h"
SceneManager* SceneManager::privGetInstance()
{
	static SceneManager instance;
	return &instance;
}

SceneManager::SceneManager()
	:
	pList(nullptr),
	currentScene(nullptr)
{
}

SceneManager::~SceneManager()
{
}



void SceneManager::Add(Scene* newScene, Scene::Name newName)
{
	SceneManager* pMan = SceneManager::privGetInstance();

	newScene->SetName(newName);

	pMan->privAddToFront(newScene, pMan->pList);
}

void SceneManager::AddSceneObject(const Scene::Name newName, GameObject2D* pNewObj)
{
	SceneManager* pMan = SceneManager::privGetInstance();
	Scene* pScene = pMan->Find(newName);
	pScene->Add(pNewObj);
}

void SceneManager::DeleteSceneObject(const Scene::Name newName, GameObject2D* pNewObj)
{
	SceneManager* pMan = SceneManager::privGetInstance();
	Scene* pScene = pMan->Find(newName);
	pScene->Delete(pNewObj);
}

Scene* SceneManager::Find(const Scene::Name newName)
{
	SceneManager* pMan = SceneManager::privGetInstance();

	Scene* pTmp = pMan->pList;
	while (pTmp != nullptr)
	{
		if (pTmp->GetName() == newName)
		{
			return pTmp;
		}
		pTmp = pTmp->getNext();
	}

	return nullptr;
}

void SceneManager::SetCurrentScene(const Scene::Name newName)
{
	SceneManager* pMan = SceneManager::privGetInstance();
	Scene* pScene = pMan->Find(newName);

	if (pMan->currentScene != nullptr)
	{
		TimerMan::ClearTimerEvents();
		pMan->currentScene->DeleteSceneElements();
	}
	pMan->currentScene = pScene;

	pScene->AddSceneElements();
}

const Scene::Name SceneManager::GetCurrentScene()
{
	return SceneManager::privGetInstance()->currentScene->GetName();
}

void SceneManager::ResetCurrentScene()
{
	SceneManager* pMan = SceneManager::privGetInstance();
	pMan->currentScene->DeleteSceneElements();
	pMan->currentScene->AddSceneElements();
}

void SceneManager::Terminate()
{
	SceneManager* pMan = SceneManager::privGetInstance();

	pMan->currentScene->DeleteSceneElements();

	Scene* pTmp = pMan->pList;
	Scene* pTmp2 = nullptr;
	while (pTmp!= nullptr)
	{
		pTmp2 = pTmp;
		pTmp = pTmp->getNext();
		delete pTmp2;
	}

}

void SceneManager::Update()
{
	SceneManager::privGetInstance()->currentScene->Update();
}

void SceneManager::Draw()
{
	SceneManager::privGetInstance()->currentScene->Draw();
}

void SceneManager::privAddToFront(Scene* node, Scene*& head)
{
	assert(node);

	if (head == nullptr)
	{
		head = node;
		node->setNext(nullptr);
		node->setPrev(nullptr);
	}
	else
	{
		node->setNext(head);
		head->setPrev(node);
		head = node;
	}
}
