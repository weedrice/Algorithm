
#include <stdio.h>
#include <vector>
using namespace std;

bool solution(string input) {
	bool answer = true;
	vector<char> v;

	for (int i = 0; i < input.size(); i++) {
		switch (input[i]) {
		case '[':
			if (v.empty()) {
				v.push_back('[');
			}
			else {
				if (v.back() == '[' || v.back() == '{' || v.back() == '(') {
					answer = false;
					return answer;
				}
				else {
					v.push_back('[');
				}
			}
			break;
		case '{':
			if (v.empty()) {
				v.push_back('{');
			}
			else {
				if (v.back() == '{' || v.back() == '(') {
					answer = false;
					return answer;
				}
				else {
					v.push_back('{');
				}
			}
			break;
		case '(':
			if (v.empty()) {
				v.push_back('(');
			}
			else {
				if (v.back() == '(') {
					answer = false;
					return answer;
				}
				else {
					v.push_back('(');
				}
			}
			break;
		case ']':
			if (v.empty()) {
				answer = false;
				return answer;
			}
			else {
				if (v.back() == '[') {
					v.pop_back();
				}
				else {
					answer = false;
					return answer;
				}
			}
			break;
		case '}':
			if (v.empty()) {
				answer = false;
				return answer;
			}
			else {
				if (v.back() == '{') {
					v.pop_back();
				}
				else {
					answer = false;
					return answer;
				}
			}
			break;
		case ')':
			if (v.empty()) {
				answer = false;
				return answer;
			}
			else {
				if (v.back() == '(') {
					v.pop_back();
				}
				else {
					answer = false;
					return answer;
				}
			}
			break;
		}
	}
	if (v.empty()) {
		return answer;
	}
	else {
		return false;
	}
	
}

int main() {
	string input = "3+{(5+1}";
	if (solution(input))
		printf("true\n");
	else
		printf("false\n");
}