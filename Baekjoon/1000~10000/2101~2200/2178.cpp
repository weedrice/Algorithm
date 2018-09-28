#include <cstdio>
#include <queue>

using namespace std;

int xpos[4] = { 0, 1, 0, -1 };
int ypos[4] = { -1, 0, 1, 0 };

int n, m;
int** maze;
int** mazeValue;
queue<pair<int, int>> q;

void go(pair<int, int> a) {
	int x = a.first;
	int y = a.second;
	
	for (int i = 0; i < 4; i++) {
		int newX = x + xpos[i];
		int newY = y + ypos[i];

		if (newX > 0 && newY > 0 && newX <= n && newY <= m) {
			if (maze[newX][newY] == 1) {
				q.push({ newX, newY });
				mazeValue[newX][newY] = mazeValue[x][y] + 1;
				maze[newX][newY] = -1;
			}
		}
	}
	
}

void bfs() {
	q.push({ 1, 1 });

	maze[1][1] = -1;
	mazeValue[1][1] = 1;

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();

		if (temp.first == n && temp.second == m)
			break;

		go(temp);
	}

}

int main() {
	scanf("%d %d", &n, &m);
	maze = new int*[n+1]();
	mazeValue = new int*[n + 1]();
	for (int i = 1; i <= n; i++) {
		maze[i] = new int[m + 1]();
		mazeValue[i] = new int[m + 1]();
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
			mazeValue[i][j] = 0;
		}
	}

	bfs();
	printf("%d\n", mazeValue[n][m]);
}