#include <iostream>
#include <string>
#include <locale>

using namespace std;

wstring texts[4] = { L"가가나나다다", L"라라마마바바", L"사사아아자자", L"차차카카타타" };

void printRotate(int degree) {
	switch(degree) {
		case 0:
			for (int i = 0; i < 4; i++) {
				wcout << texts[i];
				cout << endl;
			}
			break;
		case 90:
			for (int i = 0; i < texts[0].length(); i++) {
				for (int j = 3; j >= 0; j--) {
					wcout << texts[j][i];
				}
				cout << endl;
			}
			break;
		case 180:
			for (int i = 3; i >= 0; i--) {
				for (int j = texts[0].length()-1; j >= 0; j--) {
					wcout << texts[i][j];
				}
				wcout << endl;
			}
			break;
		case 270:
			for (int i = texts[0].length() - 1; i >= 0 ; i--) {
				for (int j = 0; j < 4; j++) {
					wcout << texts[j][i];
				}
				cout << endl;
			}
			break;
	}
}

void setRotate(int degree, bool clockWise) {
	degree %= 360;
	if (clockWise) {
		printRotate(degree);
	}
	else {
		degree *= -1;
		if(degree != 0)
			degree += 360;
		printRotate(degree);
	}
}

int main() {
	setlocale(LC_ALL, "korean");

	string input;
	cout << "시계방향: cw" << endl;
	cout << "반시계방향: ccw" << endl;
	cout << "회전? ";
	cin >> input;

	if (input.substr(0, 2) == "cw") {
		int degree = stoi(input.substr(2));
		setRotate(degree, true);
	}
	else {
		int degree = stoi(input.substr(3));
		setRotate(degree, false);
	}

	return 0;
}