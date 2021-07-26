// FeatherYellow
// Andre BerThiaume, May 2017

#ifndef _FeatherYellow
#define _FeatherYellow

#include "GameObject2D.h"

class ManagedPool;

class FeatherYellow : public GameObject2D
{
private:
	ManagedPool* pPool;
	float ScaleFactor;
	float speedx;
	float speedy;
	float speedang;
	float speedMag;

public:
	FeatherYellow() = delete;
	~FeatherYellow();
	FeatherYellow(const FeatherYellow&) = delete;
	FeatherYellow& operator=(const FeatherYellow&) = delete;

	virtual void Update(float t) override;

	void SetPosAng(float pixx, float pixy);

	FeatherYellow(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void ManagedSceneExit() override;
};

#endif _FeatherYellow
