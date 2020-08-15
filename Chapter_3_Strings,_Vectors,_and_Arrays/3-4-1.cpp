#include <iostream>
#include <string>

using std::string; using std::cin; using std::cout; using std::endl;

int main() {
    string line_a, line_b;
    getline(cin, line_a);
    getline(cin, line_b);
    if (line_a == line_b)
        cout << "Tow strings are equal." << endl;
    else {
        if (line_a < line_b)
            cout << line_b << " is larger." << endl;
        else
            cout << line_a << " is larger." << endl;
    }
    return 0;
}