#include <iostream>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	//end input;

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (k >= arr[i]) {
			k -= arr[i];
			cnt++;
		}
		if (k == 0)
			break;
	}

	printf("%d\n", cnt);
}