#include <cstdio>

int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	int* ringArr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &ringArr[i]);
	}

	for (int i = 1; i < n; i++) {
		int gcdNum = gcd(ringArr[0], ringArr[i]);
		printf("%d/%d\n", ringArr[0] / gcdNum, ringArr[i] / gcdNum);
	}
}