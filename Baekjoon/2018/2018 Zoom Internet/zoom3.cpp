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
	//두 단어가 같을경우
	if (S == T)
		return "NOTHING";

	int sLen = S.length();
	int tLen = T.length();
	//단어 길이가 같을 경우 SWAP이 가능함.
	if (sLen == tLen) {
		//다른 문자의 위치를 찾는다.
		for (int i = 0; i < sLen; i++) {
			if (S[i] != T[i]) {
				int location = T.find(S[i]);
				//바꿀 문자를 찾지 못했을 경우 IMPOSSIBLE
				if (location == -1) {
					return "IMPOSSIBLE";
				}

				//두 위치를 SWAP한다.
				T[location] = T[i];
				T[i] = S[i];
				
				//SWAP 이후 문자열이 같다면 SWAP T[location] T[i]를 리턴
				if (S == T) {
					string returnValue = "SWAP ";
					returnValue += T[i];
					returnValue.append(" ");
					returnValue += T[location];
					return returnValue;
				}
				//다르다면 IMPOSSIBLE
				else {
					return "IMPOSSIBLE";
				}
				
			}
		}
		
	}
	//길이가 2이상 차이날경우 IMPOSSIBLE
	else if (gap(sLen, tLen) > 1)
		return "IMPOSSIBLE";
	//길이가 1의 차이를 가질 경우 INSERT나 REMOVE 두가지가 가능함.
	else {
		//문자열이 달라지는 부분을 찾는다
		for (int i = 0; i < min(tLen, sLen); i++) {
			//다른 부분을 찾았을 경우
			if (S[i] != T[i]) {
				//S[i]와 T[i+1]번째가 같을경우 insert하는 상황
				if (S[i] == T[i + 1]) {
					char temp = T[i];
					T.erase(i, 1);

					//insert 이후 값이 같을경우 INSERT
					if (S == T) {
						string returnValue = "INSERT ";
						returnValue += temp;
						return returnValue;
					}
					//insert 이후에도 값이 다를경우 IMPOSSIBLE
					else
						return "IMPOSSIBLE";
				}
				//S[i+1]과 T[i]가 같을경우 REMOVE하는 상황
				if (S[i+1] == T[i]) {
					char temp = S[i];
					S.erase(i, 1);
					//remove이후 값이 같을경우 REMOVE
					if (S == T) {
						string returnValue = "REMOVE ";
						returnValue += temp;
						return returnValue;
					}
					//remove이후에도 값이 다를경우 IMPOSSIBLE
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