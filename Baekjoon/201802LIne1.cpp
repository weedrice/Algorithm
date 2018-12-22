#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int calMoney(int distance) {
	if (distance > 178 || distance < 4) {
		return -1;
	}
	if (distance < 40) {
		return 720;
	}
	else {
		int additionalDistance = distance - 40;
		if (additionalDistance % 8 == 0) {
			return 720 + ((additionalDistance + 1) / 8 * 80);
		}
		else {
			return 720 + ((additionalDistance / 8 + 1) * 80);
		}
	}
}

int main() {
	string line;
	getline(cin, line);

	int card = 20000;

	stringstream ss(line);
	for (int distance; !(ss >> distance).fail(); ) {
		// @todo Write your code here.
		int usedMoney = calMoney(distance);
		if (usedMoney == -1) {
			break;
		}
		else if (usedMoney > card) {
			break;
		}
		else {
			card -= usedMoney;
		}
	}
	// @todo Write your code here.
	cout << card << endl;
	return 0;
}
