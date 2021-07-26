#ifndef AABB_QUERY_H
#define AABB_QUERY_H

#include "InputSystem.h"
#include "AABBRayCast.h"
class AABBQuery : InputSystem
{
public:
	AABBQuery();
	AABBQuery(const AABBQuery&) = delete;
	const AABBQuery& operator = (const AABBQuery&) = delete;
	virtual ~AABBQuery();

	virtual void Update() override;
	
	AABBRayCast* pRayCast;
};


#endif AABB_QUERY_H