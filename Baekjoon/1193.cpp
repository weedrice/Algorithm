#include <cstdio>

int main() {
	int n = 1;
	scanf("%d", &n);

	int num = 0, den = 0;
	for (int i = 0, j = 0; ; i += j) {
		if (n > i) {
			j++;
			continue;
		}
		else {
			if (j % 2 == 0) {
				num = j;
				den = 1;
				while (i != n) {
					num--;
					den++;
					i--;
				}
			}
			else {
				num = 1;
				den = j;
				while (i != n) {
					num++;
					den--;
					i--;
				}
			}
			break;
		}
	}
	printf("%d/%d\n", num, den);
}