#ifndef THIRD_LEVEL_H
#define THIRD_LEVEL_H

#include "Scene.h"

class Platform;
class LineDynamicCollider;
class ThirdLevel : public Scene
{
public:
	ThirdLevel();
	ThirdLevel(const ThirdLevel&) = delete;
	const ThirdLevel& operator = (const ThirdLevel&) = delete;
	virtual ~ThirdLevel();

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
	Platform* newPlat;
	Platform* newPlat2;
	Platform* newPlat3;
	Platform* newPlat4;
};

#endif THIRD_LEVEL_H