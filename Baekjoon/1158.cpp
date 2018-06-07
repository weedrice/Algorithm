#include <cstdio>
#include <queue>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	std::queue<int> queue;
	for (int i = 1; i <= n; i++) {
		queue.push(i);
	}
	int idx = 1;
	printf("<");
	while (!queue.empty()) {
		if (idx == m) {
			printf("%d", queue.front());
			queue.pop();
			if (queue.size() >= 1) {
				printf(", ");
			}
			idx = idx - m + 1;
		}
		else {
			int value = queue.front();
			queue.pop();
			queue.push(value);
			idx++;
		}
	}
	printf(">\n");
}