#include <vector>

using namespace std;

int solution(vector<int> &A) {
	int now = A.front();
	int cnt = 1;
	while (now != -1) {
		cnt++;
		now = A[now];
	}

	return cnt;
}