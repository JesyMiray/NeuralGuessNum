#include "Matrix.h"

void Matrix::Init(int row, int column) {
	this->row = row; this->column = column;
	matrix = new double* [row];
	for (int i = 0; i < row; i++)
		matrix[i] = new double[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = 0;
}
void Matrix::Rand() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = ((rand() % 100) * 0.03 / (row + 35.0));
}
void Matrix::MatMulti(const Matrix& m1, const double* neuron, double* res, int n) {
	if (m1.column != n)
		throw std::runtime_error("Error MatMulti:\n m row =/ neuron column\n");

	for (int i = 0; i < m1.row; i++) {
		double temp = 0;
		for (int j = 0; j < m1.column; j++) {
			temp += m1.matrix[i][j] * neuron[j];
		}
		res[i] = temp;
	}
}
void Matrix::MatMultiT(const Matrix& m1, const double* neuron, double* res, int n) {
	if (m1.row != n)
		throw std::runtime_error("Error MatMultiT:\n");
	for (int i = 0; i < m1.column; ++i) {
		double temp = 0;
		for (int j = 0; j < m1.row; ++j)
			temp += m1.matrix[j][i] * neuron[j];
		res[i] = temp;
	}
}
void Matrix::SumVec(double* a, double* b, int n) {
	for (int i = 0; i < n; i++)
		a[i] += b[i];
}
double& Matrix::operator()(int i, int j) {
	return matrix[i][j];
}