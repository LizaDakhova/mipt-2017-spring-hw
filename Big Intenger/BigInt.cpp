#include "BigInt.h"
#include <cstdio>
#include <cstdlib>
int len_n(int n) {
	int len = 0;
	while (n) {
		n /= 10;
		++len;
	}
	return len;
}

BigInt::BigInt() {
	numbers = new int*[10];
	for (int i = 0; i < 10; ++i) {
		numbers[i] = new int[base];
		for (int j = 0; j < base; ++j)
			numbers[i][j] = 0;
	}
	size = 10;
	sign_is_positive = true;
}

BigInt::BigInt(const char* s) {
	int lens; 
	int index_s;
	if (s[0] == '-') {
		lens = strlen(s) - 1;
		sign_is_positive = false;
		index_s = 1;
	}
	else {
		lens = strlen(s);
		sign_is_positive = true;
		index_s = 0;
	}
	size = (lens - 1) / base + 1;
	numbers = new int*[size];
	for (int i = 0; i < size; ++i) {
		numbers[i] = new int[base];
		for (int j = 0; j < base; ++j)
			if (i == 0 && j < (size * base - lens))
				numbers[i][j] = 0;
			else {
				numbers[i][j] = s[index_s] - 48;
				++index_s;
			}
	}
}

BigInt::BigInt(const int n) {
	int m;
	if (n >= 0) {
		sign_is_positive = true;
		m = n;
	}
	else {
		sign_is_positive = false;
		m = -n;
	}
	int lenn = len_n(n);
	size = (lenn - 1) / base + 1;
	numbers = new int*[size];
	int power10 = 1;
	for (int i = 1; i < lenn; ++i) power10 *= 10;
	for (int i = 0; i < size; ++i) {
		numbers[i] = new int[base];
		for (int j = 0; j < base; ++j)
			if (i == 0 && j < (size * base - lenn))
				numbers[i][j] = 0;
			else {
				numbers[i][j] = m / power10;
				m %= power10;
				power10 /= 10;
			}
	}
}

BigInt::BigInt(const BigInt &that) {
	this->size = that.size;
	this->sign_is_positive = that.sign_is_positive;
	this->numbers = new int*[this->size];
	for (int i = 0; i < this->size; ++i) {
		this->numbers[i] = new int[this->base];
		for (int j = 0; j < this->base; ++j)
			this->numbers[i][j] = that.numbers[i][j];
	}
}

BigInt::~BigInt() {
	clear();
}

void BigInt::clear() {
	for (int i = 0; i < size; ++i)
		delete[] numbers[i];
	delete[] numbers;
}

BigInt &BigInt::operator=(const char* s) {
	BigInt result(s);
	return result;
}

BigInt &BigInt::operator=(const int n) {
	BigInt result(n);
	return result;
}

BigInt &BigInt::operator=(const BigInt &bg) {
	BigInt result(bg);
	return result;
}
 
size_t max(size_t size1, size_t size2) {
	if (size1 > size2)
		return size1;
	else
		return size2;
}

BigInt BigInt::normalize() {
	int i = 0, j = 0, count = 0;
	while (this->numbers[i][j] == 0) {
		if (j == this->base - 1) {
			++i;
			j = 0;
		}
		else
			++j;
	}
	BigInt bg;
	if (i > 0) {
		bg.sign_is_positive = this->sign_is_positive;
		bg.size = this->size - i;
		bg.numbers = new int*[bg.size];
		for (int k = 0; k < bg.size; ++k) {
			bg.numbers[k] = new int[this->base];
			for (int m = 0; m < this->base; ++m) {
				bg.numbers[k][m] = this->numbers[k + i][m];
			}
		}
		return bg;
	}
	else
		return *this;
}

int maxabs(const BigInt  &bg0, const BigInt &bg1) {
	if (bg0.size > bg1.size) return 0;
	else if (bg1.size > bg0.size) return 1;
	else {
		int result = 0;
		for (int i = 0; i < bg0.size; ++i) {
			for (int j = 0; j < bg0.base; ++j) {
				if (bg0.numbers[i][j] > bg1.numbers[i][j]) {
					result = 0;
					break;
				}
				else if (bg1.numbers[i][j] > bg0.numbers[i][j]) {
					result = 1;
					break;
				}
			}
		}
		return result;
	}
}

