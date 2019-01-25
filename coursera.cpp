#include <iostream>
#include <vector>
using namespace std;

const int& gcd(const int& a, const int& b) {	//	*** *** *** *** calculate greatest common divisor (gcd)
	if (a == 0 || (a == 0 && b == 0))
		return b;
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

void binary_integer(int number) {	//	*** *** *** *** convert integer to binary
	cout << number << " in binary code = ";
	vector<int> bin_int;
	while (number > 0) {
		bin_int.push_back(number%2);
		number /= 2;
	}
	for (int i = bin_int.size() - 1; i >= 0; --i) {
		cout << bin_int[i];
	}
	cout << endl;
}

int main() {
	binary_integer(5);
	gcd(52, 25);

	return 0;
}
