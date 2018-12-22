#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int solution(vector<int> &A) {
	sort(A.begin(), A.end(), greater<int>());
	int max = A.front();
	for (int i = 0; i < A.size(); i++) {
		if (A[i] >= max)
			max = A[i]--;
		else {
			if (A[i] != max)
				break;
		}
	}
}