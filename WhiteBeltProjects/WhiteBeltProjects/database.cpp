#include "database.h"

int Date::GetYear() const {
	return year;
}

int Date::GetMonth() const {
	return month;
}

int Date::GetDay() const {
	return day;
}

bool operator<(const Date& ldate, const Date& rdate) {
	if (ldate.GetYear() < rdate.GetYear()) {
		return true;
	} else if (ldate.GetYear() > rdate.GetYear()){
		return false;
	}
	if (ldate.GetMonth() < rdate.GetMonth()) {
		return true;
	} else if (ldate.GetMonth() > rdate.GetMonth()){
		return false;
	}
	if (ldate.GetDay() < rdate.GetDay()) {
		return true;
	} else if (ldate.GetDay() > rdate.GetDay()){
		return false;
	}
	return false;
//	bool answer = false;
//	if (ldate.GetYear() < rdate.GetYear() || 
//		ldate.GetMonth() < rdate.GetMonth() || 
//		ldate.GetDay() < rdate.GetDay()) {
//		answer = true;
//	}
//	return answer;
}

void Database::AddEvent(const Date& date, const string& event) {
	date_and_event[date].insert(event);
	return;
}

bool Database::DeleteEvent(const Date& date, const string& event) {
	try {
		if (count (date_and_event.at(date).begin(), date_and_event.at(date).end(), event) > 0) {
			date_and_event.at(date).erase(event);	
		}
		else {
			return false;
		}
		if (date_and_event.at(date).empty()) {
			date_and_event.erase(date);
		}
		return true;
	} catch(const exception&) {
		return false;
	}
}

int Database::DeleteDate(const Date& date) {
	int answer = 0;
	try {
			answer = date_and_event.at(date).size();
			date_and_event.erase(date);
			return answer;
	} catch(const exception&) {
		return answer;
	}
}

void Database::Find(const Date& date) const {
	try {
		for (const auto& e : date_and_event.at(date)) {
			cout << e << endl;
		}
		return;
	} catch(const exception&) {
		return;
	}

}

void Database::Print() const {
	for (const auto& d_e : date_and_event) {
		cout << setfill('0');
		for (const auto& e : d_e.second) {
			cout << setw(4) << d_e.first.GetYear() << "-" << setw(2) << d_e.first.GetMonth() << "-" <<
				    setw(2) << d_e.first.GetDay() << " " << e << endl;
		}
	}
	return;
}

