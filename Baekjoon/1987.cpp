#include <iostream>

using namespace std;

int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, -1, 0, 1 };
int** matrix;
bool* isVisited;
int r, c;
int cnt = 1;
int newCnt = 1;

void dfs(int x, int y) {
	isVisited[matrix[x][y]] = true;

	for (int i = 0; i < 4; i++) {
		int newX = x + xpos[i];
		int newY = y + ypos[i];
		if (newX >= 0 && newY >= 0 && newX < r && newY < c) {
			int next = matrix[newX][newY];
			if (isVisited[next] == false) {
				cnt = cnt > ++newCnt ? cnt : newCnt;
				dfs(newX, newY);
			}
		}
	}
	newCnt--;
	isVisited[matrix[x][y]] = false;
}

int main() {
	isVisited = new bool[26]();

	cin >> r >> c;
	getchar();

	matrix = new int*[r];
	for (int i = 0; i < r; i++) {
		matrix[i] = new int[c];
		for (int j = 0; j < c; j++) {
			char alphabet = getchar();
			matrix[i][j] = alphabet - 'A';
		}
		getchar();
	}

	dfs(0, 0);
	cout << cnt;
}