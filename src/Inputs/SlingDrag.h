#ifndef SLING_DRAG_H
#define SLING_DRAG_H

#include "InputManager.h"
#include "Bird.h"
#include "ProjectedTrajectory.h"

class SlingDrag : InputSystem
{
public:
	struct SlingData
	{
		SlingData()
			:
			pObj(nullptr),
			anchor{},
			drawLimit(0.0f),
			origState(),
			origAngle(0.0f)
		{}
		GameObject2D* pObj;
		b2Vec2 anchor;
		float drawLimit;
		Rect origState;
		float origAngle;
	};


	SlingDrag(b2Vec2 newSlingPos, float newLimit);
	SlingDrag(const SlingDrag&) = delete;
	const SlingDrag& operator = (const SlingDrag&) = delete;
	virtual ~SlingDrag();

	virtual void Update() override;

	void AddSling1(GameObject2D* newObj, b2Vec2 newAnchor, const float newDrawLimit);
	void AddSling2(GameObject2D* newObj, b2Vec2 newAnchor, const float newDrawLimit);

private:
	b2Vec2 slingPos;
	float limit;
	SlingData pData[2];

	// projection
	ProjectedTrajectory pTraj;
};


#endif SLING_DRAG_H