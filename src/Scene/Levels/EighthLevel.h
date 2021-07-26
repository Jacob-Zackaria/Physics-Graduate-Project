#ifndef EIGHTH_LEVEL_H
#define EIGHTH_LEVEL_H

#include "Scene.h"

class EighthLevel : public Scene
{
public:
	EighthLevel();
	EighthLevel(const EighthLevel&) = delete;
	const EighthLevel& operator = (const EighthLevel&) = delete;
	virtual ~EighthLevel();

	virtual void AddSceneElements() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

};

#endif EIGHTH_LEVEL_H