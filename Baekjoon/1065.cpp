#include <cstdio>

bool check_num(int num);
int calc_gap(int a, int b);

int main() {
	int n;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (check_num(i))
			sum++;
	}
	printf("%d", sum);
}

bool check_num(int num)
{
	if (num < 100) {
		return true;
	}
	else {
		int a, b, gap;
		a = num % 10;
		num /= 10;
		b = num % 10;
		gap = calc_gap(a, b);
		while (num >= 10) {
			int new_gap;
			a = b;
			if (num == 10)
				b = 1;
			else {
				num /= 10;
				b = num % 10;
			}
			new_gap = calc_gap(a, b);
			if (gap != new_gap)
				return false;
		}
	}
	return true;
}

int calc_gap(int a, int b) {
	int gap = 0;
	gap = a - b;
	return gap;
}
