/*
* Copyright (c) 2006-2007 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#include "Box2D/Dynamics/Joints/b2Joint.h"
#include "Box2D/Dynamics/Joints/b2DistanceJoint.h"
#include "Box2D/Dynamics/Joints/b2WheelJoint.h"
#include "Box2D/Dynamics/Joints/b2MouseJoint.h"
#include "Box2D/Dynamics/Joints/b2RevoluteJoint.h"
#include "Box2D/Dynamics/Joints/b2PrismaticJoint.h"
#include "Box2D/Dynamics/Joints/b2PulleyJoint.h"
#include "Box2D/Dynamics/Joints/b2GearJoint.h"
#include "Box2D/Dynamics/Joints/b2WeldJoint.h"
#include "Box2D/Dynamics/Joints/b2FrictionJoint.h"
#include "Box2D/Dynamics/Joints/b2RopeJoint.h"
#include "Box2D/Dynamics/Joints/b2MotorJoint.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2World.h"
#include "Box2D/Common/b2BlockAllocator.h"

#include <new>

b2Joint* b2Joint::Create(const b2JointDef* def, b2BlockAllocator* allocator)
{
	b2Joint* joint = NULL;

	switch (def->type)
	{
	case b2JointType::e_distanceJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2DistanceJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2DistanceJoint(static_cast<const b2DistanceJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;

	case b2JointType::e_mouseJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2MouseJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2MouseJoint(static_cast<const b2MouseJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;

	case b2JointType::e_prismaticJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2PrismaticJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2PrismaticJoint(static_cast<const b2PrismaticJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;

	case b2JointType::e_revoluteJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2RevoluteJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2RevoluteJoint(static_cast<const b2RevoluteJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;

	case b2JointType::e_pulleyJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2PulleyJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2PulleyJoint(static_cast<const b2PulleyJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;

	case b2JointType::e_gearJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2GearJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2GearJoint(static_cast<const b2GearJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;

	case b2JointType::e_wheelJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2WheelJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2WheelJoint(static_cast<const b2WheelJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;

	case b2JointType::e_weldJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2WeldJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2WeldJoint(static_cast<const b2WeldJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;
        
	case b2JointType::e_frictionJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2FrictionJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2FrictionJoint(static_cast<const b2FrictionJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;

	case b2JointType::e_ropeJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2RopeJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2RopeJoint(static_cast<const b2RopeJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;

	case b2JointType::e_motorJoint:
		{
			void* mem = allocator->Allocate(sizeof(b2MotorJoint));

			PLACEMENT_NEW_BEGIN
#undef new 
			joint = new (mem) b2MotorJoint(static_cast<const b2MotorJointDef*>(def));
			PLACEMENT_NEW_END
		}
		break;

	default:
		b2Assert(false);
		break;
	}

	return joint;
}

void b2Joint::Destroy(b2Joint* joint, b2BlockAllocator* allocator)
{
	joint->~b2Joint();
	switch (joint->m_type)
	{
	case b2JointType::e_distanceJoint:
		allocator->Free(joint, sizeof(b2DistanceJoint));
		break;

	case b2JointType::e_mouseJoint:
		allocator->Free(joint, sizeof(b2MouseJoint));
		break;

	case b2JointType::e_prismaticJoint:
		allocator->Free(joint, sizeof(b2PrismaticJoint));
		break;

	case b2JointType::e_revoluteJoint:
		allocator->Free(joint, sizeof(b2RevoluteJoint));
		break;

	case b2JointType::e_pulleyJoint:
		allocator->Free(joint, sizeof(b2PulleyJoint));
		break;

	case b2JointType::e_gearJoint:
		allocator->Free(joint, sizeof(b2GearJoint));
		break;

	case b2JointType::e_wheelJoint:
		allocator->Free(joint, sizeof(b2WheelJoint));
		break;
    
	case b2JointType::e_weldJoint:
		allocator->Free(joint, sizeof(b2WeldJoint));
		break;

	case b2JointType::e_frictionJoint:
		allocator->Free(joint, sizeof(b2FrictionJoint));
		break;

	case b2JointType::e_ropeJoint:
		allocator->Free(joint, sizeof(b2RopeJoint));
		break;

	case b2JointType::e_motorJoint:
		allocator->Free(joint, sizeof(b2MotorJoint));
		break;

	default:
		b2Assert(false);
		break;
	}
}

b2Joint::b2Joint(const b2JointDef* def)
{
	b2Assert(def->bodyA != def->bodyB);

	m_type = def->type;
	m_prev = NULL;
	m_next = NULL;
	m_bodyA = def->bodyA;
	m_bodyB = def->bodyB;
	m_index = 0;
	m_collideConnected = def->collideConnected;
	m_islandFlag = false;
	m_userData = def->userData;

	m_edgeA.joint = NULL;
	m_edgeA.other = NULL;
	m_edgeA.prev = NULL;
	m_edgeA.next = NULL;

	m_edgeB.joint = NULL;
	m_edgeB.other = NULL;
	m_edgeB.prev = NULL;
	m_edgeB.next = NULL;
}

bool b2Joint::IsActive() const
{
	return m_bodyA->IsActive() && m_bodyB->IsActive();
}
