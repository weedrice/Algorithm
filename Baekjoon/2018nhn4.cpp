#include <iostream>

using namespace std;

char** matrix;
bool** isGotten;

bool newTurn(int i, int j) {
	if (matrix[i][j] == 0) {

	}
	else {

	}
}

int main() {
	int n;
	cin >> n;

	isGotten = new bool*[n];
	matrix = new char*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new char[n];
		isGotten[i] = new bool[n]();
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z')
				isGotten[i][j] = true;
		}
	}

	while (1) {
		int leftGround = n*n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isGotten[i][j])
					newTurn();
				else
					leftGround--;
			}
		}
		if (leftGround == 0)
			break;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}