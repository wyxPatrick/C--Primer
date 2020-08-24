#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    vector<string> words;
    string word;
    while (cin >> word) {
        for (auto &c : word) {
            c = toupper(c);
        }
        words.push_back(word);
    }
    for (decltype(words.size()) i = 0; i < words.size(); i++) {
        if (i % 8 == 0) {
            cout << endl;
        }
        cout << words[i] << " ";
    }
    cout << endl;
    return 0;
}