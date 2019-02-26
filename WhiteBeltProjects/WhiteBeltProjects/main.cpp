#include "coursera.h"
#include "database.h"

//	throw exception(); кидаем исключение
//	throw runtime_error(string s или поток);
//	throw invalid_argument(); - бросать, если что-то не так с вх. данными
//	throw domain_error(); - бросать, если нарушается, напр., математические условия (деление на ноль, корень из отриц. числа)
//	throw system_error();

// опасный код заносим в try {...} 
//						 catch (exception& ex) {
//						 	ex.what(); -- если передали через runtime_error}

Date ParseDate(const string& str_date) {
	stringstream ss(str_date);
	int year, month, day;
	ss >> year;
	if (ss.peek() != '-') {
		throw invalid_argument("Wrong date format: " + str_date);
	}
	ss.ignore(1);
	ss >> month;
	if (ss.peek() != '-') {
		throw invalid_argument("Wrong date format: " + str_date);
	}
	ss.ignore(1);
	ss >> day;
	char c;
	if (ss >> c) {
		throw invalid_argument("Wrong date format: " + str_date);
	}
	if (month < 1 || month > 12) {
		throw invalid_argument("Month value is invalid: " + to_string(month));
	}
	if (day < 1 || day > 31) {
		throw invalid_argument("Day value is invalid: " + to_string(day));
	}
	return Date(year, month, day);
}

int main() {
	Database db;
	Date date;
	string str_command;
	try {
		while (getline(cin, str_command)) {
			stringstream ss(str_command);
			string command;
			ss >> command;
			if (command != "Add" && command != "Del" &&
				command != "Find" && command != "Print" && command != "\0") {
					throw invalid_argument("Unknown command: " + command);
				}
			string str_date, event;
				if (command == "Add") {
	    			ss >> str_date >> event;
	    			if (str_date.empty()) continue;
	    			date = ParseDate(str_date);
	    			if (event.empty()) continue;
	    			db.AddEvent(date, event);
				}
			if (command == "Del") {
				ss >> str_date >> event;
				if (str_date.empty()) continue;
				if (!ss.fail()) {
	    				date = ParseDate(str_date);
							if (db.DeleteEvent(date, event)) {
								cout << "Deleted successfully" << endl;
							}
							else {
								cout << "Event not found" << endl;
							}
				}
				else {
	    				date = ParseDate(str_date);
	    					cout << "Deleted " << db.DeleteDate(date) << " events" << endl;	
				}
			}
			if (command == "Find") {
				ss >> str_date;
				if (str_date.empty()) continue;
	    		date = ParseDate(str_date);
	    		db.Find(date);
			}
			if (command == "Print") {
				db.Print();
			}

	  	}
	}
	catch (invalid_argument& ia) {
		cout << ia.what();
		return 0;
	}
	catch(const exception&) {
	}

	return 0;
}

