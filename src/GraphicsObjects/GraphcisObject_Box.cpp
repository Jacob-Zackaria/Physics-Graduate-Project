#include <assert.h>

#include "GraphicsObject_Box.h"
#include "Model.h"
#include "Camera.h"
#include "CameraMan.h"
#include "ShaderMan.h"
#include "ModelMan.h"

GraphicsObject_Box::GraphicsObject_Box( Rect rect)
	: GraphicsObject(ModelMan::GetModel(ModelName::Name::Box), ShaderMan::findShader(ShaderName::Name::SPRITE_LINE) ) 
{
	assert(rect.width > 0);
	assert(rect.height > 0);

	this->origWidth = rect.width;
	this->origHeight = rect.height;

	this->origPosX = rect.x;
	this->origPosY = rect.y;

	// Create the orig Matrix 
	// The initial sprite setup, after this point standard world will adjust
	this->pMatrix_orig = new Matrix();

	Matrix Scale(MatrixScaleType::SCALE, this->origWidth, this->origHeight, 1.0f);
	*this->pMatrix_orig = Scale;

	this->color = Color::Type::Yellow;
}

GraphicsObject_Box::~GraphicsObject_Box()
{
	delete pMatrix_orig;
}


void GraphicsObject_Box::SetState()
{
	// comment out one
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glFrontFace(GL_CW);

	// Blends for sprites
	glEnable(GL_BLEND);
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
}

void GraphicsObject_Box::SetDataGPU()
{
	// Get camera
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);

	// set the vao
	glBindVertexArray(this->getModel()->vao);

	// use this shader
	this->pShaderObj->SetActive();

	// World matrix ----------------------------
	Matrix TransToOriginLowerLeft(TRANS, -pCam->getScreenWidth() / 2.0f, -pCam->getScreenHeight() / 2.0f, 0.0f);
	Matrix tmpMatrix = *this->pMatrix_orig * this->getWorld() * TransToOriginLowerLeft;

	glUniformMatrix4fv(this->pShaderObj->GetLocation("proj_matrix"), 1, GL_FALSE, (float *)&pCam->getProjMatrix());
	glUniformMatrix4fv(this->pShaderObj->GetLocation("view_matrix"), 1, GL_FALSE, (float *)&pCam->getViewMatrix());
	glUniformMatrix4fv(this->pShaderObj->GetLocation("world_matrix"), 1, GL_FALSE, (float *)&tmpMatrix);

	//Vect c(255.0f, 255.0f, 0.0f, 255.0f);
	Color c(this->color);
	Vect cval(c);
	glUniform4fv(this->pShaderObj->GetLocation("input_Color"), 1, (float *) &cval );

}

void GraphicsObject_Box::Draw()
{
	// draw
	glDrawArrays(GL_LINE_LOOP, 0, this->getModel()->numVerts);
}

void GraphicsObject_Box::RestoreState()
{
	glDisable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}
