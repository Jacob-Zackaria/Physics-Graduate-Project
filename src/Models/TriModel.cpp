#include <sb6.h>
#include <math.h>
#include <assert.h>

#include "AzulHelper.h"
#include "TriModel.h"
#include "SpriteVBO.h"

#define TRI_NUM_VERTS 3

void TriModel::privCreateVAO(const char * const modelFileName)
{
	// future proofing it for a file
	AZUL_UNUSED(modelFileName);

	this->numVerts = TRI_NUM_VERTS;
	Vert_xyz TriData[TRI_NUM_VERTS] =
	{
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f }
	};

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
	glBufferData(GL_ARRAY_BUFFER, (int)sizeof(Vert_xyz) * this->numVerts, TriData, GL_STATIC_DRAW);

	// Vertext data in location 0
	void *offsetVert = (void *)((unsigned int)&TriData[0].x - (unsigned int)TriData);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert_xyz), offsetVert);
	glEnableVertexAttribArray(0);
}


TriModel::TriModel(const char * const modelFileName)
	: Model(ModelName::Name::Tri)
{
	this->privCreateVAO(modelFileName);
}

TriModel::~TriModel()
{
	// remove anything dynamic here
}