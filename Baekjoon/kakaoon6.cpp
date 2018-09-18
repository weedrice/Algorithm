#include <string>
#include <vector>
#include <iostream>

using namespace std;

int findBodyStart(string str) {
	int start = str.find("<body>");

	if (start != -1)
		return start + 6;
	else
		return start;
}

int findBodyEnd(string str) {
	int end = str.find("</body>");

	if (end == -1)
		return -1;
	else
		return end;
}

int getNormalScore(string s, string word) {
	string body = s.substr(findBodyStart(s), findBodyEnd(s) - findBodyStart(s));

	cout << body << endl;

	return 0;
}

int getLinkScore(string s, string word) {
	int score = 0;
	return score;
}

int solution(string word, vector<string> pages) {
	int answer = 0;
	int* normalScore = new int[pages.size()];
	int* linkScore = new int[pages.size()];
	
	int i = 0;
	for (vector<string>::iterator iter = pages.begin(); iter != pages.end(); ++iter) {
		normalScore[i] = getNormalScore(*iter, word);
		linkScore[i++] = getLinkScore(*iter, word);
	}
	return answer;
}

int main() {
	string a = "aaaaaa <body> aaaaaaaffff f</body>fffff";
	vector<string> b;
	b.push_back(a);

	int c = solution(a, b);
}