#include <vector>

using namespace std;

int solution(vector<int> &A) {
	int countF = 0;
	int countT = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == 1) {
			countF++;
		}
		else {
			countT++;
		}
	}

	return countF > countT ? countF - countT : countT - countF;
}