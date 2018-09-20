#include <cstdio>
#include <stack>

using namespace std;

int** matrix;
bool* isVisited;

int dfs(int numOfComputer) {
	stack<int> s;
	int count = 0;

	s.push(1);
	isVisited[1] = true;

	while (!s.empty()) {
		int now = s.top();
		s.pop();
		for (int i = 1; i <= numOfComputer; i++) {
			if (matrix[now][i] == 1 && isVisited[i] == false) {
				isVisited[i] = true;
				s.push(i);
				count++;
			}
		}
	}
	return count;
}

int main() {
	int numOfComputer;
	scanf("%d", &numOfComputer);
	int edges;
	scanf("%d", &edges);

	matrix = new int*[numOfComputer+1];
	isVisited = new bool[numOfComputer+1];
	for (int i = 1; i <= numOfComputer; i++) {
		matrix[i] = new int[numOfComputer+1]();
		isVisited[i] = false;
	}
	while (edges--) {
		int start, end;
		scanf("%d %d", &start, &end);
		matrix[start][end] = 1;
		matrix[end][start] = 1;
	}

	printf("%d\n", dfs(numOfComputer));
}