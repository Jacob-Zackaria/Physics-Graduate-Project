#include "Visualizer.h"
#include "GraphicsObject_Box.h"
#include "PhysicsManager.h"
#include "PixelToMeter.h"
#include "Color.h"
#include "GameObject2D.h"

Visualizer* Visualizer::ptrInstance = nullptr;

Visualizer::Visualizer()
{
	pGrObj = new GraphicsObject_Box( Rect(0, 0, 1, 1));

	ColJointToJoint = Color::Type::Blue;
	ColCenterToJoint = Color::Type::Green;
	ColJointMarker = Color::Type::Blue;
	ColCenterMarker = Color::Type::Black;
}

Visualizer::~Visualizer()
{
	delete pGrObj;
}

void Visualizer::privShowJointLinks()
{
	b2World* bWorld = PhysicsManager::GetWorld();

	b2Vec2 ja, jb, ca, cb;
	b2Joint* pjoint = bWorld->GetJointList();
	while (pjoint != nullptr)
	{
		ja = pjoint->GetAnchorA();
		jb = pjoint->GetAnchorB();
		ca = pjoint->GetBodyA()->GetPosition();
		cb = pjoint->GetBodyB()->GetPosition();

		DrawSegment(ca, ja, ColCenterToJoint);
		DrawSegment(cb, jb, ColCenterToJoint);	
		DrawMarker(ca, ColCenterMarker);
		DrawMarker(cb, ColCenterMarker);

		DrawMarker(ja, ColJointMarker);
		DrawMarker(jb, ColJointMarker);
		DrawSegment(ja, jb, ColJointToJoint);
		
		pjoint = pjoint->GetNext();
	}
}

void Visualizer::PrivShowSleep()
{
	b2World* bWorld = PhysicsManager::GetWorld();

	b2Body* pBody = bWorld->GetBodyList();
	while (pBody != nullptr)
	{
		DrawDebugSleep(pBody);
		pBody = pBody->GetNext();
	}
}


void Visualizer::DrawSegment(b2Vec2 s, b2Vec2 e, Color::Type c)
{
	b2Vec2 v = (e - s);
	float len = MeterToPixel(v.Length());
	b2Vec2 pos = .5f * (s + e);
	float ang = atan2f(v.y, v.x);

	pGrObj->color = c;

	Matrix Scale(MatrixScaleType::SCALE, len, 1, 1);
	Matrix Rot(RotType::ROT_Z, ang);
	Matrix Trans(MatrixTransType::TRANS, MeterToPixel(pos.x), MeterToPixel(pos.y), 0.0f);

	Matrix W = Scale * Rot * Trans;

	pGrObj->SetWorld(W);
	
	pGrObj->Render();
}

void Visualizer::DrawMarker(b2Vec2 p, Color::Type c)
{
	float len = 5.0f;
	pGrObj->color = c;

	Matrix Scale(MatrixScaleType::SCALE, len, 1, 1);
	Matrix Rot(RotType::ROT_Z, MATH_PI2);
	Matrix Trans(MatrixTransType::TRANS, MeterToPixel(p.x), MeterToPixel(p.y), 0.0f);

	Matrix W = Scale * Trans;
	pGrObj->SetWorld(W);
	pGrObj->Render();

	W = Scale * Rot * Trans;
	pGrObj->SetWorld(W);
	pGrObj->Render();
}

void Visualizer::DrawDebugSleep(b2Body* pb)
{
	Color::Type c = pb->IsAwake() ? Color::Type::White : c = Color::Type::Black;

	b2Fixture* pf = pb->GetFixtureList();
	while (pf != nullptr)
	{
		GameObject2D *pGObj = static_cast<GameObject2D*>(pf->GetUserData());
		if (pGObj != nullptr && pGObj->GetDebugSprite() != nullptr)
		{
			pGObj->SetDebugColor(c);
			pGObj->GetDebugSprite()->Render();
		}
		
		pf = pf->GetNext();
	}
}

void Visualizer::privAddLineWorld(b2Vec2 start, b2Vec2 end, Color::Type c)
{
	LineData newline;
	newline.From = start;
	newline.To = end;
	newline.Color = c;

	LineCol.push_back(newline);
}

void Visualizer::privShowLines()
{
	for (unsigned int i = 0; i < LineCol.size(); i++)
	{
		LineData& l = LineCol[i];
		DrawSegment(l.From, l.To, l.Color);
		//DrawMarker(l.From, l.Color);
	}
}

void Visualizer::privClearLines()
{
	LineCol.clear();
}

void Visualizer::privRender()
{
	privShowJointLinks();
	PrivShowSleep();
	privShowLines();
	privShowAABBs();
}

void Visualizer::privAddAABB(b2AABB ab, Color::Type col)
{
	AABBData abd;
	abd.AABB = ab;
	abd.Color = col;

	AABBCol.push_back(abd);
}

void Visualizer::privShowAABBs()
{
	for (unsigned int i = 0; i < AABBCol.size(); i++)
	{
		AABBData& abd(AABBCol[i]);
		DrawAABB(abd.AABB, abd.Color);
	}
}

void Visualizer::DrawAABB(b2AABB ab, Color::Type c)
{
	b2Vec2 extent = ab.GetExtents();
	b2Vec2 center = ab.GetCenter();

	Matrix world = Matrix(SCALE, MeterToPixel(2 * extent.x), MeterToPixel(2 * extent.y), 0)
		* Matrix(TRANS, MeterToPixel(center.x), MeterToPixel(center.y), 0);

	pGrObj->SetWorld(world);
	pGrObj->color = c;
	pGrObj->Render();
}

void Visualizer::privClearAABBs()
{
	AABBCol.clear();
}
