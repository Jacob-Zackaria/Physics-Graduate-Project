#ifndef CUBE_MODEL_H
#define CUBE_MODEL_H

#include "Model.h"

class CubeModel : public Model
{
public:
	CubeModel( const char * const modelFileName );
	~CubeModel();

	// tells the compiler do not create or allow it to be used, c++11
	CubeModel(const CubeModel &) = delete;
	CubeModel& operator=(const CubeModel & other) = delete;

private:
	void privCreateVAO( const char * const modelFileName  ) override;



};

#endif