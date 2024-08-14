#pragma once
#include <iostream>

class Matrix {
	double** matrix; 
	int row, column;

public:
	void Init (int row, int column);
	void Rand();
	static void MatMulti(const Matrix& m, const double* b, double *res, int n);
	static void MatMultiT(const Matrix& m, const double* b, double* res, int n);
	static void SumVec(double *a, double *b, int n);
	double& operator ()(int i, int j);
	friend std::ostream& operator << (std::ostream& os, const Matrix& m);
	friend std::istream& operator >> (std::istream& is, Matrix& m);
};

