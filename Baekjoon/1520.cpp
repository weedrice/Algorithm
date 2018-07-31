#include <cstdio>

int n, m;
int** maps;
unsigned int** ways;
int xWays[4] = { -1, 0, 1, 0 };
int yWays[4] = { 0, -1, 0, 1 };

int findWay(int y, int x) {
	//시작점일경우 방법은 1개
	if (x == 0 && y == 0) {
		return 1;
	}

	//처음 방문한 곳일경우 진입
	if (ways[y][x] == -1) {
		ways[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			//상하좌우 비교를 위한 좌표 선언
			int nextX = xWays[i] + x;
			int nextY = yWays[i] + y;

			//다음 XY가 오르막일때(역순으로 가므로)
			if (nextX >= 0 && nextY >= 0 && nextY < m && nextX < n) {
				if (maps[y][x] < maps[nextY][nextX]) {
					ways[y][x] += findWay(nextY, nextX);
				}
			}
		}
	}

	return ways[y][x];
}

int main() {
	scanf("%d %d", &m, &n);
	maps = new int*[m];
	ways = new unsigned int*[m];
	for (int i = 0; i < m; i++) {
		maps[i] = new int[n];
		ways[i] = new unsigned int[n]();
		for (int j = 0; j < n; j++) {
			scanf("%d", &maps[i][j]);
			ways[i][j] = -1;
		}
	}
	printf("%d", findWay(m-1, n-1)); 
}