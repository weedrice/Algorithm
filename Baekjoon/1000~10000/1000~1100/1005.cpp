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
		//�ǹ��� ����, ������ ���� �Է�
		int numberOfBuildings, numberOfRules;
		scanf("%d %d", &numberOfBuildings, &numberOfRules);

		//�Ǽ� �ð��� �Է¹��� �迭 ����
		buildingTime = new int[numberOfBuildings+1];
		pre = new int[numberOfBuildings + 1]();
		//�ǹ� ������ ������ �Է¹��� �迭 ����
		buildings = new int*[numberOfBuildings+1];
		for (int i = 1; i <= numberOfBuildings; i++) {
			buildings[i] = new int[numberOfBuildings+1]();
			//�� �ǹ��� �Ǽ��ð� �Է�
			scanf("%d", &buildingTime[i]);
		}

		//�������� ���� �Է�
		while (numberOfRules--) {
			int origin, destination;
			scanf("%d %d", &origin, &destination);
			buildings[origin][destination] = 1;
			pre[destination]++;
		}

		//�¸��� ���� ����� �ϴ� ���� ��ȣ �Է�
		int finalBuilding;
		scanf("%d", &finalBuilding);
		//�Է� �Ϸ�

		printf("%d\n", findWinningTime(finalBuilding, numberOfBuildings));
	}
}
