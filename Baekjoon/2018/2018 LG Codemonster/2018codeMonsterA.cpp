#include <cstdio>
#include <vector>

using namespace std;

int gap(int a, int b) {
	return a > b ? a - b : b - a;
}

int solution(vector<int> people, vector<int> tshirts) {
	int answer = 0;
	int availableTshirts[1001] = { 0, };
	int needTshirts[1001] = { 0, };
	
	for (vector<int>::iterator iter = people.begin(); iter != people.end(); ++iter) {
		needTshirts[*iter]++;
	}
	for (vector<int>::iterator iter = tshirts.begin(); iter != tshirts.end(); ++iter) {
		availableTshirts[*iter]++;
	}

	for (int i = 1; i < 1001; i++) {
		if (needTshirts[i] <= availableTshirts[i]) {
			answer += needTshirts[i];
		}
		else if (needTshirts[i] > availableTshirts[i]) {
			answer += availableTshirts[i];
		}
	}

	return answer;
}

int main() {
	vector<int> people;
	vector<int> tshirts;
	people.push_back(1);
	people.push_back(2);
	people.push_back(3);
	tshirts.push_back(1);
	tshirts.push_back(1);
	//tshirts.push_back(3);
	int answer = solution(people, tshirts);
	printf("%d\n", answer);
}