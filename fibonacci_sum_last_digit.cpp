#include <iostream>
#include <vector>

const long long pisano_period_for_10 = 60;

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

int get_fibonacci_huge_fast(long long n, long long m) {
	long long r = n%pisano_period_for_10;
    return get_fibonacci_last_digit_fast(n%pisano_period_for_10, m);
}

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
	int answer = get_fibonacci_huge_fast(n + 2, 10);
	return answer != 0 ? answer - 1 : 9;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
