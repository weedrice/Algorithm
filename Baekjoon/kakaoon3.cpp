#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool findCandidates(vector<string> v) {
	sort(v.begin(), v.end());
	int count = 0;
	for (vector<string>::iterator iter = v.begin(); iter != v.end() - 1; ++iter) {
		if (*iter == *(iter + 1))
			count++;
	}

	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}


int solution(vector<vector<string>> relation) {
	int answer = 0;
	int attributeSize = relation.front.size();
	bool* isCandidate = new bool[attributeSize]();
	vector<string>* candidates = new vector<string>[attributeSize];
	for (vector<vector<string>>::iterator iter = relation.begin(); iter != relation.end(); ++iter) {
		int i = 0;
		for (vector<string>::iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); ++iter2) {
			candidates[i++].push_back((*iter2));
		}
	}

	for (int i = 0; i < attributeSize; i++) {
		vector<string> tempVector;
		for (vector<string>::iterator iter = candidates[i].begin(); iter != candidates[i].end() - 1; ++iter) {
			string newString = *iter;
			for (int j = i + 1; j < attributeSize; j++) {
				for (int k = j + 1; k < attributeSize; k++) {

				}
				newString.append(candidates[j].front());
			}
		}
		
	}
	
	for (int i = 0; i < attributeSize; i++) {
		sort(candidates[i].begin(), candidates[i].end());
		int count = 0;
		for (vector<string>::iterator iter = candidates[i].begin(); iter != candidates[i].end() - 1; ++iter) {
			if (*iter == *(iter + 1))
				count++;
		}
		if (count == 0) {
			isCandidate[i] = true;
			answer++;
		}
	}
	
	return answer;
}

int main() {
	vector<vector<string>> relation;
	int n = 6;
	while (n--) {
		int m = 4;
		vector<string> tuple;
		while (m--) {
			string a;
			cin >> a;
			tuple.push_back(a);
		}
		relation.push_back(tuple);
	}

	int num = solution(relation);
	cout << "answer: " << num << endl;
}