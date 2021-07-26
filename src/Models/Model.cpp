
#include "Model.h"

Model::Model(ModelName::Name newName)
	: numVerts(0), numTris(0), vao(0), name(newName)
{
	this->vbo[0] = 0;
	this->vbo[1] = 0;
}

Model::~Model()
{
}

void Model::Set(ModelName::Name newName)
{
	this->name = newName;
}

ModelName::Name Model::Get() const
{
	return this->name;
}

