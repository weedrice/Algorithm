#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			int num;
			cin >> num;
			sum += num;
		}

		double average = sum / 10.0;
		int ave = round(average);

		cout << "#" << i << " " << ave << "\n";
	}
}