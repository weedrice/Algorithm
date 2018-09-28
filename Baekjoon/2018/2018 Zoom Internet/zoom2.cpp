#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	int cnt = 1;
	for (int i = 0; i < S.length();) {
		if (S[i] == S[i + 1]) {
			S.erase(i, 2);
			if(i)
				i--;
		}
		else {
			i++;
		}
	}

	return S;
}

int main() {
	string S = "ABCCBCCA";
	S = solution(S);
	cout << S;
}