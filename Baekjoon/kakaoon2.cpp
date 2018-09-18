#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool sortRule(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first) {
		return a.second < b.second ? true : false;
	}
	else
		return a.first > b.first ? true : false;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int* tryUser = new int[N + 2]();
	int* clearUser = new int[N + 2]();
	int* totalUser = new int[N + 2]();
	double* clearRate = new double[N + 2]();
	int numOfUser = stages.size();
	for (vector<int>::iterator iter = stages.begin(); iter != stages.end(); ++iter) {
		tryUser[(*iter)]++;
	}

	vector<pair<double, int>> sortArr;
	for (int i = N; i > 0; i--) {
		clearUser[i] += tryUser[i+1] + clearUser[i+1];
		totalUser[i] = clearUser[i] + tryUser[i];
		if (totalUser[i] == 0) {
			clearRate[i] = 0;
			sortArr.push_back(pair<double, int>(clearRate[i], i));
		}
		else {
			clearRate[i] = (double)tryUser[i] / (double)totalUser[i];
			sortArr.push_back(pair<double, int>(clearRate[i], i));
		}
	}

	sort(sortArr.begin(), sortArr.end(), sortRule);

	for (vector<pair<double, int>>::iterator iter = sortArr.begin(); iter != sortArr.end();++iter) {
		answer.push_back((*iter).second);
		cout << "Stage num: " << (*iter).second << endl;
		cout << "Clear rate: " << (*iter).first << endl;
	}

	return answer;
}

int main() {
	int N = 5;
	int input = 0;
	vector<int> stages;
	while (input != -1) {
		cin >> input;
		stages.push_back(input);
	}
	vector<int> answer = solution(N, stages);
}