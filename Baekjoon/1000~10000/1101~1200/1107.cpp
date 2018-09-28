#include <cstdio>
#include <cmath>

using namespace std;

bool nums[10] = { true, true, true, true, true, true, true, true, true, true };

int getDivisor(int num) {
	int count = 0;
	if (num == 0)
		return 1;
	while (num > 0) {
		num /= 10;
		count++;
	}
	return count;
}

bool itCanType(int num) {
	if (num < 0) {
		return false;
	}
	if (num == 0)
		return nums[0];
	while (num > 0) {
		int rest = num % 10;
		if (nums[rest] == false)
			return false;
		num /= 10;
	}
	return true;
}

int gap(int a, int b) {
	return a > b ? a - b : b - a;
}

int main() {
	int channel;
	scanf("%d", &channel);
	int numGap = gap(channel, 100);

	int brokenNums;
	scanf("%d", &brokenNums);

	for(int i=0;i<brokenNums;i++) {
		int num;
		scanf("%d", &num);
		nums[num] = false;
	}

	if (brokenNums == 10) {
		printf("%d\n", numGap);
		return 0;
	}

	int nearestNum = 0;
	for (int i = 0; i < numGap; i++) {
		if (itCanType(channel - i)) {
			nearestNum = channel - i;
			break;
		}
		else if (itCanType(channel + i)) {
			nearestNum = channel + i;
			break;
		}
	}

	nearestNum = gap(channel, nearestNum) + getDivisor(nearestNum);
	numGap = numGap < nearestNum ? numGap : nearestNum;
	printf("%d\n", numGap);
}