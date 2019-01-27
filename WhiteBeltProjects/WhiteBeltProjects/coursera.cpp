#include "coursera.h"

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

bool IsPalindrom(string str) {
    for (int i = 1; i <= str.size()/2 + 1; ++i) {
        if (str[i - 1] != str[str.size() - i]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter (const vector<string>& words,
                                int minLength) {
    vector<string> result;
    for (auto s : words) {
        if (IsPalindrom(s) && s.size() >= minLength) {
            cout << s << endl;
            result.push_back(s);
        }
    }
    return result;
}

void UpdateIfGreater(int first, int& second) {
	if (first > second) {
		second = first;
	}
}

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto s : source) {
		destination.push_back(s);
	}
	source.clear();
}

void Reverse(vector<int>& v) {
	for (int i = 1; i < v.size()/2 + 1; ++i) {
		swap(v[i - 1], v[v.size() - i]);
	}
}

vector<int> Reversed(const vector<int>& v) {
	vector<int> result = v;
	Reverse(result);
	return result;
}
