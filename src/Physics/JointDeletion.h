#ifndef JOINT_DELETION_H
#define JOINT_DELETION_H

#include "Box2D.h"
class JointDeletion
{
public:

	JointDeletion(b2Joint* pObj)
		:
		pNext(nullptr),
		pPrev(nullptr)
	{
		this->jointObj = pObj;
	}
	JointDeletion(const JointDeletion&) = delete;
	const JointDeletion& operator = (const JointDeletion&) = delete;
	~JointDeletion()
	{
	}

	b2Joint* GetJoint()
	{
		return this->jointObj;
	}

	//-----links----
	void JointDeletion::setNext(JointDeletion* newNext)
	{
		this->pNext = newNext;
	}

	void JointDeletion::setPrev(JointDeletion* newPrev)
	{
		this->pPrev = newPrev;
	}

	JointDeletion* JointDeletion::getNext() const
	{
		return (this->pNext);
	}

	JointDeletion* JointDeletion::getPrev() const
	{
		return (this->pPrev);
	}

private:
	b2Joint* jointObj;

	// links
	JointDeletion* pNext;
	JointDeletion* pPrev;
};

#endif JOINT_DELETION_H