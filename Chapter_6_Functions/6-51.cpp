#include <iostream>

using namespace std;

void f() {
    cout << "Calling f()." << endl;
}

void f(int a) {
    cout << "Calling f(int)." << endl;
}

void f(int a, int b) {
    cout << "Calling f(int, int)." << endl;
}

void f(double a, double b = 3.14) {
    cout << "Calling f(double, double = 3.14)." << endl;
}

int main() {
    // f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}