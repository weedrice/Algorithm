#include <iostream>
#include <string>

int main() {
	std::string sentence;
	std::getline(std::cin, sentence);
	int blank = 1;

	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] == ' ')
			blank++;
	}

	if (sentence[0] == ' ')
		blank--;

	if (sentence[sentence.size() - 1] == ' ')
		blank--;

	std::cout << blank << std::endl;
}