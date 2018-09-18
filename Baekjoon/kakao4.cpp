#include <iostream>

using namespace std;

double* checkPointX;
double* checkPointY;

bool isMove(double a, double b, double x) {

}

int main() {
	int n, q;
	cin >> n >> q;
	checkPointX = new double[n];
	checkPointY = new double[n];

	for (int i = 0; i < n; i++) {
		cin >> checkPointX[i];
		cin >> checkPointY[i];
	}

	for (int i = 0; i < q; i++) {
		double a, b, x;
		cin >> a >> b >> x;

		if (isMove)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}