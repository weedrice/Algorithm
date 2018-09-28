#include <cstdio>
#include <algorithm>
#include <vector>

int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	int* numArr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &numArr[i]);
	}
	std::sort(numArr, numArr + n);

	int gap = numArr[1] - numArr[0];
	for (int i = 1; i < n - 1; i++) {
		gap = gcd(gap, numArr[i + 1] - numArr[i]);
	}

	std::vector<int> printArr;
	for (int i = 2; i * i <= gap; i++) {
		if (gap%i == 0) {
			printArr.push_back(i);
			if (i*i < gap) {
				printArr.push_back(gap / i);
			}
		}
	}
	printArr.push_back(gap);

	std::sort(printArr.begin(), printArr.end());
	for (std::vector<int>::iterator iter = printArr.begin(); iter != printArr.end();iter++) {
		printf("%d ", *iter);
	}
}