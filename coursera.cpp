#include <iostream>
#include <vector>
#include <string>
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
    for (int i = 0; i < words.size(); ++i) {
        if (IsPalindrom(words[i]) && words[i].size() >= minLength) {
            cout << words[i] << endl;
            result.push_back(words[i]);
        }
    }
    return result;
}

int main() {
    vector<string> words;
    words.push_back("abacaba");
    words.push_back("aba");
    PalindromFilter(words, 5);
    return 0;
}
