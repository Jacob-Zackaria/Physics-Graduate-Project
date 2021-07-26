// TerrainSegment
// Andre Berthiaume, April 2017

#ifndef _TerrainSegment
#define _TerrainSegment

#include "GameObject2D.h"
#include "Box2D.h"

class TerrainSegment : public GameObject2D
{
private:
	b2Body* pTerBody;
	b2Fixture* pSegFix;

public:
	TerrainSegment() = delete;
	virtual ~TerrainSegment();
	TerrainSegment(const TerrainSegment&) = delete;
	TerrainSegment& operator=(const TerrainSegment&) = delete;

	TerrainSegment(float posx, float posy, float len, float ang, b2Body* pbod);
	TerrainSegment(b2Vec2 left, b2Vec2 right, float ang, b2Body* pbod);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) { other.CollideVisit(*this, contact, pimpulse); };

	static const int stickheight = 5;
	static const bool debugval = true;
};

#endif _TerrainSegment