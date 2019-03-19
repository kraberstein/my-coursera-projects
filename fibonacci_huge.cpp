#include <iostream>

int get_fibonacci_last_digit_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }

    return current;
}

size_t get_pisano_period_size(long long m) {
	long long f_1 = 0;
	long long f_2 = 1;
	long long fn;
	for (int i = 0; i <= m*m; ++i) {
		fn = (f_1 + f_2)%m;
		f_1 = f_2;
		f_2 = fn;
		if (f_1 == 0 && f_2 == 1) {
			return i + 1;
		}
	}
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

unsigned long long get_fibonacci_huge_fast(long long n, long long m) {
    return get_fibonacci_last_digit_fast(n%get_pisano_period_size(m), m);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}

