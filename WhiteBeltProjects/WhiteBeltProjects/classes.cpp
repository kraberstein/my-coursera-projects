#include "classes.h"
#include "coursera.h"

void SortedStrings::AddString(const string& s) {
	data_strings_.push_back(s);
	sort(begin(data_strings_), end(data_strings_));
}

vector<string> SortedStrings::GetSortedStrings() {
	return data_strings_;
}

