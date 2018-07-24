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
		//���ݿ��ΰ� ������ ������ ���Ű��� ���� ������ ���ð� ������ ������ ������ ������츦 ��(2��° ���� ������ ������)
		drinkWines[i] = max(wines[i] + wines[i - 1] + drinkWines[i-3], wines[i] + drinkWines[i - 2]);
		//������ �� ū���� ���� ������ ������ �ʰ� ������ �� ������ ���� ��� ��
		drinkWines[i] = max(drinkWines[i], drinkWines[i - 1]);
	}

	printf("%d\n", drinkWines[n]);
}