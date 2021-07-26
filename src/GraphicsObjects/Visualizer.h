// Visualizer
// AB 4/18

#ifndef _Visualizer
#define _Visualizer

#include <assert.h>
#include "Box2D.h"
#include "Color.h"
#include <vector>

class GraphicsObject_Box;
class GameObject2D;

class Visualizer
{
private:
	static Visualizer* ptrInstance;

	Visualizer();
	~Visualizer();
	Visualizer(const Visualizer&) = delete;
	Visualizer& operator=(const Visualizer&) = delete;

	static Visualizer& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new Visualizer();

		return *ptrInstance;
	}

	GraphicsObject_Box* pGrObj;
	Color::Type ColCenterToJoint;
	Color::Type ColJointToJoint;
	Color::Type ColJointMarker;
	Color::Type ColCenterMarker;
	
	void DrawSegment(b2Vec2 s, b2Vec2 e, Color::Type c);
	void DrawMarker(b2Vec2 p, Color::Type c);
	void DrawDebugSleep(b2Body* pb);
	void DrawAABB(b2AABB ab, Color::Type c);

	void privShowJointLinks();

	struct LineData
	{
		LineData()
			:
			From{}, To{}, Color{}
		{
		}
		b2Vec2 From;
		b2Vec2 To;
		Color::Type Color;
	};

	using LineCollection = std::vector<LineData>;
	LineCollection LineCol;

	void privAddLineWorld(b2Vec2 start, b2Vec2 end, Color::Type c);
	void privShowLines();
	void privClearLines();
	void PrivShowSleep();
	void privRender();

	struct AABBData
	{
		AABBData()
			:
			AABB{}, Color{}
		{
		}
		b2AABB AABB;
		Color::Type Color;
	};

	using AABBCollection = std::vector<AABBData>;
	AABBCollection AABBCol;

	void privShowAABBs();
	void privAddAABB(b2AABB ab, Color::Type col);
	void privClearAABBs();

public:
	static void Render() { Instance().privRender(); };
	static void Terminate() { delete ptrInstance; }

	static void AddLineWorld(b2Vec2 start, b2Vec2 end, Color::Type c = Color::Type::White) { Instance().privAddLineWorld(start, end, c); };
	static void ClearLines() { Instance().privClearLines(); }

	static void AddAABB(b2AABB ab, Color::Type col) { Instance().privAddAABB(ab, col); };
	static void ClearAABBs() { Instance().privClearAABBs(); }
};

#endif _Visualizer
