#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n-- > 0) {
		string line;
		getline(cin, line);  // drop a newline traling n
		stringstream ss(line);
		string method, url, body;
		getline(ss, method, ' ');
		getline(ss, url, ' ');
		getline(ss, body);
		// @todo Write your code here.
	}

	return 0;
}
