#ifndef LOAD_LEVEL_H
#define LOAD_LEVEL_H

#include "Scene.h"


class LoadLevel : public Scene
{
public:
	LoadLevel();
	LoadLevel(const LoadLevel&) = delete;
	const LoadLevel& operator = (const LoadLevel&) = delete;
	virtual ~LoadLevel();

	virtual void AddSceneElements() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

	Scene::Name sceneName;
};

#endif LOAD_LEVEL_H