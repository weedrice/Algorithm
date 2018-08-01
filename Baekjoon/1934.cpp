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
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int gcdNum = gcd(a, b);
		printf("%d\n", a * b / gcdNum);
	}
}