#include "CollisionControl.h"
#include "DebugOut.h"

CollisionControl::CollisionControl()
{
}

CollisionControl::~CollisionControl()
{
}

void CollisionControl::CollideAccept(GameObject2D&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("ACCEPT\n");
}

void CollisionControl::CollideVisit(Wood&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit Wood\n");
}

void CollisionControl::CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit RedBird\n");
}

void CollisionControl::CollideVisit(YellowBird&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit YellowBird\n");
}

void CollisionControl::CollideVisit(Stone&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit Stone\n");
}

void CollisionControl::CollideVisit(Glass&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit Glass\n");
}

void CollisionControl::CollideVisit(CollisionObjectBox&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit Collison BOx\n");
}

void CollisionControl::CollideVisit(MinionPig&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit Glass\n");
}

void CollisionControl::CollideVisit(KingPig&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit KingPig\n");
}

void CollisionControl::CollideVisit(TerrainSegment&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit TerrainSegment\n");
}

void CollisionControl::CollideVisit(CollisionObjectTri&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit Collision Tri\n");
}

void CollisionControl::CollideVisit(FeatherYellow&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(FeatherRed&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(FeatherBlack&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(FeatherBlue&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(FeatherGreen&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(FeatherWhite&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(TrailSmoke&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(Projector&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(CircleParticles&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(Egg&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(Gear&, b2Contact*, const b2ContactImpulse*)
{
}

void CollisionControl::CollideVisit(SensorBox&, b2Contact*, const b2ContactImpulse*)
{
}
