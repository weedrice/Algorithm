#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

int main() {
	deque<char> dq;
	vector<char> v;
	string s;

	while (1) {
		char in = getchar();
		if (in == ' ')
			continue;

		if (in == '\n')
			break;

		if (dq.size() < 3) {
			dq.push_back(in);
		}
		else {
			bool check = false;
			deque<char>::iterator iter;
			for (iter = dq.begin(); iter != dq.end(); ++iter) {
				if (in == *iter) {
					check = true;
					break;
				}
			}
			if (check) {
				dq.erase(iter);
				dq.push_back(in);
			}
			else {
				v.push_back(dq.front());
				dq.pop_front();
				dq.push_back(in);
			}
		}
	}

	if (v.size() == 0) {
		cout << "0" << endl;
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << endl;
		}
	}

	return 0;
}