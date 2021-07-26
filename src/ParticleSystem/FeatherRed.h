// FeatherYellow
// Andre BerThiaume, May 2017

#ifndef _FeatherRed
#define _FeatherRed

#include "GameObject2D.h"

class ManagedPool;

class FeatherRed : public GameObject2D
{
private:
	ManagedPool* pPool;
	float ScaleFactor;
	float speedx;
	float speedy;
	float speedang;
	float speedMag;

public:
	FeatherRed() = delete;
	~FeatherRed();
	FeatherRed(const FeatherRed&) = delete;
	FeatherRed& operator=(const FeatherRed&) = delete;

	virtual void Update(float t) override;

	void SetPosAng(float pixx, float pixy);

	FeatherRed(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void ManagedSceneExit() override;
};

#endif _FeatherRed
