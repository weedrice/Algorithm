#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(int* arr, int n, int size) {
	int start = 0;
	int end = size;
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2;

		if (arr[mid] == n) {
			return true;
		}
		else if (arr[mid] > n) {
			end = mid - 1;
		}
		else if (arr[mid] < n) {
			start = mid + 1;
		}
	}

	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr+n);

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int input;
		scanf("%d", &input);
		if (binarySearch(arr, input, n-1) == true) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}

}