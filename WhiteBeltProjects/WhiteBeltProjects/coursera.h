#ifndef COURSERA_H_
#define COURSERA_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int& gcd(const int& a, const int& b);		/* calculate greatest
 	 	 	 	 	 	 	 	 	 	 	 	 * common divisor (gcd) */

void binary_integer(int number);				/* convert integer
 	 	 	 	 	 	 	 	 	 	 	 	 * to binary */

bool IsPalindrom(string str);

vector<string> PalindromFilter(const vector<string>& words,
                                int minLength);

void UpdateIfGreater(int first, int& second);

void MoveStrings(vector<string>&, vector<string>&);

void Reverse(vector<int>&);

vector<int> Reversed(const vector<int>& v);

#endif /* COURSERA_H_ */
