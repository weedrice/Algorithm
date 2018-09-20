#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	deque<int> dq;
	int n;
	scanf("%d", &n);
	while (n--) {
		int waiting;
		scanf("%d", &waiting);
		dq.push_back(waiting);
	}
	sort(dq.begin(), dq.end());
	int sum = 0;
	int waitSum = 0;
	while (!dq.empty()) {
		int person = dq.front();
		dq.pop_front();
		sum = sum + person;
		waitSum = waitSum + sum;
	}

	printf("%d\n", waitSum);
}