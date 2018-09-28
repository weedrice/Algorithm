#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int gap(int a, int b) {
	return a > b ? a - b : b - a;
}

int min(int a, int b) {
	return a > b ? b : a;
}

string solution(string &S, string &T) {
	// write your code in C++14 (g++ 6.2.0)
	//�� �ܾ �������
	if (S == T)
		return "NOTHING";

	int sLen = S.length();
	int tLen = T.length();
	//�ܾ� ���̰� ���� ��� SWAP�� ������.
	if (sLen == tLen) {
		//�ٸ� ������ ��ġ�� ã�´�.
		for (int i = 0; i < sLen; i++) {
			if (S[i] != T[i]) {
				int location = T.find(S[i]);
				//�ٲ� ���ڸ� ã�� ������ ��� IMPOSSIBLE
				if (location == -1) {
					return "IMPOSSIBLE";
				}

				//�� ��ġ�� SWAP�Ѵ�.
				T[location] = T[i];
				T[i] = S[i];
				
				//SWAP ���� ���ڿ��� ���ٸ� SWAP T[location] T[i]�� ����
				if (S == T) {
					string returnValue = "SWAP ";
					returnValue += T[i];
					returnValue.append(" ");
					returnValue += T[location];
					return returnValue;
				}
				//�ٸ��ٸ� IMPOSSIBLE
				else {
					return "IMPOSSIBLE";
				}
				
			}
		}
		
	}
	//���̰� 2�̻� ���̳���� IMPOSSIBLE
	else if (gap(sLen, tLen) > 1)
		return "IMPOSSIBLE";
	//���̰� 1�� ���̸� ���� ��� INSERT�� REMOVE �ΰ����� ������.
	else {
		//���ڿ��� �޶����� �κ��� ã�´�
		for (int i = 0; i < min(tLen, sLen); i++) {
			//�ٸ� �κ��� ã���� ���
			if (S[i] != T[i]) {
				//S[i]�� T[i+1]��°�� ������� insert�ϴ� ��Ȳ
				if (S[i] == T[i + 1]) {
					char temp = T[i];
					T.erase(i, 1);

					//insert ���� ���� ������� INSERT
					if (S == T) {
						string returnValue = "INSERT ";
						returnValue += temp;
						return returnValue;
					}
					//insert ���Ŀ��� ���� �ٸ���� IMPOSSIBLE
					else
						return "IMPOSSIBLE";
				}
				//S[i+1]�� T[i]�� ������� REMOVE�ϴ� ��Ȳ
				if (S[i+1] == T[i]) {
					char temp = S[i];
					S.erase(i, 1);
					//remove���� ���� ������� REMOVE
					if (S == T) {
						string returnValue = "REMOVE ";
						returnValue += temp;
						return returnValue;
					}
					//remove���Ŀ��� ���� �ٸ���� IMPOSSIBLE
					else
						return "IMPOSSIBLE";
				}
			}
		}
	}
}

int main() {
	string S = "o";
	string T = "odd";
	string answer = solution(S, T);
	cout << answer;
}