#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

unsigned long long MaxPairwiseProductNaive(const vector<int>& numbers) {
    unsigned long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
        	if (max_product < (unsigned long long)numbers[first] * numbers[second]) {
			    max_product = (unsigned long long)numbers[first] * numbers[second];
			}

        }
    }

    return max_product;
}

unsigned long long MaxPairwiseProductFast(const vector<int>& numbers) {
    unsigned long long max_product = 0;
    int n = numbers.size();
    
	int max_index1 = -1;
    for (int i = 0; i < n; ++i) {
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1])) {
        	max_index1 = i;
		}
	}
	
	int max_index2 = -1;
	for (int i = 0; i < n; ++i) {
        if ((i != max_index1) && ((max_index2 == -1) || (numbers[i] > numbers[max_index2]))) {
        	max_index2 = i;
		}
	}

    return (unsigned long long)numbers[max_index1]*numbers[max_index2];
}

int main() {
	while (true) {
		int n = rand()%1000 + 2;
		cout << "vector size " << n << endl;
		vector<int> numbers(n);
		for (auto& num : numbers) {
			num = rand()%100'000;
			cout << num << " ";
		}
		cout << endl;
		unsigned long long naive = MaxPairwiseProductNaive(numbers);
		unsigned long long fast = MaxPairwiseProductFast(numbers);
		if (naive != fast) {
			cout << "wrong " << naive << " " << fast << endl;
			return 0;
		}
		else {
			cout << "OK\n";
		}
	}
	/*
	int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
    */
}
