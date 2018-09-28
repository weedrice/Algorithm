#include <cstdio>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);

	int *wines = new int[10001]();
	wines[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &wines[i]);
	}

	int* drinkWines = new int[10001]();
	drinkWines[0] = wines[0];
	drinkWines[1] = wines[1];
	drinkWines[2] = wines[1] + wines[2];

	for (int i = 3; i <= n; i++) {
		//지금와인과 이전의 와인을 마신경우와 지금 와인은 마시고 이전의 와인은 마시지 않은경우를 비교(2번째 전의 와인은 마셨음)
		drinkWines[i] = max(wines[i] + wines[i - 1] + drinkWines[i-3], wines[i] + drinkWines[i - 2]);
		//위에서 더 큰값과 지금 와인을 마시지 않고 이전의 두 와인을 마신 경우 비교
		drinkWines[i] = max(drinkWines[i], drinkWines[i - 1]);
	}

	printf("%d\n", drinkWines[n]);
}