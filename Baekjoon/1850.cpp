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
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a * b / gcd(a, b));
}