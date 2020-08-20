#include <cctype>
#include <iostream>

using std::cout; using std::endl; using std::string;

int main() {
    string str("some string");
    decltype(str.size()) i = 0;
    while (i < str.size())
        str[i++] = 'X';
    cout << str << endl;
    return 0;
}