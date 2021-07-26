// FeatherYellow
// Andre BerThiaume, May 2017

#ifndef _TrailSmoke
#define _TrailSmoke

#include "GameObject2D.h"

class ManagedPool;

class TrailSmoke : public GameObject2D
{
private:
	ManagedPool* pPool;

public:
	TrailSmoke() = delete;
	~TrailSmoke();
	TrailSmoke(const TrailSmoke&) = delete;
	TrailSmoke& operator=(const TrailSmoke&) = delete;


	void SetPosAng(float pixx, float pixy, float ang);

	TrailSmoke(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void ManagedSceneExit() override;
};

#endif _TrailSmoke
