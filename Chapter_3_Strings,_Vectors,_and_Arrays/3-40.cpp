#include <iostream>
#include <cstring>

using namespace std;

int main () {
    char a[] = "abcdefg";
    char b[] = "abcdefg";
    char c[15];
    strcpy(c, strcat(a, b));
    for (auto ch : c) {
        cout << ch << endl;
    }

    return 0;
}