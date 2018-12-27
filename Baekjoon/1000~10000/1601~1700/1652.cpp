#include <cstdio>
#include <cstring>
#include <iostream>

int counting(bool** matrix, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		int space = 0;
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == false) {
				space++;
			}
			else {
				if (space > 1) {
					count++;
				}
				space = 0;
			}
		}
		if (space > 1) {
			count++;
		}
	}

	return count;
}

int counting2(bool** matrix, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		int space = 0;
		for (int j = 0; j < n; j++) {
			if (matrix[j][i] == false) {
				space++;
			}
			else {
				if (space > 1) {
					count++;
				}
				space = 0;
			}
		}
		if (space > 1) {
			count++;
		}
	}

	return count;
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();

	bool** matrix = new bool*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			char input;
			scanf("%c", &input);
			if (input == '.') {
				matrix[i][j] = false;
			}
			else {
				matrix[i][j] = true;
			}
		}
		getchar();
	}
	//input end
	int horisonCount = counting(matrix, n);
	int verticalcount = counting2(matrix, n);

	printf("%d %d\n", horisonCount, verticalcount);
}