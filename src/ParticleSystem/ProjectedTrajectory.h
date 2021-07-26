// ProjectedTrajectory
// Andre Berthiaume, May 2017

#ifndef _ProjectedTrajectory
#define _ProjectedTrajectory

#include "Box2D.h"
#include "ProjectorCollection.h"

class ProjectedTrajectory
{
public:
	ProjectedTrajectory() = default;
	~ProjectedTrajectory() = default;
	ProjectedTrajectory(const ProjectedTrajectory&) = delete;
	ProjectedTrajectory& operator=(const ProjectedTrajectory&) = delete;

	void Trace(b2Vec2 initPos, b2Vec2 initVel, int count);
	void DeleteTrace();
private:
	ProjectorCollection pProjectorCollection;

};


#endif _ProjectedTrajectory