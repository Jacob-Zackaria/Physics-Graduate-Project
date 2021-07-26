// Terrain
// Andre Berthiaume, April 2017

#ifndef _Terrain
#define _Terrain

#include "Box2D.h"
class TerrainSegment;

class Terrain 
{
public:
	Terrain() = delete;
	virtual ~Terrain();
	Terrain(const Terrain&) = delete;
	Terrain& operator=(const Terrain&) = delete;

	Terrain(b2Vec2 posleft, b2Vec2 posright, float DFy, int count);


private:
	struct Segment
	{
		b2Vec2 Point;
		TerrainSegment* pTerrSeg = nullptr;
	};

	int SegmentCount;
	Segment* SegArray;

	float DispFacty;
	float MaxY;
	float MinY;

	void BuildSegment(int i, int j);

	float Random(float min, float max);
	void clamp(float& v, float min, float max);

	b2Body* pBody;

public:
	b2Vec2 GetLeft() { return SegArray[0].Point; }
	b2Vec2 GetRight() { return SegArray[SegmentCount - 1].Point; }
	float GetDisp() { return DispFacty; }
	int GetCount() { return SegmentCount - 1; }

	void Build();
	void Clear();
};

#endif _Terrain
