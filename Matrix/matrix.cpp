#include "matrix.h"
#include <cstring>

Matrix::Matrix(const Matrix & m) {
	this->row_count = m.row_count;
	this->col_count = m.col_count;
	this->values = new matrix_cell*[this->row_count];
	for (int i = 0; i < this->row_count; ++i) {
		this->values[i] = new matrix_cell[this->col_count];
		std::memcpy(this->values[i], m.values[i], col_count * sizeof(matrix_cell));
	}
	std::cout << "constructor2" << '\n';
} 
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

Matrix::Matrix(size_t row_count, size_t col_count):
	row_count(row_count), col_count(col_count) {
	this->values = new matrix_cell*[this->row_count];
	for (int i = 0; i < this->row_count; ++i) {
		this->values[i] = new matrix_cell[this->row_count];
	}
	std::cout << "constructor1" << '\n';
}

Matrix::~Matrix() {
	for (int i = 0; i < this->row_count; ++i)
		delete[] this->values[i];
	delete[] this->values;
}

matrix_cell Matrix::get(size_t row, size_t col) const {
	return this->values[row][col];
}

void Matrix::set(size_t row, size_t col, matrix_cell value) {
	this->values[row][col] = value;
}

std::ostream &operator<<(std::ostream &out, Matrix &matrix) {
	for (int row = 0; row < matrix.row_count; ++row) {
		for (int col = 0; col < matrix.col_count; ++col)
			out << matrix.values[row][col] << " ";
		out << std::endl;
	}
	return out;
}

std::istream &operator>>(std::istream &in, Matrix &matrix) {
	for (int row = 0; row < matrix.row_count; ++row)
		for (int col = 0; col < matrix.col_count; ++col)
			in >> matrix.values[row][col];
	return in;
}

Matrix Matrix::eye(size_t count) {
	Matrix result(count, count);
	for (int row = 0; row < count; ++row)
		for (int col = 0; col < count; ++col)
			result.values[row][col] = (col = row);
	return result;
}
	
Matrix operator+(Matrix &m1, Matrix &m2) {
	Matrix result(m1.row_count, m1.col_count);
	for (int row = 0; row < m1.row_count; ++row)
		for (int col = 0; col < m1.col_count; ++col)
			result.values[row][col] = m1.values[row][col] + m2.values[row][col];
	return result;
}