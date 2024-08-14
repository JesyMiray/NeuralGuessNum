#pragma once
#include "FuncActivate.h"
#include "Matrix.h"
#include <fstream>
using namespace std;


struct data_Network {
	int L;
	int* size;
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
	void PrintConfig();
	void SetInput(double* values);
	double ForwardFeed();
	int SearchMaxIndex(double* value);
	void PrintValues(int L);
	void BackPropogation(double expect);
	void WeightUpdater(double lr);
	void SaveWeights();
	void ReadWeights();
};

