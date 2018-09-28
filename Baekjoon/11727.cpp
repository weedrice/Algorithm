#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long *dp = new long long[n+1];

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = ((dp[i - 1] % 10007) + (dp[i - 2] * 2) % 10007) % 10007;
	}
	cout << dp[n] << endl;
}