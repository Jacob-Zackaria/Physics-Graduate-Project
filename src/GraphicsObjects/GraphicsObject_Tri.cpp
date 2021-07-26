#include <assert.h>

#include "GraphicsObject_Tri.h"
#include "Model.h"
#include "Camera.h"
#include "CameraMan.h"
#include "ShaderMan.h"
#include "ModelMan.h"

GraphicsObject_Tri::GraphicsObject_Tri( Vect2D _originPoint, Vect2D *verts)
	: GraphicsObject(ModelMan::GetModel(ModelName::Name::Tri), ShaderMan::findShader(ShaderName::Name::SPRITE_TRI))
{
	this->originPt = _originPoint;

	this->originVerts[0] = verts[0];
	this->originVerts[1] = verts[1];
	this->originVerts[2] = verts[2];

	this->origWidth = 1.0f;
	this->origHeight = 1.0f;

	// Create the orig Matrix 
	// The initial sprite setup, after this point standard world will adjust
	this->pMatrix_orig = new Matrix();

	Matrix Scale(MatrixScaleType::SCALE, this->origWidth, this->origHeight, 1.0f);
	*this->pMatrix_orig = Scale;

	this->color = Color::Type::Yellow;
}

GraphicsObject_Tri::~GraphicsObject_Tri()
{
	delete this->pMatrix_orig;
}


void GraphicsObject_Tri::SetState()
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

void GraphicsObject_Tri::SetDataGPU()
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

	Matrix m;
	m.M0() = this->originVerts[0].x - this->originPt.x;
	m.M1() = this->originVerts[0].y - this->originPt.y;
	m.M4() = this->originVerts[1].x - this->originPt.x;
	m.M5() = this->originVerts[1].y - this->originPt.y;
	m.M8() = this->originVerts[2].x - this->originPt.x;
	m.M9() = this->originVerts[2].y - this->originPt.y;

	glUniformMatrix4fv(this->pShaderObj->GetLocation("data_matrix"), 1, GL_FALSE, (float *)&m);


	Color c(this->color);
	Vect cval(c);
	glUniform4fv(this->pShaderObj->GetLocation("input_Color"), 1, (float *)&cval);

}

void GraphicsObject_Tri::Draw()
{
	// draw
	glDrawArrays(GL_LINE_LOOP, 0, this->getModel()->numVerts);
}

void GraphicsObject_Tri::RestoreState()
{
	glDisable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}
