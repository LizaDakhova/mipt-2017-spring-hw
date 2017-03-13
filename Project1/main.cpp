#include "Array.h"
#include <iostream>

int main() {
	B* B = new C();
	B->print();
	List* List = new ArrayList(1);
	for (int i = 0; i < 10; i++) {
		List->add(i * i);
	}
	std::cout << List->contains(3) << ' ' << List->contains(16) << std::endl;
	for (size_t i = 0; i < List->size(); ++i) {
		std::cout << List->get(i) << std::endl;
	}
	system("pause");
	return 0;
}