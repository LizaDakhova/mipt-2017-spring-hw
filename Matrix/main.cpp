#include "matrix.h"
#include <iostream>

int main() {
	Matrix a(2, 2);
	std::cin >> a;
	std::cout << a;
	Matrix b(a);
	std::cout << b;
	std::cout << a + b;
	system("pause");
	return 0;
}