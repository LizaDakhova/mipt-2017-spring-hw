#include "BigInt.h"

int main() {
	BigInt b1("-3410378120471968421631422421");
	std::cout << b1 << std::endl;
	BigInt b2 = 214;
	std::cout << b2 << std::endl;
	BigInt b3 = b1;
	std::cout << b3 << std::endl;

	std::cout << "b1 + b2 = " << b1 + b2 << std::endl;
	std::cout << "b1 - b2 = " << b1 - b2 << std::endl;
	//std::cout << "b1 * b2 = " << b1 * b2 << std::endl;
	//std::cout << "b1 / b2 = " << b1 / b2 << std::endl;
	//std::cout << "2 * b1 = " << 2 * b1 << std::endl;

	BigInt b4;
	std::cin >> b4;
	std::cout << b4;
	system("pause"); 
	return 0;
}