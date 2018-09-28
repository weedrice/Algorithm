#include <cstdio>

int main() {
	int x;
	scanf("%d", &x);

	while (x--) {
		if (x == 64) {
			printf("1\n");
			return 0;
		}

		int shortestStick = 32;
		int restStickSum = 0;
		int sticks = 1;
		int totalSum = 64;

		while (1) {
			totalSum = restStickSum + shortestStick;
			if (totalSum == x)
				break;

			if (shortestStick + restStickSum >= x) {
				shortestStick /= 2;
			}
			else {
				restStickSum += shortestStick;
				shortestStick /= 2;
				sticks++;
			}
		}

		printf("x: %d\n", x);
		printf("number of stick: %d\n", sticks);
	}
}