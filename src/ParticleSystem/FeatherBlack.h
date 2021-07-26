// FeatherYellow
// Andre BerThiaume, May 2017

#ifndef _FeatherBlack
#define _FeatherBlack

#include "GameObject2D.h"

class ManagedPool;

class FeatherBlack : public GameObject2D
{
private:
	ManagedPool* pPool;
	float ScaleFactor;
	float speedx;
	float speedy;
	float speedang;
	float speedMag;

public:
	FeatherBlack() = delete;
	~FeatherBlack();
	FeatherBlack(const FeatherBlack&) = delete;
	FeatherBlack& operator=(const FeatherBlack&) = delete;

	virtual void Update(float t) override;

	void SetPosAng(float pixx, float pixy);

	FeatherBlack(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void ManagedSceneExit() override;
};

#endif _FeatherBlack
