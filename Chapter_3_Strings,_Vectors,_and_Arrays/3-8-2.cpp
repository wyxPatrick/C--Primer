#include <cctype>
#include <iostream>

using std::cout; using std::endl; using std::string;

int main() {
    string str("some string");
    for (decltype(str.size()) i = 0; i < str.size(); i++)
        str[i] = 'X';
    cout << str << endl;
    return 0;
}