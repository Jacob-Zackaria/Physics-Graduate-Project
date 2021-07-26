#ifndef CIRCLE_MODEL_H
#define CIRCLE_MODEL_H

#include "Model.h"

class CircleModel : public Model
{
public:
	CircleModel(const char * const modelFileName);
	~CircleModel();

	// tells the compiler do not create or allow it to be used, c++11
	CircleModel(const CircleModel &) = delete;
	CircleModel& operator=(const CircleModel & other) = delete;

private:
	void privCreateVAO(const char * const modelFileName) override;



};

#endif