#include <sb6.h>
#include <math.h>
#include <assert.h>

#include "AzulHelper.h"
#include "CircleModel.h"
#include "SpriteVBO.h"

#define CIRCLE_NUM_VERTS 24

void CircleModel::privCreateVAO(const char * const modelFileName)
{
	// future proofing it for a file
	AZUL_UNUSED(modelFileName);

	this->numVerts = CIRCLE_NUM_VERTS;
	Vert_xyz CircleData[CIRCLE_NUM_VERTS];

	float radius =  0.5f;
	float stepAngle = MATH_2PI / (float)this->numVerts;

	for (int i = 0; i < this->numVerts; i++)
	{
		float angle = (float)i * stepAngle;
		CircleData[i].x = cosf(angle) * radius;
		CircleData[i].y = sinf(angle) * radius;
		CircleData[i].z = 0.0f;
	}

	// Create a VAO
	glGenVertexArrays(1, &this->vao);
	assert(this->vao != 0);
	glBindVertexArray(this->vao);

	// Create a VBO
	glGenBuffers(1, &this->vbo[0]);
	assert(this->vbo[0] != 0);

	// needed since we reserved 2 VBOs, but only using one
	this->vbo[1] = 0;

	// Load the combined data: ---------------------------------------------------------
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo[0]);

	// load the data to the GPU
	glBufferData(GL_ARRAY_BUFFER, (int)sizeof(Vert_xyz) * this->numVerts, CircleData, GL_STATIC_DRAW);

	// Vertext data in location 0
	void *offsetVert = (void *)((unsigned int)&CircleData[0].x - (unsigned int)CircleData);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert_xyz), offsetVert);
	glEnableVertexAttribArray(0);
}


CircleModel::CircleModel(const char * const modelFileName)
	: Model(ModelName::Name::Circle)
{
	this->privCreateVAO(modelFileName);
}

CircleModel::~CircleModel()
{
	// remove anything dynamic here
}