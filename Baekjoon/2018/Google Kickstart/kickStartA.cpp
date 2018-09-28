#include <iostream>

/*

bool isEven(int n) {
	return (n % 2 == 0) ? true : false;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int t;
	scanf("%d", &t);

	for(int testCase = 1; testCase <= t; testCase++) {
		// n == number of candies, o == number of eatable odd candeis, d == max sweetness
		int n, o;
		long long d;
		scanf("%d %d %lld", &n, &o, &d);
		// X[i] = (A * x[i-1] + B * X[i-2] + c) modulo M, i = 3 to N
		// S[i] = X[i] + L for i to N
		int* x = new int[n];
		int* s = new int[n];
		int* dp = new int[n]();
		int* oddNumA = new int[n]();

		int a, b, c, m, l;
		scanf("%d %d %d %d %d %d %d", &x[0], &x[1], &a, &b, &c, &m, &l);

		//init x
		for (int i = 2; i < n; i++) {
			x[i] = ((a*x[i - 1]) + (b*x[i - 2]) + c) % m;
		}
		//init s
		for (int i = 0; i < n; i++) {
			s[i] = x[i] + l;
		}

		if (isEven(s[0])) {
			dp[0] = s[0];
			oddNumA[0] = 0;
		}
		else {
			if (o > 0) {
				dp[0] = s[0];
				oddNumA[0] = 1;
			}
		}

		int maxSweet = s[0];
		for (int i = 1; i < n; i++) {
			if (isEven(s[i])) {
				dp[i] = max(dp[i - 1] + s[i], s[i]);
				if (dp[i] == s[i]) {
					oddNumA[i] = 0;
				}
				else {
					oddNumA[i] = oddNumA[i - 1];
				}

				if (dp[i] < d) {
					maxSweet = max(maxSweet, dp[i]);
				}
				else {
					dp[i] = max(s[i - 1] + s[i], s[i]);
					maxSweet = max(maxSweet, dp[i]);
				}
			}
			else {
				if (oddNumA[i - 1] < o) {
					dp[i] = max(dp[i - 1] + s[i], s[i]);
					if (dp[i] == s[i]) {
						oddNumA[i] = 1;
					}
					else {
						oddNumA[i] = oddNumA[i-1] + 1;
					}

					if (dp[i] < d) {
						maxSweet = max(maxSweet, dp[i]);
					}
					else {
						dp[i] = max(s[i - 1] + s[i], s[i]);
						maxSweet = max(maxSweet, dp[i]);
					}
				}
				else {
					dp[i] = max(dp[i - 1], s[i]);
					if (dp[i] == s[i]) {
						oddNumA[i] = 1;
					}
					else {
						oddNumA[i] = oddNumA[i - 1];
					}

					if (dp[i] < d) {
						maxSweet = max(maxSweet, dp[i]);
					}
					else {
						dp[i] = max(s[i - 1] + s[i], s[i]);
						maxSweet = max(maxSweet, dp[i]);
					}
				}
			}
		}


		printf("Case #%d: %d\n", testCase, maxSweet);
	}
}

*/

bool isEven(int n) {
	return (n % 2 == 0) ? true : false;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int t;
	scanf("%d", &t);

	for (int testCase = 1; testCase <= t; testCase++) {
		// n == number of candies, o == number of eatable odd candeis, d == max sweetness
		int n, o;
		long long d;
		std::cin >> n >> o >> d;
		// X[i] = (A * x[i-1] + B * X[i-2] + c) modulo M, i = 3 to N
		// S[i] = X[i] + L for i to N
		int* x = new int[n];
		int* s = new int[n];
		int dp[500000][500000];
		int** oddNum = new int*[n];

		int a, b, c, m, l;
		std::cin >> x[0] >> x[1] >> a >> b >> c >> m >> l;

		int maxSweet = d;
		//init x
		for (int i = 2; i < n; i++) {
			x[i] = ((a*x[i - 1]) + (b*x[i - 2]) + c) % m;
		}
		//init s and dp
		int oddNumSize = 0;
		for (int i = 0; i < n; i++) {
			oddNum[i] = new int[n]();

			s[i] = x[i] + l;
			if (s[i] < d) {
				maxSweet = s[i];
			}
			if (!isEven(s[i]))
				oddNumSize++;
		}

		if (!isEven(s[0]))
			oddNum[0][0]++;

		if (maxSweet == d) {
			std::cout << "Case #" << testCase << ": IMPOSSIBLE" << std::endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					if (i == j) {
						if (s[j] > d)
							dp[i][j] = d;
						else
							dp[i][j] = s[j];

						if (isEven(s[j]))
							oddNum[i][j] = 0;
						else
							oddNum[i][j] = 1;

						maxSweet = max(maxSweet, dp[i][j]);
					}
					else {
						if (isEven(s[j])) {
							if (dp[i][j - 1] + s[j] > d) {
								for (int k = i + 1; k < j - 1; k++) {
									int maxdp = dp[k][j - 1] + s[j];
									if (maxdp < d && maxdp > dp[i][j - 1])
										dp[i][j] = maxdp + s[j];
								}

								dp[i][j] = max(dp[i][j], s[j]);
								if (dp[i][j] == s[j])
									oddNum[i][j] = 0;
								else
									oddNum[i][j] = oddNum[i][j - 1];

								maxSweet = max(maxSweet, dp[i][j]);
							}
							else {
								dp[i][j] = max(dp[i][j - 1] + s[j], s[j]);
								if (dp[i][j] == s[j])
									oddNum[i][j] = 0;
								else
									oddNum[i][j] = oddNum[i][j - 1];

								maxSweet = max(maxSweet, dp[i][j]);
							}
						}
						//when odd number
						else {
							if (oddNum[i][j - 1] >= o) {
								if (s[i] > s[j]) {
									dp[i][j] = s[j];
									oddNum[i][j] = 1;
								}
								else {
									dp[i][j] = dp[i + 1][j - 1] + s[j];
									oddNum[i][j] = oddNum[i][j - 1];
								}
								maxSweet = max(maxSweet, dp[i][j]);
							}
							else {
								if (dp[i][j - 1] + s[j] > d) {
									for (int k = i + 1; k < j - 1; k++) {
										int maxdp = dp[k][j - 1] + s[j];
										if (maxdp < d && maxdp > dp[i][j - 1])
											dp[i][j] = maxdp + s[j];
									}

									dp[i][j] = max(dp[i][j], s[j]);
									if (dp[i][j] == s[j])
										oddNum[i][j] = 1;
									else
										oddNum[i][j] = oddNum[i][j - 1] +1;

									maxSweet = max(maxSweet, dp[i][j]);
								}
								else {
									dp[i][j] = max(dp[i][j - 1] + s[j], s[j]);
									if (dp[i][j] == s[j])
										oddNum[i][j] = 1;
									else
										oddNum[i][j] = oddNum[i][j - 1] + 1;

									maxSweet = max(maxSweet, dp[i][j]);
								}
							}
						}
					}
				}
			}

			std::cout << "Case #" << testCase <<": "<< maxSweet << std::endl;
		}
	}
}