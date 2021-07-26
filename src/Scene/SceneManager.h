#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H


#include "Scene.h"

class SceneManager
{
public:

	SceneManager(const SceneManager&) = delete;
	const SceneManager& operator = (const SceneManager&) = delete;
	~SceneManager();

	static void Add(Scene* newScene, Scene::Name newName);
	static void AddSceneObject(const Scene::Name newName, GameObject2D* pNewObj);
	static void DeleteSceneObject(const Scene::Name newName, GameObject2D* pNewObj);
	static Scene* Find(const Scene::Name newName);
	static void SetCurrentScene(const Scene::Name newName);
	static const Scene::Name GetCurrentScene();
	static void ResetCurrentScene();
	static void Terminate();

	static void Update();
	static void Draw();
	
private:
	static SceneManager* privGetInstance();
	SceneManager();

	void privAddToFront(Scene* node, Scene*& head);

	Scene* pList;
	Scene* currentScene;
};

#endif SCENE_MANAGER_H