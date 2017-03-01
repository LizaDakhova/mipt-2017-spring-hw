#include <iostream>
typedef int matrix_cell;
class Matrix {
private:
	size_t row_count;
	size_t col_count;
	matrix_cell** values;
public:
	Matrix(const Matrix&);
	Matrix(size_t, size_t);
	~Matrix();

	matrix_cell get(size_t, size_t) const;
	void set(size_t, size_t, matrix_cell);

	friend std::ostream &operator<<(std::ostream &, Matrix &);
	friend std::istream &operator>>(std::istream &, Matrix &);

	static Matrix eye(size_t);
	static Matrix eye(size_t, int, ...);
	static Matrix eye_conversely(size_t);

	friend Matrix operator+(Matrix &, Matrix &);
	friend Matrix operator+(Matrix &, int);
	friend Matrix operator*(Matrix &, Matrix &);
	friend Matrix operator*(Matrix &, int);

}; 