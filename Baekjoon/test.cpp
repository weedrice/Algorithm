#include <iostream>
#include <string>

using namespace std;

string temp[4] = { "��������", "���ٳ���", "�ٴٴٴ�", "�����" };

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << temp[i][j];
		}
		cout << endl;
	}

	return 0;
}