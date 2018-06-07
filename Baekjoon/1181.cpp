#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool str_compare(const std::string &word1, const std::string &word2) {
	if (word1.size() == word2.size()) {
		return word1 < word2;
	}
	return word1.size() < word2.size();
}

int main() {
	int n;
	scanf("%d", &n);
	std::string word;
	std::vector<std::string> words;
	for (int i = 0; i < n; i++) {
		std::cin >> word;
		words.push_back(word);
	}

	std::vector<std::string>::iterator iter;
	std::vector<std::string>::iterator end_iter;

	sort(words.begin(), words.end(), str_compare);
	end_iter = std::unique(words.begin(), words.end());

	for (iter = words.begin(); iter != end_iter; iter++) {
		std::cout << *iter << std::endl;
	}
}