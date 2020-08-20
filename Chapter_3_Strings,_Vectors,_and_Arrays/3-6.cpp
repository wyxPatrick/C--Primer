#include <cctype>
#include <iostream>

using std::cout; using std::endl; using std::string;

int main() {
    string str("some string");
    for (auto &c : str) {
        c = 'X';
    }
    cout << str << endl;
    return 0;
}