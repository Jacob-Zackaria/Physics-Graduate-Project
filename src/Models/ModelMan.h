#ifndef MODEL_MAN_H
#define MODEL_MAN_H

#include "SpriteModel.h"
#include "CircleModel.h"
#include "BoxModel.h"
#include "TriModel.h"

// Singleton
class ModelMan
{
public:

	static Model *GetModel(ModelName::Name name);
	static void Terminate();
	static void Create();

private:  // methods

	static ModelMan *privGetInstance();
	ModelMan();
	
private:  // add

	SpriteModel *pSpriteModel; 
	CircleModel *pCircleModel; 
	BoxModel    *pBoxModel; 
	TriModel    *pTriModel; 

};


#endif