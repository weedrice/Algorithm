#include <iostream>
#include <string>

using namespace std;

bool checkDay(string month, string day) {
	int n_month = atoi(month.c_str());
	int n_day = atoi(day.c_str());
	if (n_month > 0 && n_month < 13) {
		switch (n_month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (n_day > 0 && n_day <= 31) {
				return true;
			}
			else {
				return false;
			}
		case 2:
			if (n_day > 0 && n_day < 29) {
				return true;
			}
			else {
				return false;
			}
		default:
			if (n_day > 0 && n_day < 31) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}
}

int main() {
	int t;
	cin >> t;

	for (int testcase = 1; testcase <= t; testcase++) {
		string str;
		cin >> str;
		string year = str.substr(0, 4);
		string month = str.substr(4, 2);
		string day = str.substr(6, 2);
		if (checkDay(month, day)) {
			cout << "#" << testcase << " " << year << "/" << month << "/" << day << "\n";
		}
		else {
			cout << "#" << testcase<< " "<< "-1" << "\n";
		}
	}
}