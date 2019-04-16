#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {

		int a, b;
		cin >> a >> b;

		char c;
		if (a == b) {
			c = '=';
		}
		else {
			c = a > b ? '>' : '<';
		}

		cout << "#" << i << " " << c << "\n";
	}
}