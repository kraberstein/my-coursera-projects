#include <iostream>

int gcd_fast(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd_fast(b, a%b);
	}
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

unsigned long long lcm_fast(int a, int b) {
	return ((unsigned long long)a*b)/gcd_fast(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
