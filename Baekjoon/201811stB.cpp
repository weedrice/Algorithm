#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string &S, string token) {
	vector<string> v;
	while (1) {
		string subStr;
		int now = S.find(token[0]);
		for (int i = 0; i < token.size(); i++) {
			if (now > S.find(token[i]))
				now = S.find(token[i]);
		}

		if (now == -1) {
			if (S.size() > 0)
				v.push_back(S);
			return v;
		}
		else {
			subStr = S.substr(0, now);
		}
		if (subStr.size() > 0)
			v.push_back(subStr);
		S.erase(0, now + 1);
	}
	
}

int solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	// 긴 문장 나누기
	vector<string> v = split(S, ".!?");


	//가장 많은 단어를 보유한 문장 찾기
	int max = 0;
	for (int i = 0; i < v.size(); i++) {
		vector<string> sentence = split(v[i], " ");
		int temp = sentence.size();
		max = max > temp ? max : temp;
		cout << v[i] << endl;
	}

	return max;
}

int main() {
	string S = "We test coders. Give us a try?";
	int num = solution(S);
	cout << num << endl;
}