#ifndef BOX_MODEL_H
#define BOX_MODEL_H

#include "Model.h"

class BoxModel : public Model
{
public:
	BoxModel(const char * const modelFileName);
	~BoxModel();

	// tells the compiler do not create or allow it to be used, c++11
	BoxModel(const BoxModel &) = delete;
	BoxModel& operator=(const BoxModel & other) = delete;

private:
	void privCreateVAO(const char * const modelFileName) override;



};

#endif