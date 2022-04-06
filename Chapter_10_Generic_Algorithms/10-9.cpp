#include <iostream>
#include <algorithm>
#include <vector>

void elimDups(std::vector<std::string> &words) {
    std::cout << "Reading the input: ";
    for (int i = 0; i < words.size(); ++i) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    std::cout << "After unique: ";
    for (int i = 0; i < words.size(); ++i) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
    words.erase(end_unique, words.end());
    std::cout << "After erase: ";
    for (int i = 0; i < words.size(); ++i) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string word;
    std::vector<std::string> words;
    while(std::cin >> word) {
        words.push_back(word);
    }
    elimDups(words);
    return 0;
}