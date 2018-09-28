#include <cstdio>

int* dp;

int getWays(int num) {
	if (num == 1)
		return dp[1];
	else if (num == 2) {
		return dp[2];
	}
	else if (num == 3) {
		return dp[3];
	}
	else {
		return getWays(num - 1) + getWays(num - 2) + getWays(num - 3);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	dp = new int[12]();
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (n--) {
		int num;
		scanf("%d", &num);

		printf("%d\n", getWays(num));
	}
}