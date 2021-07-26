// FeatherYellow
// Andre BerThiaume, May 2017

#ifndef _FeatherWhite
#define _FeatherWhite

#include "GameObject2D.h"

class ManagedPool;

class FeatherWhite : public GameObject2D
{
private:
	ManagedPool* pPool;
	float ScaleFactor;
	float speedx;
	float speedy;
	float speedang;
	float speedMag;

public:
	FeatherWhite() = delete;
	~FeatherWhite();
	FeatherWhite(const FeatherWhite&) = delete;
	FeatherWhite& operator=(const FeatherWhite&) = delete;

	virtual void Update(float t) override;

	void SetPosAng(float pixx, float pixy);

	FeatherWhite(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void ManagedSceneExit() override;
};

#endif _FeatherWhite
