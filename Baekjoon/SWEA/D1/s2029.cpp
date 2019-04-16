#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		int a, b;
		cin >> a >> b;
		cout << "#" << test_case << " " << a / b << " " << a % b << "\n";
	}

}