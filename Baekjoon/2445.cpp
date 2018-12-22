#include <iostream>

int main() {
	int n;
	scanf("%d", &n);
	int tot = n * 2;

	for (int i = 0; i < tot; i++) {
		if (i < n) {
			for (int j = 0; j < i + 1; j++) {
				printf("*");
			}
			for (int j = 0; j < (tot)-((i + 1) * 2); j++) {
				printf(" ");
			}
			for (int j = 0; j < i + 1; j++) {
				printf("*");
			}
			printf("\n");
		}
		else {
			for (int j = 0; j < tot - i - 1; j++) {
				printf("*");
			}
			for (int j = 0; j < (i+1) % n; j++) {
				printf("  ");
			}
			for (int j = 0; j < tot - i - 1; j++) {
				printf("*");
			}
			printf("\n");
		}
		
	}

}