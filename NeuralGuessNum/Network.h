#pragma once
#include "FuncActivate.h"
#include "Matrix.h"
using namespace std;


struct data_Network {

};

class Network {
	int L; 
	int* size;
	FuncActivate actFunc;
	Matrix* weights;
	double** bios;
	double** neurons_val, ** neurons_err;
	double* neurons_bios_val;

public:
	void Init(data_Network data);

};

