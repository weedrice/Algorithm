#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int comNum = a;
		for (int i = 1; i < b; i++) {
			comNum = (comNum * a) % 10;
		}

		printf("%d\n", comNum == 0?10:comNum);
	}
}