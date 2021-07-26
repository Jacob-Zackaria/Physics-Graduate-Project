#ifndef MODEL_H
#define MODEL_H

#include "MathEngine.h"
#include "sb6.h"
#include "EnumBase.h"

class Model
{
public:
	Model(ModelName::Name newName);
	virtual ~Model();
	void Set(ModelName::Name newName);
	ModelName::Name Get() const;
// Data
	int numVerts;
	int numTris;

	GLuint vao;
	GLuint vbo[2];

private:
	// load VAO
	virtual void privCreateVAO( const char * const modelFileName  ) = 0;

	ModelName::Name name;

	// prevent from copying
	Model( Model &copyModel );
	Model & operator = (Model &copyModel);
};

#endif