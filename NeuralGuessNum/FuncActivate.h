#pragma once
#include <iostream>
enum funcActivate { sigmoid = 1, ReLU, thx};

class FuncActivate {
	funcActivate actFunc;
public:
	void set();
	void use(double* value, int n);
	void useDer(double* value, int n);
	double useDer(double value);
};

