#ifndef TRI_MODEL_H
#define TRI_MODEL_H

#include "Model.h"

class TriModel : public Model
{
public:
	TriModel(const char * const modelFileName);
	~TriModel();

	// tells the compiler do not create or allow it to be used, c++11
	TriModel(const TriModel &) = delete;
	TriModel& operator=(const TriModel & other) = delete;

private:
	void privCreateVAO(const char * const modelFileName) override;

};

#endif