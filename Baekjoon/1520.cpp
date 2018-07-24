#include <cstdio>

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int** maps = new int*[m];
	unsigned int** ways = new unsigned int*[m];
	for (int i = 0; i < m; i++) {
		maps[i] = new int[n];
		ways[i] = new unsigned int[n]();
		for (int j = 0; j < n; j++) {
			scanf("%d", &maps[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) {
				ways[i][j] = 1;
			}
			else if (i == 0) {
				if (ways[i][j - 1] > ways[i][j])
					ways[i][j] = ways[i][j] + ways[i][j - 1];
			}
			else if (j == 0) {
				if (ways[i-1][j] > ways[i][j])
					ways[i][j] = ways[i][j] + ways[i-1][j];
			}
			else {
				if (ways[i - 1][j] > ways[i][j])
					ways[i][j] = ways[i][j] + ways[i - 1][j];
				if (ways[i][j - 1] > ways[i][j])
					ways[i][j] = ways[i][j] + ways[i][j - 1];
			}
		}
	}

	printf("%d", ways[m-1][n-1]);
}