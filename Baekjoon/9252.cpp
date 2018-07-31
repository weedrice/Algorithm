#include <cstdio>
#include <cstring>
#include <stack>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	char str1[1001];
	char str2[1001];
	scanf("%s", &str1);
	scanf("%s", &str2);
	int size1 = strlen(str1);
	int size2 = strlen(str2);

	int** dp = new int*[size1 + 1];
	for (int i = 0; i <= size1; i++) {
		dp[i] = new int[size2 + 1]();
	}

	int lcs = 0;
	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printf("%d\n", dp[size1][size2]);

	int i = size1;
	int j = size2;
	std::stack<char> lcsStr;
	while (i > 0 && j > 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			lcsStr.push(str1[i - 1]);
			i--;
			j--;
		}
	}
	while (!lcsStr.empty()) {
		printf("%c", lcsStr.top());
		lcsStr.pop();
	}
}