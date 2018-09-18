#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int firstPrize[7] = { 0, 5000000,3000000,2000000,500000,300000,100000 };
int secondPrize[6] = { 0, 5120000, 2560000, 1280000, 640000, 320000 };

int getFirstRank(int a) {
	int sum = 0;
	if (a > 21 || a == 0)
		return sum;

	for (int i = 1; i < 7; i++) {
		sum += i;
		if (sum >= a) {
			return i;
		}
	}
}

int getSecondRank(int a) {
	int sum = 0;
	if (a > 31 || a == 0)
		return sum;

	for (int i = 0; i < 5; i++) {
		sum += pow(2, i);
		if (sum >= a)
			return i+1;
	}
}

int main() {
	srand(time(NULL));
	int t;
	cin >> t;
	for(int i=0;i<t;i++) {
		int firstRank, secondRank;
		//cin >> firstRank >> secondRank;
		//scanf("%d %d", &firstRank, &secondRank);
		firstRank = rand()%101;
		secondRank = rand()%65;
		
		cout << "1번째 대회 등수: " << firstRank << endl;
		cout << "2번째 대회 등수: " << secondRank << endl;

		int prizeSum = firstPrize[getFirstRank(firstRank)] + secondPrize[getSecondRank(secondRank)];
		cout << prizeSum << endl;
	}
}