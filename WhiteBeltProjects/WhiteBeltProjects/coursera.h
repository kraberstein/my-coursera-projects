#ifndef COURSERA_H
#define COURSERA_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <exception>
#include <system_error>
using namespace std;

const int& gcd(const int& a, const int& b);		/* calculate greatest
 	 	 	 	 	 	 	 	 	 	 	 	 * common divisor (gcd) */

void binary_integer(int number);				/* convert integer
 	 	 	 	 	 	 	 	 	 	 	 	 * to binary */

//bool IsPalindrom(string str);

vector<string> PalindromFilter(const vector<string>& words,
                                int minLength);

void UpdateIfGreater(int first, int& second);

void MoveStrings(vector<string>&, vector<string>&);

void Reverse(vector<int>&);

vector<int> Reversed(const vector<int>&);

// working with read and write files
void ReadAll(const string& path);
void WriteAll(const string& ipath, const string& opath);

// print in standart output with manilulators <iomanip>
void Print(const vector<string>& names, const vector<double>& values,
		   int width);

#endif /* COURSERA_H */
