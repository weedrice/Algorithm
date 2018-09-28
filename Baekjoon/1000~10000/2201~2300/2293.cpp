#include <cstdio>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int* coins = new int[n+1];
	int* coinSum = new int[k+1]();
	for (int i = 0; i < n; i++) {
		scanf("%d", &coins[i]);
	}

	coinSum[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			coinSum[j] += coinSum[j - coins[i]];
		}
	}

	printf("%d\n", coinSum[k]);
}