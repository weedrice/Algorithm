#include <iostream>

using namespace std;

int* predicts;

int main() {
	int days;
	cin >> days;

	predicts = new int[days];
	for (int i = 0; i < days; i++) {
		cin >> predicts[i];
	}

	int margin = 0;
	int tradeCount = 0;
	int maxStock = 0;

	for (int i = days - 1; i >= 0; i--) {
		if (predicts[i] > maxStock) {
			if(maxStock != 0)
				tradeCount++;
			maxStock = predicts[i];
		}
		else {
			int sell = maxStock - predicts[i];
			if (tradeCount == 0)
				tradeCount++;
			margin += sell;
		}
	}
	if (margin > 0)
		margin -= tradeCount;

	cout << margin;

	return 0;
}