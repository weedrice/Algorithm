#include <cstdio>

bool isEven(int a) {
	return (a % 2) == 0 ? true : false;
}

bool match(int a, int b) {
	if (isEven(a)) {
		return (a - 1) == b ? true : false;
	}
	else {
		if (isEven(b)) {
			return (b - 1) == a ? true : false;
		}

		return false;
	}
}

int nextMatch(int a) {
	if (isEven(a))
		return a / 2;

	return (a / 2) + 1;
}

int main() {
	int n, kim, lim;
	scanf("%d %d %d", &n, &kim, &lim);

	int round = 1;
	while (!match(kim, lim)) {
		kim = nextMatch(kim);
		lim = nextMatch(lim);
		round++;
	}

	printf("%d", round);
}