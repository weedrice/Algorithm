#include <cstdio>

long long multi(int n, int r) {
	long long result = 1;
	for (int i = 0; i < r; i++) {
		result *= (n - i);
		result /= (1 + i);
	}
	return result;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		long long result = multi(m, n);
		printf("%lld\n", result);
	}
}