#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%1d", &a);
		getchar();
		scanf("%1d", &b);
		printf("%d\n", a + b);
	}
}