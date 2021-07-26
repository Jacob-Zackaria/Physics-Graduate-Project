// FeatherYellow
// Andre BerThiaume, May 2017

#ifndef _FeatherBlue
#define _FeatherBlue

#include "GameObject2D.h"

class ManagedPool;

class FeatherBlue : public GameObject2D
{
private:
	ManagedPool* pPool;
	float ScaleFactor;
	float speedx;
	float speedy;
	float speedang;
	float speedMag;

public:
	FeatherBlue() = delete;
	~FeatherBlue();
	FeatherBlue(const FeatherBlue&) = delete;
	FeatherBlue& operator=(const FeatherBlue&) = delete;

	virtual void Update(float t) override;

	void SetPosAng(float pixx, float pixy);

	FeatherBlue(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void ManagedSceneExit() override;
};

#endif _FeatherBlue
