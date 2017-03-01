#include "matrix.h"
#include <iostream>

int main() {
	Matrix a(2, 2);
	std::cin >> a;
	std::cout << "a" << '\n' << a;
	Matrix b(a);
	std::cout << "b" << '\n' << b;
	std::cout << "a + b" << '\n' << a + b;
	int n = 6;
	std::cout << "a + " << n << '\n' << a + n;
	std::cout << "a * b" << '\n' << a * b;
	int k = 2;
	std::cout << "a * " << k << '\n' << a * k;
	int count = 3;
	std::cout << "eye(" << count << ")" << '\n' << Matrix::eye(count);
	std::cout << "eye(2, 1 3)" << '\n' << Matrix::eye(2, 1, 3);
	std::cout << "eye_conversely(" << count << ")" << '\n' << Matrix::eye_conversely(count);
	system("pause");
	return 0;
}