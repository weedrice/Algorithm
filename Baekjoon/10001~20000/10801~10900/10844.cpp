#include <cstdio>

int main() {
	int n;
	int div = 1000000000;
	scanf("%d", &n);

	int** dp = new int*[n+1];
	for (int i = 0; i <= n; i++) {
		dp[i] = new int[10];
	}

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1] % div;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8] % div;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % div;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i < 10; i++) {
		sum = (sum + dp[n][i]) % div;
	}

	printf("%d\n", sum);
}