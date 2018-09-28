#include <iostream>

using namespace std;

int* arr;
int n, s;
int cnt = 0;

void dfs(int sum, int now) {
	if (now >= n) {
		if (s == sum) {
			cnt++;
		}
		return;
	}

	dfs(sum + arr[now], now + 1);
	dfs(sum, now + 1);
}

int main() {
	cin >> n >> s;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);

	if (s == 0)
		cnt--;

	cout << cnt << endl;
}