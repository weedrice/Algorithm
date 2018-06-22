#include <cstdio>
#include <cmath>

using namespace std;

int abs(int x, int y) {
	return x > y ? x - y : y - x;
}

long long cal_location(int x1, int y1, int x2, int y2) {
	long long distance = pow(abs(x1, x2), 2) + pow(abs(y1, y2), 2);
	return distance;
}

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		long long distance = cal_location(x1, y1, x2, y2);
		long long sum = pow(r1 + r2, 2);
		long long min = pow(abs(r1, r2), 2);
		if (distance == 0) {
			if (r1 == r2) {
				printf("-1\n");
			}
			else {
				printf("0\n");
			}
		}
		else {
			if (distance < sum && distance > min) {
				printf("2\n");
			}
			else if(distance == sum) {
				printf("1\n");
			}
			else if (distance == min) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
	}
}