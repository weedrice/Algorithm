#include <iostream>

using namespace std;

int** matrix;
bool* isVisited;
int n;

int main() {
	int e;
	cin >> n >> e;
	matrix = new int*[n];
	isVisited = new bool[n]();
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n]();
	}

	while (e--) {
		int ori, des;
		cin >> ori >> des;

	}
}