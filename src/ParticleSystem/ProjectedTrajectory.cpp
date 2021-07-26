#include "ProjectedTrajectory.h"
#include "PhysicsManager.h"
#include "PixelToMeter.h"

void ProjectedTrajectory::Trace(b2Vec2 initPos, b2Vec2 initVel, int count)
{
	pProjectorCollection.DeleteProjection();  // Recall the previous projected trail

	float timestep = 1.0f / 60;
	b2Vec2 a = PhysicsManager::GetWorld()->GetGravity();

	b2Vec2 p = initPos;
	float t;
	for (int i = 0; i < count; i++)
	{
		t = 5 * i * timestep;
		p = initPos + t * initVel + t * t * 0.5f * a;

		pProjectorCollection.Create(MeterToPixel(p.x), MeterToPixel(p.y), 0);
	}
}

void ProjectedTrajectory::DeleteTrace()
{
	pProjectorCollection.DeleteProjection();
}
