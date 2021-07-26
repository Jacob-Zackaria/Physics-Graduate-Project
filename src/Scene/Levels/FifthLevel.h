#ifndef FIFTH_LEVEL_H
#define FIFTH_LEVEL_H

#include "Scene.h"

class FifthLevel : public Scene
{
public:
	FifthLevel();
	FifthLevel(const FifthLevel&) = delete;
	const FifthLevel& operator = (const FifthLevel&) = delete;
	virtual ~FifthLevel();

	virtual void AddSceneElements() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

	void CreateFerris();
};

#endif FIFTH_LEVEL_H