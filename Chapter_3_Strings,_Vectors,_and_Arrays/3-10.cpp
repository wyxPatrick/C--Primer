#include <cctype>
#include <iostream>

using std::cout; using std::endl; using std::string;

int main() {
    string str("some, string!");
    for (auto &c : str) {
        if(!ispunct(c)) {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}