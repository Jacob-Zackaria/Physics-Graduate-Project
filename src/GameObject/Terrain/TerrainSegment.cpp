#include "TerrainSegment.h"
#include "PixelToMeter.h"

TerrainSegment::TerrainSegment(float posx, float posy, float len, float ang, b2Body* pbod)
	: GameObject2D(
		GameObjectName::Name::WoodPlatform0,
		new GraphicsObject_Sprite(ImageName::Name::WoodPlatform0, Rect(100, 20, len, (float)stickheight)),
		new GraphicsObject_Box(Rect(posx, posy, len, 5))
	)
{
	this->setName("TowerSegment");

	// Shape
	b2PolygonShape StickShape;
	StickShape.SetAsBox(PixelToMeter(len * 0.5f), PixelToMeter(5),
		b2Vec2(PixelToMeter(posx), PixelToMeter(posy)),  // center of box relative to body position
		ang
	);

	// We must use a Fixture Definition
	b2FixtureDef SegmentFixtureDef;
	SegmentFixtureDef.shape = &StickShape;
	SegmentFixtureDef.density = 10;
	SegmentFixtureDef.friction = 0.3f;
	SegmentFixtureDef.restitution = 0.50f;
	SegmentFixtureDef.userData = this;

	pTerBody = pbod;
	pSegFix = pTerBody->CreateFixture(&SegmentFixtureDef);

	this->SetFixture(pSegFix, ang, posx, posy);
}

TerrainSegment::TerrainSegment(b2Vec2 left, b2Vec2 right, float ang, b2Body* pbod)
	: GameObject2D(
		GameObjectName::Name::WoodPlatform0,
		new GraphicsObject_Sprite(ImageName::Name::WoodPlatform0, Rect(100, 20, (right-left).Length(), (float) stickheight)),
		new GraphicsObject_Box(Rect(0, 0, (right - left).Length(), (float) stickheight))
	)
{
	b2Vec2 midpoint = .5f * (right+left);
	this->posX = midpoint.x;
	this->posY = midpoint.y;
	
	this->setName("TowerSegment");
	this->SetOffsetAngle(ang);

	// Shape
	b2EdgeShape StickShape;
	b2Vec2 WorldLeft(PixelToMeter(left.x), PixelToMeter(left.y));
	b2Vec2 Worldright(PixelToMeter(right.x), PixelToMeter(right.y));
	StickShape.Set(WorldLeft, Worldright); 

	// We must use a Fixture Definition
	b2FixtureDef SegmentFixtureDef;
	SegmentFixtureDef.shape = &StickShape;
	SegmentFixtureDef.density = 10;
	SegmentFixtureDef.friction = 0.3f;
	SegmentFixtureDef.restitution = 0.50f;
	SegmentFixtureDef.userData = this;

	pTerBody = pbod;
	pSegFix = pTerBody->CreateFixture(&SegmentFixtureDef);
}

TerrainSegment::~TerrainSegment()
{
	pTerBody->DestroyFixture(pSegFix);
}