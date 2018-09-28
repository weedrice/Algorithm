#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j < n; j++) {
			printf(" ");
		}
		for (int j = 2 * i - 1; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n-1; i > 0; i--) {
		for (int j = i; j < n; j++) {
			printf(" ");
		}
		for (int j = 2 * i - 1; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
}