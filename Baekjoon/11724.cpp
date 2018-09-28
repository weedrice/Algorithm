#include <iostream>
#include <stack>
#include <deque>

using namespace std;

int** matrix;
bool* isVisited;
int n;

void dfs(int now) {
	isVisited[now] = true;

	for (int i = 0; i < n; i++) {
		if (matrix[now][i] == 1 && isVisited[i] == false)
			dfs(i);
	}
}

int main() {
	int m;
	int count = 0;
	cin >> n >> m;
	
	matrix = new int*[n];
	isVisited = new bool[n]();
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n]();
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		matrix[a-1][b-1] = 1;
		matrix[b-1][a-1] = 1;
	}
	
	for (int i = 0; i < n; i++) {
		if (!isVisited[i]) {
			dfs(i);
			count++;
		}
	}
		
	cout << count << endl;
}