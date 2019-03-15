#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd_fast(b, a%b);
	}
}

void test() {
	for (int i = 1; i <= 100; ++i){
		for (int j = 1; j <= 100; ++j) {
			assert(gcd_naive(i, j) == gcd_fast(i, j));
		}
	}
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  	return 0;
}
