#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int>* tree;
bool* isVisited;

int dfs(int start, int end) {
	if (start == end)
		return 1;

	queue<int> q;
	for (vector<int>::iterator iter = tree[start].begin(); iter != tree[start].end(); iter++) {
		q.push(*iter);
		isVisited[start] = true;
	}

	int count = 2;
	while (1) {
		int size = q.size();
		for(int i=0;i<size;i++) {
			int next = q.front();
			q.pop();

			if (next == end) {
				return count;
			}
			
			for (vector<int>::iterator iter = tree[next].begin(); iter != tree[next].end(); iter++) {
				if (isVisited[*iter] == false) {
					q.push(*iter);
					isVisited[next] = true;
				}
			}
			
		}
		count++;
	}
	return count;
}

vector<int> solution(int N, vector<vector<int>> directory, vector<vector<int>> query) {
	vector<int> answer;
	tree = new vector<int>[N+1];
	for (int i = 0; i < directory.size(); i++) {
		tree[directory[i].front()].push_back(directory[i].back());
		tree[directory[i].back()].push_back(directory[i].front());
	}

	for (int i = 0; i < query.size(); i++) {
		isVisited = new bool[N+1]();
		answer.push_back(dfs(query[i].front(), query[i].back()));
	}

	return answer;
}

int main() {
	int n = 4;
	int size = 3;
	vector<vector<int>> directory;
	vector<vector<int>> query;
	for (int i = 0; i < size; i++) {
		int root, child;
		vector<int> temp;
		scanf("%d %d", &root, &child);
		temp.push_back(root);
		temp.push_back(child);
		directory.push_back(temp);
	}
	for (int i = 0; i < size; i++) {
		int start, end;
		vector<int> temp;
		scanf("%d %d", &start, &end);
		temp.push_back(start);
		temp.push_back(end);
		query.push_back(temp);
	}
	vector<int> temp = solution(n, directory, query);
}