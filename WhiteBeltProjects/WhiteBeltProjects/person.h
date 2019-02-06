#ifndef PERSON_H
#define PERSON_H

#include "coursera.h"

struct FullName {
	FullName() {}
	explicit FullName(const string& _full_name) {
					  	full_name = _full_name;
					  }
	string full_name;
};

struct BirthDate {
	BirthDate() {}
	explicit BirthDate(const string& DD_MM_YY) {
		birth_date = DD_MM_YY;
	}
	string birth_date;
};

class Person {
public:
	Person(const string&, const string&, int);
	void ChangeFirstName(int, const string&);
  	void ChangeLastName(int, const string&);
  	string GetFullName(int) const;
  	string GetFullNameWithHistory(int) const;
private:
	string GetFirstName(int) const;
	string GetLastName(int) const;
	vector<string> FindFirstNamesHistory(int) const;
	vector<string> FindLastNamesHistory(int) const;
	map<int, string> first_names;
	map<int, string> last_names;
	int birth_year;
};

#endif /* PERSON_H */

