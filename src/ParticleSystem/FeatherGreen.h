// FeatherYellow
// Andre BerThiaume, May 2017

#ifndef _FeatherGreen
#define _FeatherGreen

#include "GameObject2D.h"

class ManagedPool;

class FeatherGreen : public GameObject2D
{
private:
	ManagedPool* pPool;
	float ScaleFactor;
	float speedx;
	float speedy;
	float speedang;
	float speedMag;

public:
	FeatherGreen() = delete;
	~FeatherGreen();
	FeatherGreen(const FeatherGreen&) = delete;
	FeatherGreen& operator=(const FeatherGreen&) = delete;

	virtual void Update(float t) override;

	void SetPosAng(float pixx, float pixy);

	FeatherGreen(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void ManagedSceneExit() override;
};

#endif _FeatherGreen
