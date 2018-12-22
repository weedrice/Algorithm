#include <iostream>
#include <deque>
#include <vector>

using namespace std;
deque<int> cardLst;
deque<int> tempCards;

void shuffles(int n) {
	deque<int> saveF, saveB;
	for (int i = 0; i < n; i++) {
		saveB.push_front(cardLst.back());
		cardLst.pop_back();
	}
	for (int i = 0; i < n; i++) {
		saveF.push_back(cardLst.front());
		cardLst.pop_front();
	}
	for (int i = 0; i < n; i++) {
		tempCards.push_front(saveB.back());
		saveB.pop_back();
	}
	for (int i = 0; i < n; i++) {
		tempCards.push_front(saveF.back());
		saveF.pop_back();
	}
}


int main() {
	int c, p;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cardLst.push_back(i + 1);
	}

	cin >> p;
	for (int i = 0; i < p; i++) {
		int n;
		cin >> n;
		while (cardLst.size() > 2 * n) {
			shuffles(n);
		}
		for (int i = 0; i < tempCards.size(); i++) {
			cardLst.push_back(tempCards[i]);
		}
		tempCards.clear();
	}
	for (int i = 0; i < 5; i++) {
		cout << cardLst[i] << endl;
	}

	return 0;
}