#include "FuncActivate.h"

void FuncActivate::set() {
	std::cout << "set func\n1 - sigmoid \n2 - ReLU \n3 - th(x) \n";
	int temp; 
	std::cin >> temp;
	switch (temp) {
		case sigmoid: actFunc = sigmoid; break;
		case ReLU:	  actFunc = ReLU;	 break;
		case thx:	  actFunc = thx;	 break;
		default: throw std::runtime_error("Error read function\n"); break;
	}
}
void FuncActivate::use(double* value, int n) {
	switch (actFunc) {
		case funcActivate::sigmoid:
			for (int i = 0; i < n; i++)
				value[i] = 1. / (1. + exp(-value[i]));
			break;
		case funcActivate::ReLU:
			for (int i = 0; i < n; i++) {
				if (value[i] < 0)
					value[i] *= 0.01;
				else if (value[i] > 1)
					value[i] = 1. + 0.01 * (value[i] - 1.);
			}
			break;
		case funcActivate::thx:
			for (int i = 0; i < n; i++) {
				if (value[i] < 0)
					value[i] = 0.01 * (exp(value[i]) - exp(-value[i])) / (exp(value[i]) + exp(-value[i]));
				else 
					value[i] = (exp(value[i]) - exp(-value[i]))/(exp(value[i]) + exp(-value[i]));
			}
			break;
		default: throw std::runtime_error("Error activate function\n");
			break;
	}
}
void FuncActivate::useDer(double* value, int n) {
	switch (actFunc) {
	case funcActivate::sigmoid:
		for (int i = 0; i < n; i++)
			value[i] = value[i] * (1 - value[i]);
		break;
	case funcActivate::ReLU:
		for (int i = 0; i < n; i++) {
			if (value[i] < 0 || value[i] > 1)
				value[i] = 0.01;
			else
				value[i] = 1;
		}
		break;
	case funcActivate::thx:
		for (int i = 0; i < n; i++) {
			if (value[i] < 0)
				value[i] = 0.01 * (1 - value[i] * value[i]);
			else
				value[i] = 1 - value[i] * value[i];
		}
		break;
	default: throw std::runtime_error("Error activate der function\n");
		break;
	}
}
double FuncActivate::useDer(double value) {
	switch (actFunc) {
	case funcActivate::sigmoid:
		value =  1 / (1 + exp(-value));
		break;
	case funcActivate::ReLU:
		if (value < 0 || value > 1)
			value = 0.01;
		break;
	case funcActivate::thx:
			if (value < 0)
				value = 0.01 * (exp(value) - exp(-value)) / (exp(value) + exp(-value));
			else
				value = (exp(value) - exp(-value)) / (exp(value) + exp(-value));
		break;
	default: throw std::runtime_error("Error activate der function\n");
		break;
	}
	return value;
}
 