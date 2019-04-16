#include <iostream>

using namespace std;

bool rpc(int a, int b) {
	if (a == 1) {
		return b == 2 ? false : true;
	}
	else if (a == 2) {
		return b == 3 ? false : true;
	}
	else {
		return b == 1 ? false : true;
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	
	if (rpc(a, b)) {
		cout << "A";
	}
	else {
		cout << "B";
	}
}