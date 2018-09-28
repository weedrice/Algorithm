#include <cstdio>
#include <cmath>

using namespace std;

int n;
int count = 0;
int* rows;

bool possible(int col) {
	//printf("col: %d일때 rows: ", col);
	//for (int i = 0; i <= col; i++) {
	//	printf("%d ", rows[i]);
	//}
	//printf("\n");

	for (int i = 0; i < col; i++) {
		if (rows[i] == rows[col])
			return false;
		if (abs(rows[i] - rows[col]) == abs(col - i))
			return false;
	}
	return true;
}

void dfs(int col) {
	if (col == n) {
		//printf("col == n\n");
		count++;
	}
	else {
		for (int i = 0; i < n; i++) {
			rows[col] = i;
			if (possible(col)) {
				dfs(col+1);
			}
		}
	}
	//printf("col: %d일때 rows: ", col);
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", rows[i]);
	//}
	//printf("\n");
}

int main() {
	scanf("%d", &n);
	rows = new int[n];
	dfs(0);
	printf("%d\n", count);
}
