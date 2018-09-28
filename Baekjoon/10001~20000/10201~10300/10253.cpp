#include <cstdio>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int henry;
		while (a != 1) {
			henry = b / a + 1;
			a = a * henry - b;
			b = b * henry;
			int gcdAB = gcd(a, b);
			a /= gcdAB;
			b /= gcdAB;
		}
		printf("%d\n", b);
	}
}