#include <iostream>
#include <cctype>
#include <string>

int main() {
	std::string sentence;
	std::cin >> sentence;
	int alphabet[26] = { 0 };

	for (int i = 0; i < sentence.length(); i++) {
		if (std::isupper(sentence[i])) {
			alphabet[(int)sentence[i] - 65]++;
		}
		else {
			alphabet[(int)sentence[i] - 97]++;
		}
	}

	int highestval = 0;
	int highestnum = 0;
	int secondhighest = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] >= highestval) {
			secondhighest = highestval;
			highestval = alphabet[i];
			highestnum = i;
		}
	}

	if (secondhighest == highestval)
		printf("?");
	else {
		char fin = highestnum + 'A';
		printf("%c", fin);
	}
}