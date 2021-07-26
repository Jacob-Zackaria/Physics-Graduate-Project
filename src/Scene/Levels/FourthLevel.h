#ifndef FOURTH_LEVEL_H
#define FOURTH_LEVEL_H

#include "Scene.h"

class Rope;
class Platform;
class LineDynamicCollider;
class FourthLevel : public Scene
{
public:
	FourthLevel();
	FourthLevel(const FourthLevel&) = delete;
	const FourthLevel& operator = (const FourthLevel&) = delete;
	virtual ~FourthLevel();

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

	Rope* newRope;
	Rope* newRope2;
	Platform* newPlat;
	Platform* newPlat2;
};

#endif FOURTH_LEVEL_H