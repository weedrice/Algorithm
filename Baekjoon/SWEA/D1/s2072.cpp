#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			int num;
			cin >> num;
			if (num % 2 != 0) {
				sum += num;
			}
		}

		cout << "#" << i << " " << sum << "\n";
	}
}