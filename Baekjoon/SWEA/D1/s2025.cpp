#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << (1 + n) * (n / 2);
	}
	else {
		cout << ((1 + (n-1)) * ((n-1) / 2)) + n;
	}
}