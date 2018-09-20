#include <cstdio>

int main() {
	bool cups[3] = { true, false, false };
	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);

		bool swap;
		swap = cups[a-1];
		cups[a - 1] = cups[b - 1];
		cups[b - 1] = swap;
	}

	for (int i = 0; i < 3; i++) {
		if (cups[i]) {
			printf("%d\n", i + 1);
			break;
		}
	}
}