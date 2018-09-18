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
		//���� ��Ʈ��ũ ��ְ� �߻������� ���� ������ �������� ���� ��
		if (copy.size() == 0) {
			return -1;
		}

		//���� ���� ���� �Ҹ�ð�
		int minFoodTime = copy.front().first;
		//���� ���� �� ����ð��� ���� ���� ������ ������������ �Ҹ�ð�
		long long rotateTimes = minFoodTime * numOfFood;

		//���� ������ ��� �Ա� �� ��Ʈ��ũ ������ �߻��� ��
		if (remainTimes < rotateTimes) {
			break;
		}
		//�Ѱ��� ������ �� ���� ���Ŀ� ��Ʈ��ũ ������ �߻��� ��
		else {
			//�ش� ������ �����ϰ� �����ִ� ���ĵ��� �ð����� ����ð��� ����.
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
		cout << (*iter).second << "��° ���� ���� ����ð�: " << (*iter).first << endl;
	}

	deque<pair<int, int>>::iterator iter = copy.begin();
	answer = (*iter).second;
	for(int i=0;i<remainTimes % copy.size();i++) {
		iter++;
		answer = (*iter).second;
	}
	cout << "�Ծ�� �� ���� ��ȣ: " << answer << endl;

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