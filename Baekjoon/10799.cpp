#include <iostream>
#include <stack>

using namespace std;

int main() {
	int cnt = 0;
	stack<char> st;
	char input = getchar();
	st.push(input);
	while (1) {
		char before = input;
		input = getchar();
		if (input == '\n')
			break;
		if (input == '(') {
			st.push(input);
		}
		else {
			st.pop();
			if (before == '(') {
				cnt += st.size();
			}
			else {
				cnt += 1;
			}
		}
	}

	printf("%d\n", cnt);
}