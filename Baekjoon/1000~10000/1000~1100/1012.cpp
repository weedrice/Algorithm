#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int** matrix;
bool** isVisited;
int m, n, k;

int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, -1, 0, 1 };

int bfs(int i, int j) {
	if (matrix[i][j] == 0) {
		isVisited[i][j] = true;
		return 0;
	}
	queue<pair<int, int>> q;
	q.push(pair<int, int>(i, j));
	isVisited[i][j] = true;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newX = xpos[i] + nowX;
			int newY = ypos[i] + nowY;
			if (newX >= 0 && newY >= 0 && newX < m && newY < n) {
				if (!isVisited[newX][newY]) {
					if (matrix[newX][newY] == 1)
						q.push(pair<int, int>(newX, newY));
					isVisited[newX][newY] = true;
				}
			}
		}
	}

	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &m, &n, &k);

		matrix = new int*[m];
		isVisited = new bool*[m];
		for (int i = 0; i < m; i++) {
			matrix[i] = new int[n];
			isVisited[i] = new bool[n];
			for (int j = 0; j < n; j++) {
				matrix[i][j] = 0;
				isVisited[i][j] = false;
			}
		}

		for (int i = 0; i < k; i++) {
			int newM, newN;
			scanf("%d %d", &newM, &newN);
			matrix[newM][newN] = 1;
		}

		int wormSum = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if(!isVisited[i][j])
					wormSum += bfs(i, j);
			}
		}

		printf("%d\n", wormSum);
	}
}