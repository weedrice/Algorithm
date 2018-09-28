#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int** matrix;
bool** isVisited;

int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, 1, 0, -1 };

int bfs(int i, int j) {
	int numOfApartment = 1;
	queue<pair<int, int>> q;
	q.push(pair<int, int>(i, j));
	isVisited[i][j] = true;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + xpos[i];
			int nextY = nowY + ypos[i];
			if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < n) {
				if (isVisited[nextX][nextY] == false && matrix[nextX][nextY] == 1) {
					q.push(pair<int, int>(nextX, nextY));
					isVisited[nextX][nextY] = true;
					numOfApartment++;
				}
				else
					isVisited[nextX][nextY] = true;
			}
		}
	}
	return numOfApartment;
}

int main() {
	scanf("%d", &n);
	matrix = new int*[n];
	isVisited = new bool*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		isVisited[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			scanf("%1d", &matrix[i][j]);
			isVisited[i][j] = false;
		}
	}

	vector<int> apartments;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 1 && isVisited[i][j] == false)
				apartments.push_back(bfs(i, j));
		}
	}

	sort(apartments.begin(), apartments.end());
	printf("%d\n", apartments.size());
	for (vector<int>::iterator iter = apartments.begin(); iter != apartments.end(); iter++) {
		printf("%d\n", *iter);
	}
}