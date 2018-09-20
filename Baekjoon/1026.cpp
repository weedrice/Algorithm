#include <cstdio>
#include <deque>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	deque<int> a;
	deque<int> b;

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		a.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		b.push_back(num);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a.front() * b.front();
		a.pop_front();
		b.pop_front();
	}
	printf("%d\n", sum);
}