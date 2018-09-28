#include <cstdio>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);

	double z = (double)x / (double)y;

	printf("%0.9lf", z);
}