#include <iostream>

int zero[41], one[41];


int main() {
	int t;
	scanf("%d", &t);

	zero[0] = 1; zero[1] = 0;
	one[0] = 0; one[1] = 1;
	for (int i = 2; i < 41; i++) {
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	for (int i = 0; i < t; i++) {
		int number;
		scanf("%d", &number);
		printf("%d %d\n", zero[number], one[number]);
	}
}