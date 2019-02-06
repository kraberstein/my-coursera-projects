#ifndef CLASSES_H
#define CLASSES_H

#include "coursera.h"

class SortedStrings {
public:
  	void AddString(const string&);
  	vector<string> GetSortedStrings();
private:
  	vector<string> data_strings_;
};

class ReversibleString {
public:
	ReversibleString() {}
	ReversibleString(const string& str) : data(str) {}
	string ToString() const { return data; }
	void Reverse() { reverse(data.begin(), data.end()); }
private:
	string data;
};

#endif /* CLASSES_H */

