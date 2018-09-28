#include <cstdio>
#include <cmath>
#include <deque>
#include <algorithm>

//다시풀것
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k, length;
		scanf("%d %d %d", &n, &length, &k);
		deque<pair<int, int>> ants;
		deque<int> antsID;
		bool* heading = new bool[n + 1];
		for (int i = 0; i < n; i++) {
			int antLocation, antID;
			scanf("%d %d", &antLocation, &antID);
			if (antID < 0) {
				ants.push_back(pair<int, int>(antLocation, antID));
			}
			else {
				ants.push_back(pair<int, int>(length - antLocation, antID));
			}
			antsID.push_back(antID);
		}

		sort(ants.begin(), ants.end());
		deque<pair<int, int>> falling;
		for(deque<pair<int, int>>::iterator iter = ants.begin();iter!=ants.end();++iter) {
			if ((*iter).second > 0) {
				falling.push_back(pair<int, int>((*iter).first, antsID.back()));
				antsID.pop_back();
			}
			else {
				falling.push_back(pair<int, int>((*iter).first, antsID.front()));
				antsID.pop_front();
			}
		}

		sort(falling.begin(), falling.end());
		printf("%d\n", falling[k-1].second);
	}
}