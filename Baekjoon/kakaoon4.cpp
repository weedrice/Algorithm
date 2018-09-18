#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

bool sortByNum(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second ? true : false;
}

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int numOfFood = food_times.size();
	long long maxRotate = k / numOfFood;

	long long* eachFoodTime = new long long[numOfFood]();

	deque<pair<int, int>> copy;
	int i = 1;
	for (vector<int>::iterator iter = food_times.begin(); iter != food_times.end(); ++iter) {
		copy.push_back(pair<int, int>(*iter, i++));
	}

	sort(copy.begin(), copy.end());

	long long remainTimes = k;
	while (1) {
		//만약 네트워크 장애가 발생했지만 먹을 음식이 남아있지 않을 때
		if (copy.size() == 0) {
			return -1;
		}

		//가장 적은 음식 소모시간
		int minFoodTime = copy.front().first;
		//남은 음식 중 섭취시간이 가장 적은 음식이 없어질때까지 소모시간
		long long rotateTimes = minFoodTime * numOfFood;

		//남은 음식을 모두 먹기 전 네트워크 오류가 발생할 때
		if (remainTimes < rotateTimes) {
			break;
		}
		//한가지 음식을 다 먹은 이후에 네트워크 오류가 발생할 때
		else {
			//해당 음식을 제거하고 남아있는 음식들의 시간에서 섭취시간을 뺀다.
			deque<pair<int, int>> temp;
			for (deque<pair<int, int>>::iterator iter = copy.begin(); iter != copy.end();iter++) {
				int remainTimesOfFood = (*iter).first;
				remainTimesOfFood -= minFoodTime;

				if (remainTimesOfFood > 0) {
					temp.push_back(pair<int, int>(remainTimesOfFood, (*iter).second));
				}
			}
			copy = temp;
			remainTimes -= rotateTimes;
		}
	}

	sort(copy.begin(), copy.end(), sortByNum);

	for (deque<pair<int, int>>::iterator iter = copy.begin(); iter != copy.end(); ++iter) {
		cout << (*iter).second << "번째 음식 남은 섭취시간: " << (*iter).first << endl;
	}

	deque<pair<int, int>>::iterator iter = copy.begin();
	answer = (*iter).second;
	for(int i=0;i<remainTimes % copy.size();i++) {
		iter++;
		answer = (*iter).second;
	}
	cout << "먹어야 할 음식 번호: " << answer << endl;

	return answer;
}

int main() {
	vector<int> food_times;
	food_times.push_back(3);
	food_times.push_back(1);
	food_times.push_back(2);
	long long k = 5;
	int result = solution(food_times, k);
}