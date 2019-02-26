#include "coursera.h"

class Date {
public:
	Date() {}
	Date(int _year, int _month, int _day): year(_year), 
										   month(_month), 
										   day(_day) {}
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& ldate, const Date& rdate);

class Database {
public:
	void AddEvent(const Date& date, const string& event);
	bool DeleteEvent(const Date& date, const string& event);
	int  DeleteDate(const Date& date);
	void Find(const Date& date) const;
	void Print() const;
private:
	map<Date, set<string>> date_and_event;
};
