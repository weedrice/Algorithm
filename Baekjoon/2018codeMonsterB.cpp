#include <cstdio>
#include <vector>
#include <cmath>
#include <functional>
#include <algorithm>

using namespace std;

int matrix[201][201];

int getDistance(int x1, int y1, int x2, int y2) {
	return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

void getNewDistances(int x, int y) {
	int minX, minY;
	int min = 0;
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			int newDistance = getDistance(i, j, x + 100, y + 100);
			if (matrix[i][j] > 0) {
				matrix[i][j] = matrix[i][j] > newDistance ? newDistance : matrix[i][j];
			}
			else {
				matrix[i][j] = newDistance;
			}
		}
	}
}

int solution(int N, vector<vector<int>> house) {
	int answer = 0;
	
	int houseX, houseY;
	for (int i = 0; i < house.size(); i++) {
		houseX = house[i].front();
		houseY = house[i].back();
		getNewDistances(houseX, houseY);
	}

	vector<int> distances;
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			distances.push_back(matrix[i][j]);
		}
	}
	sort(distances.begin(), distances.end(), greater<int>());
	answer = distances[N-1];

	return answer;
}

int main() {
	vector<vector<int>> house;
	int N = 380;
	for (int i = 0; i < 2; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vector<int> location;
		location.push_back(x);
		location.push_back(y);
		house.push_back(location);
	}
	printf("%d\n", solution(N, house));
}