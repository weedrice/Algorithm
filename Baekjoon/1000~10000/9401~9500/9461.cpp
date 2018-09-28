#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		int fixed[6] = { 1, 1, 1, 2, 2, 3 };
		long long* dp = new long long[n + 1];
		for (int i = 1; i <= n; i++) {
			if (i < 6) {
				dp[i] = fixed[i - 1];
			}
			else {
				dp[i] = dp[i - 1] + dp[i - 5];
			}
		}

		printf("%lld\n", dp[n]);
	}
}