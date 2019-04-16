#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 1;
	cout << a << " ";
	for (int i = 1; i <= n; i++) {
		a = a * 2;
		cout << a << " ";
	}
}