#include <cstdio>
#include <stack>

using namespace std;

int** matrix;
int** canVisit;

void dfs(int n) {
	for (int i = 0; i < n; i++) {
		stack<int> st;
		bool* isVisited = new bool[n]();

		st.push(i);
		while (!st.empty()) {
			int now = st.top();
			st.pop();
			for (int j = 0; j < n; j++) {
				if (matrix[now][j] == 1 && isVisited[j] == false) {
					st.push(j);
					isVisited[j] = true;
					canVisit[i][j] = 1;
				}
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	matrix = new int*[n];
	canVisit = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n]();
		canVisit[i] = new int[n]();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			scanf("%d", &temp);
			matrix[i][j] = temp;
		}
	}

	dfs(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", canVisit[i][j]);
		}
		printf("\n");
	}
}