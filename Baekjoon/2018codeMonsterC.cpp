#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <functional>

using namespace std;

vector<int> solution(vector<int> healths, vector<vector<int>> items) {
	vector<int> answer;
	deque<pair<int, int>> newItemVec;
	for (int i = 0; i < items.size(); i++) {
		newItemVec.push_back(pair<int, int>(items[i].back(), i+1));
	}
	sort(healths.begin(), healths.end(), greater<int>());
	sort(newItemVec.begin(), newItemVec.end(), greater<pair<int, int>>());

	vector<int>::iterator iterHealth = healths.begin();
	while (iterHealth != healths.end() && !newItemVec.empty()) {
		if ((*iterHealth) > newItemVec.front().first) {
			answer.push_back(newItemVec.front().second);
			newItemVec.pop_front();
			iterHealth++;
		}
		else {
			newItemVec.pop_front();
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	vector<int> healths;
	vector<vector<int>> items;
	int healthNum = 3;
	int itemsNum = 3;;
	for (int i = 0; i < healthNum; i++) {
		int temp;
		scanf("%d", &temp);
		healths.push_back(temp);
	}
	for (int i = 0; i < itemsNum; i++) {
		int tempA, tempB;
		scanf("%d %d", &tempA, &tempB);
		vector<int> temp;
		temp.push_back(tempA);
		temp.push_back(tempB);
		items.push_back(temp);
	}

	vector<int> result = solution(healths, items);
	for (vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter) {
		printf("%d ", *iter);
	}
}