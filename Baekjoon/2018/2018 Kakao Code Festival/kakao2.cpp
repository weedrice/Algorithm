#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	int n, k;
	cin >> n >> k;

	//k���� ���� ���� ����
	double **sum = new double*[n + 1];
	//k���� ����� ���� ����
	double **average = new double*[n+1]();
	//ǥ������
	double **stde = new double*[n + 1]();
	//�� ������ ��ȣ��
	int *dolls = new int[n+1]();

	for (int i = 1; i <= n; i++) {
		sum[i] = new double[n + 1]();
		average[i] = new double[n + 1]();
		stde[i] = new double[n + 1]();

		//���� �Է¹ޱ�
		//scanf("%d", &dolls[i]);
		dolls[i] = rand() % 1000000;
	}

	double min = 123456789;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (i == j) {
				sum[i][j] = dolls[i];
				average[i][j] = sum[i][j];
				stde[i][j] = 0;
			}
			else {
				int gap = j - i + 1;
				sum[i][j] = dolls[j] + sum[i][j - 1];
				average[i][j] = sum[i][j] / gap;
				for (int k = i; k <= j; k++)
					stde[i][j] += pow(dolls[k] - average[i][j], 2);
				stde[i][j] /= gap;
				stde[i][j] = sqrt(stde[i][j]);
				if (gap >= k && min > stde[i][j]) {
					min = stde[i][j];
				}
				
			}
		}
	}

	printf("%.7lf\n", min);
}