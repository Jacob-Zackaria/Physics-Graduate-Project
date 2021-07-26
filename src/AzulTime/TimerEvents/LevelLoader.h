#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H

class SceneLink;

#include "TimerMan.h"
#include "SceneManager.h"

class LevelLoader : public TimerEvent
{
public:

	LevelLoader(Scene::Name newName);
	virtual void Execute(float currTime) override;
	virtual ~LevelLoader();

	void AddObjects(GameObject2D* newObj);

private:
	void privAddToFront(SceneLink* node, SceneLink*& head);
	void privRemove(SceneLink* pNewData, SceneLink*& pHead);

	SceneLink* pNewLink;
	Scene::Name sceneName;

};


#endif LEVEL_LOADER_H