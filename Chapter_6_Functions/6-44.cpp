#include <iostream>
#include <string>

using namespace std;

inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main() {
    string a = "abc";
    string b = "abcde";

    if (isShorter(a, b)) {
        cout << "String a is shorter." << endl;
    }

    return 0;
}