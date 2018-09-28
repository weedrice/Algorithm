#include <cstdio>
#include <cmath>

using namespace std;

int abs(int a, int b) {
	return a > b ? a - b : b - a;
}

bool inSpace(int x1, int y1, int spaceX, int spaceY, int spaceSize) {
	long long distance = pow(abs(x1, spaceX), 2) + pow(abs(y1, spaceY), 2);
	if (spaceSize * spaceSize > distance) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		int princeX, princeY, destinationX, destinationY;
		scanf("%d %d %d %d", &princeX, &princeY, &destinationX, &destinationY);
		int borders = 0;

		int numOfPlanet;
		scanf("%d", &numOfPlanet);
		while (numOfPlanet--) {
			int spaceX, spaceY, spaceSize;
			scanf("%d %d %d", &spaceX, &spaceY, &spaceSize);
			if (inSpace(princeX, princeY, spaceX, spaceY, spaceSize)) {
				if (inSpace(destinationX, destinationY, spaceX, spaceY, spaceSize)) {
					continue;
				}
				else {
					borders++;
				}
			}
			else {
				if (inSpace(destinationX, destinationY, spaceX, spaceY, spaceSize)) {
					borders++;
				}
				else {
					continue;
				}
			}
		}
		printf("%d\n", borders);
	}
}