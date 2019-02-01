#include "coursera.h"

class SortedStrings {
public:
  	void AddString(const string&);
  	vector<string> GetSortedStrings();
private:
  	vector<string> data_strings_;
};

class Person {
public:
	void ChangeFirstName(int, const string&);
  	void ChangeLastName(int, const string&);
  	string GetFullName(int) const;
  	string GetFullNameWithHistory(int) const;
private:
	string GetFirstName(int) const;
	string GetLastName(int) const;
	map<int, string> fnames;
	map<int, string> lnames;
};
