#include "coursera.h"

//enum MONTH { JAN = 31, FEB = 28, MAR = 31 };

map<char, int> BuildCharCounters(string str) {
	map<char, int> result;
	for (char& c : str) {
		++result[c];
	}
	return result;
}

int main() {
	//vector<string> dailyDeals(31, " ");			//		≈жедневные дела
	//vector<int> daysInMonth = { 31, 28, 30 };
	//int Q, numOfDay;
	//string operation, deal;
	//MONTH currMonth = JAN;
	//cin >> Q;
	//for (int i = 0; i != Q; ++i) {
	//	cin >> operation;
	//	if (operation == "NEXT") {

	//	}
	//	cin >> numOfDay;
	//	if (operation == "DUMP") {

	//	}
	//	cin >> deal;
	//	dailyDeals[numOfDay] += deal;
	//}

	map<char, int> first_word_char_counter;
	map<char, int> second_word_char_counter;
	string firstWord;
	string secondWord;
	int N;
	cin >> N;
	for (int i = 0; i != N; ++i) {
		cin >> firstWord >> secondWord;
		first_word_char_counter = BuildCharCounters(firstWord);
		second_word_char_counter = BuildCharCounters(secondWord);
		cout << (first_word_char_counter == second_word_char_counter ? "YES" : "NO") << endl;
	}

	return 0;
}
