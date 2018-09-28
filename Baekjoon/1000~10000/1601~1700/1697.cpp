#include <cstdio>
#include <queue>

using namespace std;

bool isVisited[100001] = { false, };

int bfs(int n, int k) {
	queue<int> q;
	int count = 0;

	q.push(n);
	isVisited[n] = true;
	while (1) {
		int max = q.size();

		for (int i = 0; i < max; i++) {
			int next = q.front();
			q.pop();

			if (next == k)
				return count;

			if (next > 0 && isVisited[next - 1] == false) {
				q.push(next - 1);
				isVisited[next - 1] = true;
			}
			if (next < 100000 && isVisited[next + 1] == false) {
				q.push(next + 1);
				isVisited[next + 1] = true;
			}
			if (next * 2 <= 100000 && isVisited[next * 2] == false) {
				q.push(next * 2);
				isVisited[next * 2] = true;
			}
		}
		count++;
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	printf("%d\n", bfs(n, k));
}