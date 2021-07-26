#ifndef FIRST_LEVEL_H
#define FIRST_LEVEL_H

#include "Scene.h"

class LineDynamicCollider;
class FirstLevel : public Scene
{
public:
	FirstLevel();
	FirstLevel(const FirstLevel&) = delete;
	const FirstLevel& operator = (const FirstLevel&) = delete;
	virtual ~FirstLevel();

	virtual void AddSceneElements() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

	void CreateCar();
	void CarControl();

	LineDynamicCollider* pSys;
	Egg* pEgg;
	GameObject2D* carBody;
	b2WheelJoint* pFrontWheel;
	b2WheelJoint* pRearWheel;
	float carSpeed;
};

#endif FIRST_LEVEL_H