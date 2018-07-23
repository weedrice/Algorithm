#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) {
		return true;
	}
	else {
		return false;
	}
}

int* getRank(vector<pair<int, int>> gradeIndex) {
	int ranks = 0;
	int sameScorer = 0;
	int before = -1;
	int* rank = new int[gradeIndex.size()]();
	vector<pair<int, int>>::iterator iter = gradeIndex.begin();
	for (; iter != gradeIndex.end(); iter++) {
		if ((*iter).first == before) {
			if (sameScorer == 0) {
				ranks--;
			}
			rank[(*iter).second] = ranks;
			sameScorer++;
		}
		else {
			rank[(*iter).second] += ++ranks;
			before = (*iter).first;
			sameScorer = 0;
		}
	}

	return rank;
}

vector<int> solution(vector<int> grade) {
	vector<int> answer;
	vector<pair<int, int>> gradeIndex;

	vector<int>::iterator iter = grade.begin();
	for (int i = 0; iter != grade.end(); iter++, i++) {
		gradeIndex.push_back(pair<int, int>(*iter, i));
	}

	sort(gradeIndex.begin(), gradeIndex.end(), compare);

	int* rank = getRank(gradeIndex);

	for (int i = 0; i < grade.size(); i++) {
		answer.push_back(rank[i]);
	}

	return answer;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> grade;
	while (n--) {
		int score;
		scanf("%d", &score);
		grade.push_back(score);
	}

	grade = solution(grade);
	vector<int>::iterator iter = grade.begin();
	printf("[");
	for (; iter != grade.end(); iter++) {
		printf("%d,", *iter);
	}
	printf("]\n");
}

