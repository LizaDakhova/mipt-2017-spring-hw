#include <string>
#include <iostream>
using namespace std;

class BigInt {
private:
	const int base = 3;
	size_t size;
	bool sign_is_positive;
	int** numbers;
	void clear();
	BigInt normalize();
	BigInt sum_operation(const BigInt &) const;
	BigInt dif_operation(const BigInt &) const;
public:
	BigInt();
	BigInt(const char*);
	BigInt(const int);
	BigInt(const BigInt &);
	
	~BigInt();
	
	BigInt &operator=(const char*);
	BigInt &operator=(const int);
	BigInt &operator=(const BigInt &);

	friend int maxabs(const BigInt &, const BigInt&);
	void help_for_dif(const BigInt &, const BigInt &);

	BigInt operator+(const BigInt &) const;
	BigInt operator-(const BigInt &) const;
	//BigInt operator*(const BigInt &) const;
	//BigInt operator/(const BigInt &) const;
	//friend BigInt operator*(int, const BigInt &);

	friend std::istream &operator>>(std::istream &, BigInt &);
	friend std::ostream &operator<<(std::ostream &, const BigInt &);
};
