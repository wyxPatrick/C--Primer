#include <iostream>

using namespace std;

int absoluteValue(int val) {
    if (val < 0) {
        val = val * (-1);
    }
    return val;
}

int main() {
    int input;
    while (cin >> input) {
        cout << "The absolute value of " << input << " is: " << absoluteValue(input) << endl;
    }
    return 0;
}