BigInt BigInt::sum_operation(const BigInt &that) const {
	BigInt sum;
	if (this->sign_is_positive)
		sum.sign_is_positive = true;
	else
		sum.sign_is_positive = false;
	sum.size = max(this->size, that.size) + 1;
	sum.numbers = new int*[sum.size];
	int this_index = this->size - 1;
	int that_index = that.size - 1;
	int dozen = 0;
	for (int i = sum.size - 1; i >= 0; --i) {
		sum.numbers[i] = new int[base];
		if (this_index >= 0 && that_index >= 0) {
			for (int j = base - 1; j >= 0; --j) {
				sum.numbers[i][j] = (this->numbers[this_index][j] + that.numbers[that_index][j]) % 10 + dozen;
				dozen = (this->numbers[this_index][j] + that.numbers[that_index][j]) / 10;
			}
			--this_index;
			--that_index;
		}
		else if (this_index >= 0) {
			for (int j = base - 1; j >= 0; --j) {
				sum.numbers[i][j] = this->numbers[this_index][j] + dozen;
				dozen = 0;
			}
			--this_index;
		}
		else if (that_index >= 0) {
			for (int j = base - 1; j >= 0; --j) {
				sum.numbers[i][j] = that.numbers[that_index][j] + dozen;
				dozen = 0;
			}
			--that_index;
		}
		else {
			for (int j = base - 1; j >= 0; --j) {
				sum.numbers[i][j] = dozen;
				dozen = 0;
			}
		}
	}
	BigInt result = sum.normalize();
	return result;
}

BigInt BigInt::dif_operation(const BigInt &that) const{
	BigInt dif;
	BigInt bg0 = *this;
	BigInt bg1 = that;
	dif.size = max(bg0.size, bg1.size);
	if (maxabs(bg0, bg1) == 0) {
		dif.help_for_dif(bg0, bg1);
		dif.sign_is_positive = bg0.sign_is_positive;
	}
	else {
		dif.help_for_dif(bg1, bg0);
		dif.sign_is_positive = bg1.sign_is_positive;
	}
	BigInt result = dif.normalize();
	return result;
}

BigInt BigInt::operator+(const BigInt &that) const {
	if (this->sign_is_positive == that.sign_is_positive) {
		return sum_operation(that);
	}
	else
		return dif_operation(that);
}

void BigInt::help_for_dif(const BigInt &bg0, const BigInt &bg1) {
	int dozen = 0;
	int bg1_index = bg1.size - 1;
	for (int i = size - 1; i >= 0; --i) {
		if (bg1_index >= 0) {
			for (int j = base - 1; j >= 0; --j) {
				if (bg0.numbers[i][j] > bg1.numbers[bg1_index][j]) {
					numbers[i][j] = bg0.numbers[i][j] - bg1.numbers[bg1_index][j] - dozen;
					dozen = 0;
				}
				else {
					numbers[i][j] = 10 + bg0.numbers[i][j] - bg1.numbers[bg1_index][j] - dozen;
					dozen = 1;
				}
			}
			--bg1_index;
		}
		else {
			for (int j = base - 1; j >= 0; --j) {
				this->numbers[i][j] = bg0.numbers[i][j] - dozen;
				dozen = 0;
			}
		}
	}
}

BigInt BigInt::operator-(const BigInt &that) const {
	if (this->sign_is_positive != that.sign_is_positive) {
		return sum_operation(that);
	}
	else
		return dif_operation(that);
}

//BigInt BigInt::operator*(const BigInt &that) const {
//
//}
//  
//BigInt BigInt::operator/(const BigInt & that) const{
//
//}
//
//BigInt operator*(int, const BigInt &) {
//
//}
//

std::ostream &operator<<(std::ostream &out, const BigInt &bg) {
	int j = 0;
	bg.sign_is_positive ? out << "" : out << "-";
	while (bg.numbers[0][j] == 0) ++j;
	for (int i = 0; i < bg.size; ++i) {
		for (; j < bg.base; ++j)
			out << bg.numbers[i][j];
		j = 0;
	}
	return out;
}