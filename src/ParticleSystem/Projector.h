// FeatherYellow
// Andre BerThiaume, May 2017

#ifndef _Projector
#define _Projector

#include "GameObject2D.h"

class ManagedPool;

class Projector : public GameObject2D
{
private:
	ManagedPool* pPool;

public:
	Projector() = delete;
	~Projector();
	Projector(const Projector&) = delete;
	Projector& operator=(const Projector&) = delete;


	void SetPosAng(float pixx, float pixy, float ang);

	Projector(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void ManagedSceneExit() override;
};

#endif _Projector
