#ifndef SEVENTH_LEVEL_H
#define SEVENTH_LEVEL_H

#include "Scene.h"

class SeventhLevel : public Scene
{
public:
	SeventhLevel();
	SeventhLevel(const SeventhLevel&) = delete;
	const SeventhLevel& operator = (const SeventhLevel&) = delete;
	virtual ~SeventhLevel();

	virtual void AddSceneElements() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

};

#endif SEVENTH_LEVEL_H