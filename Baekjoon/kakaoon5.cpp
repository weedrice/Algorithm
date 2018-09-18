#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;



typedef struct tree {
	int x;
	int y;
	tree* leftChild;
	tree* rightChild;
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	tree* root;

	sort(nodeinfo.begin(), nodeinfo.end());

	for(vector<vector<int>>::iterator iter = nodeinfo.begin(); iter != nodeinfo.end(); iter++) {
		for (vector<int>::iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++) {
			cout << *iter2 << endl;
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> v;
	vector<int> b;
	b.push_back(11);
	b.push_back(5);
	v.push_back(b);
	vector<int> a;
	a.push_back(5);
	a.push_back(3);
	v.push_back(a);
	vector<int> c;
	a.push_back(13);
	a.push_back(3);
	v.push_back(c);
	vector<int> d;
	a.push_back(3);
	a.push_back(5);
	v.push_back(d);

	v = solution(v);
}