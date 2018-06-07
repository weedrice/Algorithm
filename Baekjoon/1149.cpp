#include <cstdio>

int min(int a, int b) {
	return a < b ? a : b;
}

int min(int a, int b, int c) {
	if (a > b) {
		if (b > c) {
			return c;
		}
		else {
			return b;
		}
	}
	else {
		if (a > c) {
			return c;
		}
		else {
			return a;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int** houses = new int*[3];
	for (int i = 0; i < 3; i++) {
		houses[i] = new int[n];
	}

	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	houses[0][0] = r;
	houses[1][0] = g;
	houses[2][0] = b;

	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &r, &g, &b);

		houses[0][i] = r + min(houses[1][i - 1], houses[2][i - 1]);
		houses[1][i] = g + min(houses[0][i - 1], houses[2][i - 1]);
		houses[2][i] = b + min(houses[0][i - 1], houses[1][i - 1]);
	}

	printf("%d\n", min(houses[0][n - 1], houses[1][n - 1], houses[2][n - 1]));
}