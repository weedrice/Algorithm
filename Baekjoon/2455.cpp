#include <cstdio>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int in[4];
	int out[4];

	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &out[i], &in[i]);
	}

	int people[4];
	people[0] = in[0];
	people[1] = people[0] + in[1] - out[1];
	people[2] = people[1] + in[2] - out[2];
	people[3] = people[2] - out[3];

	int maximum = max(max(people[0], people[1]), max(people[2], people[3]));
	printf("%d\n", maximum);
}