#ifndef SALT_SALT_H
#define SALT_SALT_H

#include "InputSystem.h"
#include "CircleCollection.h"
class SaltSalt : InputSystem
{
public:
	SaltSalt();
	SaltSalt(const SaltSalt&) = delete;
	const SaltSalt& operator = (const SaltSalt&) = delete;
	virtual ~SaltSalt();

	virtual void Update() override;
	
	CircleCollection pCircles;
};


#endif SALT_SALT_H