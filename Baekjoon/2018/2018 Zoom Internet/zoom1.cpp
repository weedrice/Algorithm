#include <string>
#include <iostream>

using namespace std;

// 부끄럽게 문제를 해결했습니다.
// S와 T의 값에 따라 경우를 나눠 해결해보려고 했으나 방법이 떠오르지 않아 이렇게 무식한 방법으로 해결했습니다.
// 혹시 가능하다면 합불과 상관 없이 코딩테스트 이후에 문제의 해결 방법에 대해 알고싶습니다.
// 감사합니다.

bool lessTwoNums(string check) {
	int cnt = 0;
	for (int i = 0; i < check.length(); i++) {
		for (int j = i + 1; j < check.length();) {
			if (check[i] == check[j])
				check.erase(j, 1);
			else
				j++;
		}
		cnt++;
	}
	if (cnt > 2)
		return false;
	return true;
}
string timeCheck(string &check) {
	if (check[5] > '9') {
		check[4]++;
		check[5] = '0';
	}
	if (check[4] > '5') {
		check[3]++;
		check[4] = '0';
	}
	if (check[3] > '9') {
		check[2]++;
		check[3] = '0';
	}
	if (check[2] > '5') {
		check[1]++;
		check[2] = '0';
	}
	if (check[1] > '9') {
		check[0]++;
		check[1] = '0';
	}

	return check;
}

int solution(string &S, string &T) {
	// write your code in C++14 (g++ 6.2.0)
	S.erase(2, 1);
	S.erase(4, 1);
	T.erase(2, 1);
	T.erase(4, 1);
	int cnt = 0;
	while (S <= T) {
		if (lessTwoNums(S))
			cnt++;
		S[5]++;
		S = timeCheck(S);
	}

	return cnt;
}

int main() {
	string S = "22:22:21";
	string T = "22:22:23";
	int answer = solution(S, T);
	cout << answer;
}