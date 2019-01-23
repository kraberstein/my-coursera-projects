//============================================================================
// Name        : coursera.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

const int& nod(const int& a, const int& b) {
	if (a == 0 || (a == 0 && b == 0))
		return b;
	if (b == 0)
		return a;
	return nod(b, a%b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << nod(a, b);
	return 0;
}
