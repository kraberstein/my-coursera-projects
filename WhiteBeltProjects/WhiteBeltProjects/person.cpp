#include "person.h"

string BuildJoinedName(vector<string> names) {
	// ��� ������� � ��� ����������
	if (names.empty()) {
		return "";
	}
	// ������ ������ ��������������� ������� �� ��������
	reverse(begin(names), end(names));

	// �������� ������� ������ ��� � ������ ����������
	string joined_name = names[0];

	// ���������� ��� ����������� �����
	for (int i = 1; i < names.size(); ++i) {
		if (i == 1) {
			// ���� ��� ������ ������������� ���, �������� ��� �� ���������� �������
			joined_name += " (";
		}
		else {
			// ���� ��� �� ������ ���, �������� �� ����������� �������
			joined_name += ", ";
		}
		// � ��������� ��������� ���
		joined_name += names[i];
	}

	// ���� � ������� ���� ������ ������ �����, �� ��������� ������ � ������� �
	if (names.size() > 1) {
		joined_name += ")";
	}
	// ��� �� ���� �������� ������
	return joined_name;
}

vector<string> FindNamesHistory(const map<int, string>& names_by_year,
	int year) {
	vector<string> names;
	// ���������� ��� ������� � ��������������� �������
	for (const auto& item : names_by_year) {
		// ���� ��������� ��� �� ��������� � �������� � ���������� �� �����������,
		if (item.first <= year && (names.empty() || names.back() != item.second)) {
			// ��������� ��� � �������
			names.push_back(item.second);
		}
	}
	return names;
}

string BuildFullName(const string& first_name, const string& last_name) {
	if (first_name.empty() && last_name.empty()) {
		return "Incognito";
	}
	else if (first_name.empty()) {
		return last_name + " with unknown first name";
	}
	else if (last_name.empty()) {
		return first_name + " with unknown last name";
	}
	else {
		return first_name + " " + last_name;
	}
}


Person::Person(const string& fname, const string& lname, int byear) {
	birth_year = byear;
	ChangeFirstName(byear, fname);
	ChangeLastName(byear, lname);
}

void Person::ChangeFirstName(int year, const string& first_name) {
	if (year < birth_year)
		return;
	first_names[year] = first_name;
}
	
void Person::ChangeLastName(int year, const string& last_name) {
		if (year < birth_year)
			return;
		last_names[year] = last_name;
	}

string Person::GetFullName(int year) const {
		if (year < birth_year) {
			return "No person";
		}
		// ����� ������� ��������� ����� � �������
		// � ������ ������ ��� �������, ��� ��� ��� ���������� ������ ��������� ��� � �������, �� ������ �� �� ������������ ������� �������?
		const vector<string> first_names_history = FindFirstNamesHistory(year);
		const vector<string> last_names_history = FindLastNamesHistory(year);

		// ���������� ������ ��� ������� BuildFullName: ������ ��������� ��� � ������� ��� ������� �� �������, ���� ��� ����������
		string first_name;
		string last_name;
		if (!first_names_history.empty()) {
			first_name = first_names_history.back();
		}
		if (!last_names_history.empty()) {
			last_name = last_names_history.back();
		}
		return BuildFullName(first_name, last_name);
	}

string Person::GetFullNameWithHistory(int year) const {
		if (year < birth_year) {
			return "No person";
		}
		// ������� ������ ��� �� ���� ��������
		const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
		// ������� ������ ������� �� ���� ��������
		const string last_name = BuildJoinedName(FindLastNamesHistory(year));
		// ��������� �� � ������� ������� �������
		return BuildFullName(first_name, last_name);
	}

vector<string> Person::FindFirstNamesHistory(int year) const {
	return FindNamesHistory(first_names, year);
}
	
vector<string> Person::FindLastNamesHistory(int year) const {
	return FindNamesHistory(last_names, year);
}

