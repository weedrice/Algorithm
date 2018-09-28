#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string calculate(string rule, string A, string B);
string numToString(string rule, int num);

string calculate(string rule, string A, string B) {
	long long decimal = 0;
	int numberSize = rule.size();
	int *ruleArray = new int[numberSize]();
	for (int i = 0; i < numberSize; i++) {
		ruleArray[rule[i] - 97] = i;
	}
	for (int i = 0; i < A.size(); i++) {
		decimal += ruleArray[A[i] - 97] * pow(numberSize, (A.size() - i - 1));
	}
	for (int i = 0; i < B.size(); i++) {
		decimal -= ruleArray[B[i] - 97] * pow(numberSize, (B.size() - i - 1));
	}

	return numToString(rule, decimal);
}

string numToString(string rule, int num) {
	string result;
	vector<char> arr;
	while (num != 0) {
		arr.push_back(rule[num%rule.size()]);
		num = num / rule.size();
	}
	while (!arr.empty()) {
		result += arr.back();
		arr.pop_back();
	}
	return result;
}

string solution(string rule, string A, string B) {
	return calculate(rule, A, B);
}

int main() {
	string rule = "ab";
	string A = "ba";
	string B = "a";
	string answer = solution(rule, A, B);
	cout << answer;
}