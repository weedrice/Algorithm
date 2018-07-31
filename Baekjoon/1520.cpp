#include <cstdio>

int n, m;
int** maps;
unsigned int** ways;
int xWays[4] = { -1, 0, 1, 0 };
int yWays[4] = { 0, -1, 0, 1 };

int findWay(int y, int x) {
	//�������ϰ�� ����� 1��
	if (x == 0 && y == 0) {
		return 1;
	}

	//ó�� �湮�� ���ϰ�� ����
	if (ways[y][x] == -1) {
		ways[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			//�����¿� �񱳸� ���� ��ǥ ����
			int nextX = xWays[i] + x;
			int nextY = yWays[i] + y;

			//���� XY�� �������϶�(�������� ���Ƿ�)
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