#include <iostream>

using namespace std;

bool HasCapitalLetter(const string &s) {
    for (auto c : s) {
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
    }
    return false;
}

string ConvertToLowercase(string& s) {
    for (auto& c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = tolower(c);
        }
    }
    return s;
}

int main() {
    string s, s_lower;
    cout << "Please enter a string: " << endl;
    cin >> s;
    if (HasCapitalLetter(s)) {
        cout << "There is a capital letter in the string." << endl;
        s_lower = ConvertToLowercase(s);
        cout << "After conversion: " << s_lower << endl;
    }
    else {
        cout << "There is no capital letter in the string." << endl;
    }
    return 0;
}