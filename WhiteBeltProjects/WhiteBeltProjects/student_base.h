#ifndef STUDENT_BASE_H
#define STUDENT_BASE_H

#include "coursera.h"
#include "person.h"

struct Student {
	Student(const FullName& name_surname,
					 const BirthDate& DD_MM_YY) {
						full_name = name_surname;
						birth_date = DD_MM_YY;
					 }
	string getFullName() const {
		return full_name.full_name;
	}
	string getBirthDate() const {
		return birth_date.birth_date;
	}
private:
	FullName full_name;
	BirthDate birth_date;
};

#endif /* STUDENT_BASE_H */

