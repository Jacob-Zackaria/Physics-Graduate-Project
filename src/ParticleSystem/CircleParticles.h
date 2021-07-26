// FeatherYellow
// Andre BerThiaume, May 2017

#ifndef _CircleParticles
#define _CircleParticles

#include "GameObject2D.h"

class ManagedPool;

class CircleParticles : public GameObject2D
{
private:
	ManagedPool* pPool;

public:
	CircleParticles() = delete;
	~CircleParticles();
	CircleParticles(const CircleParticles&) = delete;
	CircleParticles& operator=(const CircleParticles&) = delete;


	void SetPosAng(float pixx, float pixy, float ang);

	CircleParticles(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void ManagedSceneExit() override;
};

#endif _CircleParticles
