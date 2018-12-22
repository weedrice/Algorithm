#include <iostream>
#include <string>
#include <deque>

using namespace std;

string** matrix;
deque<string> rails;

int n, w;

void moves(int move, bool destination) {
	if (destination) {
		for (int i = 0; i < move; i++) {
			rails.push_back(rails.front());
			rails.pop_front();
		}
	}
	else {
		for (int i = 0; i < move; i++) {
			rails.push_front(rails.back());
			rails.pop_back();
		}
	}
}

void nMove(int stage, int destination, int j) {
	rails.clear();
	int nowX = j;
	int nowY = j;
	while (1) {
		if (nowX == stage) {
			nowX--;
			break;
		}
		rails.push_back(matrix[nowX][nowY]);
		nowX++;
	}
	nowY++;
	while (1) {
		if (nowY == stage - 1) {
			break;
		}
		rails.push_back(matrix[nowX][nowY]);
		nowY++;
	}
	while (1) {
		if (nowX == j - 1) {
			nowX++;
			break;
		}
		rails.push_back(matrix[nowX][nowY]);
		nowX--;
	}
	while (1) {
		if (nowY == j + 1)
			break;
		rails.push_back(matrix[nowX][nowY]);
		nowY--;
	}

	int move = w % stage;
	moves(move, destination);

	int nowX = j;
	int nowY = j;
	while (1) {
		if (nowX == stage) {
			nowX--;
			break;
		}
		matrix[nowX][nowY] = rails.front();
		rails.pop_front();
		nowX++;
	}
	nowY++;
	while (1) {
		if (nowY == stage - 1) {
			break;
		}
		matrix[nowX][nowY] = rails.front();
		rails.pop_front();
		nowY++;
	}
	while (1) {
		if (nowX == j - 1) {
			nowX++;
			break;
		}
		matrix[nowX][nowY] = rails.front();
		rails.pop_front();
		nowX--;
	}
	while (1) {
		if (nowY == j + 1)
			break;
		matrix[nowX][nowY] = rails.front();
		rails.pop_front();
		nowY--;
	}

}

int main() {
	bool destination;
	cin >> n >> w;
	if (w < 0)
		destination = false;
	else
		destination = true;
	w = abs(w);

	matrix = new string*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new string[n];
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	if (n % 2 == 0) {
		for (int i = 0; i < (n / 2); i++) {
			nMove(n - (i * 2), destination, i);
			destination = !destination;
		}
	}
	else {
		for (int i = 0; i < (n / 2); i++) {

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}