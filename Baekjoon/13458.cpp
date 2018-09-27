#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	int* rooms = new int[n];
	for(int i=0;i<n;i++) {
		scanf("%d", &rooms[i]);
	}

	int b, c;
	scanf("%d %d", &b, &c);

	long long directorSum = n;
	for (int i = 0; i < n; i++) {
		rooms[i] -= b;
		if (rooms[i] > 0) {
			if (rooms[i] % c == 0)
				directorSum += rooms[i] / c;
			else
				directorSum += rooms[i] / c + 1;
		}
	}

	printf("%lld\n", directorSum);
}