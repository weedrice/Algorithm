#include <cstdio>

int calc_new_num(int num) {
	if (num < 10)
		return (num * 10) + num;
	else {
		int a = num % 10;
		int b = num / 10;

		return (a * 10) + ((a + b) % 10);
	}
}

int main() {
	int num;
	int cycle = 0;
	scanf("%d", &num);
	int original_num = num;
	while (1) {
		cycle++;
		int new_num = calc_new_num(num);

		if (original_num == new_num)
			break;
		else
			num = new_num;
	}

	printf("%d", cycle);
}