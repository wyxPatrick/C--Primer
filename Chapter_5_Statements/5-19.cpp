#include <iostream>

using namespace std;

int main() {
    string rsp;
    do {
        cout << "Please enter two strings: ";
        string s1, s2;
        cin >> s1 >> s2;
        cout << (s1 <= s2 ? s1 : s2) << " is less than the other. " << "\n\n"
             << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
    return 0;
}