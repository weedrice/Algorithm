#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	long long * dp = new long long[n]();
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld\n", dp[n - 1]);
}