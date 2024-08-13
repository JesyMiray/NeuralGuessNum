#include "Network.h"

void Network::Init(data_Network data) {
	actFunc.set();
	srand(time(NULL));
	L = data.L;
	size = new int[L];
	for (int i = 0; i < L; i++)
		size[i] = data.size[i];
	weights = new Matrix[L - 1];
	bios = new double* [L - 1];
	for (int i = 0; i < L - 1; i++) {
		weights[i].Init(size[i + 1], size[i]);
		bios[i] = new double[size[i + 1]];
		weights[i].Rand();
		for (int j = 0; j < size[i + 1]; j++)
			bios[i][j] = ((rand() % 50)) * 0.06 / (size[i] + 15.);
	}
	neurons_val = new double* [L];
	neurons_err = new double* [L];
	for (int i = 0; i < L; i++) {
		neurons_val[i] = new double[size[i]];
		neurons_err[i] = new double[size[i]];
	}
	neurons_bios_val = new double[L - 1];
	for (int i = 0; i < L - 1; i++)
		neurons_bios_val[i] = 1;
}
void Network::PrintConfig() {
	cout << "*********************************************\n";
	cout << "Num of Network layers: " << L << "\nSize[]: ";
	for (int i = 0; i < L; i++)
		cout << size[i] << " ";
	cout << "*********************************************\n\n";
}
void Network::SetInput(double* values) {
	for (int i = 0; i < size[0]; i++)
		neurons_val[0][i] = values[i];
}

double Network::ForwardFeed() {
	for (int k = 1; k < L; ++k) {
		Matrix::MatMulti(weights[k - 1], neurons_val[k - 1], neurons_val[k], size[k-1]);
		Matrix::SumVec(neurons_val[k], bios[k - 1], size[k]);
		actFunc.use(neurons_val[k], size[k]);
	}
	int pred = SearchMaxIndex(neurons_val[L - 1]);
	return pred;
}

int Network::SearchMaxIndex(double* value) {
	double max = value[0];
	int predict = 0;
	double temp;
	for (int j = 0; j < size[L - 1]; j++) {
		temp = value[j];
		if (temp > max) {
			predict = j;
			max = temp;
		}
	}
	return predict;
}
void Network::PrintValues(int L) {
	for (int j = 0; j < size[L]; j++)
		cout << j << " " << neurons_val[L][j] << endl; 
}




















