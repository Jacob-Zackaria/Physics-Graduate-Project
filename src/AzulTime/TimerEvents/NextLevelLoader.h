#ifndef NEXT_LEVEL_LOADER_H
#define NEXT_LEVEL_LOADER_H

#include "Scene.h"
#include "TimerEvent.h"
class NextLevelLoader : public TimerEvent
{
public:

	NextLevelLoader(Scene::Name newName);
	virtual void Execute(float currTime) override;
	virtual ~NextLevelLoader();


private:

	Scene::Name sceneName;
};


#endif NEXT_LEVEL_LOADER_H