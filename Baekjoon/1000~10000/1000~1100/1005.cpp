#include <cstdio>
#include <queue>

int* buildingTime;
int** buildings;
int* pre;

int max(int a, int b) {
	return a > b ? a : b;
}

int findWinningTime(int goal, int numberOfBuildings) {
	std::queue<int> bfs;
	int* totalBuildTime = new int[numberOfBuildings+1]();

	for (int i = 1; i <= numberOfBuildings; i++) {
		if (pre[i] == 0) {
			bfs.push(i);
		}
	}
	
	while (pre[goal]) {
		int now = bfs.front();
		bfs.pop();
		for (int i = 1; i <= numberOfBuildings; i++) {
			if (buildings[now][i] == 1) {
				totalBuildTime[i] = max(totalBuildTime[i], buildingTime[now] + totalBuildTime[now]);
				pre[i]--;
				if(pre[i] == 0)
					bfs.push(i);
			}
		}
	}

	return totalBuildTime[goal] + buildingTime[goal];
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		//건물의 개수, 간선의 개수 입력
		int numberOfBuildings, numberOfRules;
		scanf("%d %d", &numberOfBuildings, &numberOfRules);

		//건설 시간을 입력받을 배열 선언
		buildingTime = new int[numberOfBuildings+1];
		pre = new int[numberOfBuildings + 1]();
		//건물 사이의 간선을 입력받을 배열 선언
		buildings = new int*[numberOfBuildings+1];
		for (int i = 1; i <= numberOfBuildings; i++) {
			buildings[i] = new int[numberOfBuildings+1]();
			//각 건물의 건설시간 입력
			scanf("%d", &buildingTime[i]);
		}

		//빌딩간의 간선 입력
		while (numberOfRules--) {
			int origin, destination;
			scanf("%d %d", &origin, &destination);
			buildings[origin][destination] = 1;
			pre[destination]++;
		}

		//승리를 위해 지어야 하는 빌딩 번호 입력
		int finalBuilding;
		scanf("%d", &finalBuilding);
		//입력 완료

		printf("%d\n", findWinningTime(finalBuilding, numberOfBuildings));
	}
}
