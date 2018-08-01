#include <cstdio>

long long gcd(long long a, long long b) {
	long long c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", a * b / gcd(a, b));
}