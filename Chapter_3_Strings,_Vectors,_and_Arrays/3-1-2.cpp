#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    if (a < b) {
        while (a <= b) {
            cout << a << endl;
            ++a;
        }
        return 0;
    }
    else {
        while (b <= a) {
            cout << b << endl;
            ++b;
        }
    }
}