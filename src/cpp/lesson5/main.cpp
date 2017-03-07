//
// Created by dmitry on 3/7/17.
//

int main() {
    BigInt b1("1037812047196842163142241");
    BigInt b2 = 214;

    std::cout << "b1 + b2 = " << b1 + b2 << std::endl;
    std::cout << "b1 - b2 = " << b1 - b2 << std::endl;
    std::cout << "b1 * b2 = " << b1 * b2 << std::endl;
    std::cout << "b1 / b2 = " << b1 / b2 << std::endl;
    std::cout << "2 * b1 = " << 2 * b1 << std::endl;
}