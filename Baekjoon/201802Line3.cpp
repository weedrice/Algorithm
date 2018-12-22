#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int* list;
bool *isFinal;
vector<int> answer;

void dfs(int ori, int cnt = 0) {
	if (list[ori] == 0 && cnt > 0) {
		if (!isFinal[ori]) {
			answer.push_back(ori + 1);
			isFinal[ori] = true;
		}
		return;
	}

	dfs(list[ori], cnt+1);
}

int main() {
	int n;
	cin >> n;
	
	int max = 0;
	isFinal = new bool[1001]();
	list = new int[1001]();
	while (n-- > 0) {
		string line;
		getline(cin, line);  // drop a newline traling n
		stringstream ss(line);
		vector<int> inputs;
		for (int fork; !(ss >> fork).fail(); ) {  // read forks from a note
			inputs.push_back(fork-1);				  // @todo Write your code here.
		}

		if (!inputs.empty()) {
			for (int i = 0; i < inputs.size() - 1; i++) {
				int origin = inputs[i];
				int desti = inputs[i + 1];
				//if (list[origin] != 0) {
				//	cout << "-1" << endl;
				//	return 0;
				//}
				list[origin] = desti;
				max = desti > max ? desti : max;
			}
		}
	}

	for (int i = 0; i <= max; i++) {
		if (list[i] != 0)
			dfs(i);
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}
