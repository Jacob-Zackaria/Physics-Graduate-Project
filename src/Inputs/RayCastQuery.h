#ifndef RAY_CAST_QUERY_H
#define RAY_CAST_QUERY_H

#include "InputSystem.h"
#include "LineRayCast.h"
class RayCastQuery : InputSystem
{
public:
	RayCastQuery();
	RayCastQuery(const RayCastQuery&) = delete;
	const RayCastQuery& operator = (const RayCastQuery&) = delete;
	virtual ~RayCastQuery();

	virtual void Update() override;
	
	LineRayCast* pRayCast;
};


#endif RAY_CAST_QUERY_H