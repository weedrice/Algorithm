#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int* arr = new int[n+1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	//end input

	int* dp = new int[n+1]();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(arr[j] + dp[i - j], dp[i]);
		}
	}

	printf("%d\n", dp[n]);
}