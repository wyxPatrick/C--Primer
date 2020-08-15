#include <iostream>
#include <string>

using std::string; using std::cin; using std::cout; using std::endl;

int main() {
    string word, answer;
    while (cin >> word)
        answer += word + " ";
    cout << answer << endl;
    return 0;
}