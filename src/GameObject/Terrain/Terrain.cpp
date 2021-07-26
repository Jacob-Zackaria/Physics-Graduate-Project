#include "Terrain.h"
#include <cstdlib>
#include "TerrainSegment.h"
#include "GameObjectMan.h"
#include "PhysicsManager.h"
#include "Game.h"

Terrain::Terrain(b2Vec2 posleft, b2Vec2 posright, float DFy, int count)
{
	DispFacty = DFy;

	SegmentCount = count + 1;
	SegArray = new Segment[SegmentCount];
	SegArray[0].Point = posleft;
	SegArray[SegmentCount - 1].Point = posright;

	MinY = 50;
	MaxY = Game::GetWindowHeight() - 200;


	// BodyDef
	b2BodyDef TerrainBodyDef;
	TerrainBodyDef.type = b2BodyType::b2_staticBody;  // Default value, but I show it here explicitly
	TerrainBodyDef.position.Set(0,0);
	TerrainBodyDef.angle = 0;

	// Single body for the whole terrain
	pBody = PhysicsManager::GetWorld()->CreateBody(&TerrainBodyDef);
	
	BuildSegment(0, SegmentCount - 1);

}

Terrain::~Terrain()
{
	for (int i = 0; i < SegmentCount - 1; i++)
	{
		assert(SegArray[i].pTerrSeg != nullptr);
		GameObjectMan::Delete( SegArray[i].pTerrSeg );
	}

	delete[] SegArray;

	PhysicsManager::GetWorld()->DestroyBody(pBody);
}

void Terrain::Build()
{
	Clear();

	BuildSegment(0, SegmentCount - 1);

}

void Terrain::Clear()
{
	for (int i = 0; i < SegmentCount - 1; i++)
	{
		assert(SegArray[i].pTerrSeg != nullptr);
		SegArray[i].pTerrSeg->MarkForDelete();
	}

}

void Terrain::BuildSegment(int i, int j)
{
	if (i == j)
	{
		// nothing
	}
	else if (i == j - 1)
	{
		b2Vec2 left = SegArray[i].Point;
		b2Vec2 right = SegArray[j].Point;
		//b2Vec2 midpoint = 0.5f *(left + right);
		b2Vec2 vdir = right - left;
		//float len = vdir.Length();
		float ang = atan2f(vdir.y, vdir.x);
		
		// Using box shapes
		//SegArray[i].pTerrSeg = new TerrainSegment(midpoint.x, midpoint.y, len, ang, pBody);
		
		//len;
		// Using edge shapes
		SegArray[i].pTerrSeg = new TerrainSegment(left, right, ang, pBody);

		GameObjectMan::Add(SegArray[i].pTerrSeg, GameObjectName::Name::ObjectsBucket);
	}
	else
	{
		int midind = (int) floor(.5f*(i + j));
		b2Vec2 left = SegArray[i].Point;
		b2Vec2 right = SegArray[j].Point;
		b2Vec2 midpoint = 0.5f *(left + right);

		// displace the midpoint up/down
		float yDelta =  DispFacty * (right-left).Length();
		midpoint.y += Random(-yDelta, yDelta);
		//clamp(midpoint.y, MinY, MaxY);

		SegArray[midind].Point = midpoint;

		// Recurse left and right
		BuildSegment(i, midind);
		BuildSegment(midind, j);
	}
}

float Terrain::Random(float min, float max)
{
	float r = (float)rand() / (float)RAND_MAX;
	return min + r * (max - min);

}

void Terrain::clamp(float& v, float min, float max)
{
	v = v < min ? min : v > max ? max : v;
}