#include <cstdio>
#include <algorithm>

int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int k;
		scanf("%d", &k);

		int* pagesSum = new int[k+1]();
		int** dp = new int*[k + 1]();

		for (int i = 1; i <= k; i++) {
			int value;
			scanf("%d", &value);
			pagesSum[i] = pagesSum[i - 1] + value;
			dp[i] = new int[k + 1]();
		}

		for (int i = 1; i < k; i++) {
			for (int j = 1; i + j <= k; j++) {
				dp[j][i + j] = 123456789;

				for (int k = j; k < i + j; k++)
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j]);

				dp[j][i + j] += pagesSum[i + j] - pagesSum[j - 1];
			}
		}

		printf("%d\n", dp[1][k]);
	}
}