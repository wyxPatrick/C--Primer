// #include <iostream>

// using namespace std;

#include "Chapter6.h"

int fact(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}

int main() {
    int input;
    while (cin >> input) {
        cout << "The factorial result is: " << fact(input) << endl;
    }
    return 0;
}