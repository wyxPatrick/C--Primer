#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main () {
    string a = "abcdefg";
    string b = "abcdefg";
    const char c[] = "abcdefg";
    const char d[] = "abcdefg";
    if (a == b) {
        cout << " a == b " << endl;
    }
    if (!strcmp(c, d)) {
        cout << " c == d " << endl;
    }
    return 0;
}