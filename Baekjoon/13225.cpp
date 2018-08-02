#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);

		int cnt = 0;
		for (int i = 1; i*i <= num; i++) {
			if (num%i == 0) {
				cnt++;
				if (i*i < num)
					cnt++;
			}
		}

		printf("%d %d\n", num, cnt);
	}
}