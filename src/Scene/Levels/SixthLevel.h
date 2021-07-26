#ifndef SIXTH_LEVEL_H
#define SIXTH_LEVEL_H

#include "Scene.h"
#include "Terrain.h"
class SixthLevel : public Scene
{
public:
	SixthLevel();
	SixthLevel(const SixthLevel&) = delete;
	const SixthLevel& operator = (const SixthLevel&) = delete;
	virtual ~SixthLevel();

	virtual void AddSceneElements() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;


	Terrain* pTerrain;
	GameObject2D* carBody;
	b2WheelJoint* pFrontWheel;
	b2WheelJoint* pRearWheel;
	float carSpeed;
};

#endif SIXTH_LEVEL_H