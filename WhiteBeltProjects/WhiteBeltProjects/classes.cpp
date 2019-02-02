#include "classes.h"

void SortedStrings::AddString(const string& s) {
	data_strings_.push_back(s);
	sort(begin(data_strings_), end(data_strings_));
}

vector<string> SortedStrings::GetSortedStrings() {
	return data_strings_;
}

void Person::ChangeFirstName(int year, const string& first_name) {
	fnames[year] = first_name;
}

void Person::ChangeLastName(int year, const string& last_name) {
	lnames[year] = last_name;
}

string Person::GetFirstName(int year) const {
	string result;
	for (const auto& name : fnames) {
		if (name.first <= year) {
			result = name.second;
		}
		else {
			break;
		}
	}
	return result;
}

string Person::GetLastName(int year) const {
	string result;
	for (const auto& name : lnames) {
		if (name.first <= year) {
			result = name.second;
		}
		else {
			break;
		}
	}
	return result;
}

string Person::GetFullName(int year) const {
	string fname, lname, result;
	
	fname = GetFirstName(year);
	lname = GetLastName(year);
	
	if (fname.empty() && lname.empty()) {
		result = "Incognito";
	}
	else if (fname.empty() && !lname.empty()) {
		result = lname + " with unknown first name";
	}
	else if (lname.empty() && !fname.empty()) {
		result = fname + " with unknown last name";
	}
	else {
		result = fname + " " + lname;
	}
	return result;
}

string Person::GetFullNameWithHistory(int year) const {
	
}
