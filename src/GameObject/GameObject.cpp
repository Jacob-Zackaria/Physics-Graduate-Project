#include <assert.h>
#include <math.h>

#include "AzulHelper.h"
#include "PCSNode.h"
#include "MathEngine.h"
#include "GameObject.h"
#include "GraphicsObject.h"

GameObject::GameObject()
	: PCSNode()
{
	ManagedNoDelete = false;
	this->deleteMe = false;
	this->pWorld = new Matrix(MatrixSpecialType::IDENTITY);
}

GameObject::~GameObject()
{
	//assert(this->deleteMe == true);
	delete this->pWorld;
}

Matrix &GameObject::getWorld()
{
	return *this->pWorld;
}

