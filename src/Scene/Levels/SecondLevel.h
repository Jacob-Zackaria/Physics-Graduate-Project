#ifndef SECOND_LEVEL_H
#define SECOND_LEVEL_H

#include "Scene.h"

class LineDynamicCollider;
class SecondLevel : public Scene
{
public:
	SecondLevel();
	SecondLevel(const SecondLevel&) = delete;
	const SecondLevel& operator = (const SecondLevel&) = delete;
	virtual ~SecondLevel();

	virtual void AddSceneElements() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

	void CreateCar();
	void CarControl();
	void CreateFerris(const float baseX, const float baseY);


	LineDynamicCollider* pSys;
	Egg* pEgg;
	GameObject2D* carBody;
	b2WheelJoint* pFrontWheel;
	b2WheelJoint* pRearWheel;
	float carSpeed;
};

#endif SECOND_LEVEL_H