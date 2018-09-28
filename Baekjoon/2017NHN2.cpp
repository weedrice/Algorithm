#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int** matrix;
bool** isVisited;


int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, -1, 0, 1 };

int dfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> q;

	q.push(pair<int, int>(x, y));
	isVisited[x][y] = true;

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
					cnt++;
				}
				isVisited[nextX][nextY] = true;
			}
		}
	}
	
	return cnt;
}

int main() {
	cin >> n;

	matrix = new int*[n];
	isVisited = new bool*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n]();
		isVisited[i] = new bool[n]();
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isVisited[i][j] && matrix[i][j] == 1) {
				v.push_back(dfs(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	if (v.size() == 0) {
		cout << "0" << endl;
	}
	else {
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
	}	

	return 0;
}