#include <stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);

	for (long long i = 0; i<n; i++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		long long dist = y - x;

		if (dist == 1) {
			printf("1\n");
			continue;
		}
		if (dist == 2) {
			printf("2\n");
			continue;
		}

		for (long long j = 1;; j++) {
			long long powj = j * j;
			long long max = powj + j;
			long long min = powj - j;

			if (dist <= max && dist > min) {
				if (dist > powj) {
					printf("%lld\n", 2 * j);
					break;
				}
				else {
					printf("%lld\n", 2 * j - 1);
					break;
				}
			}
		}
	}
}