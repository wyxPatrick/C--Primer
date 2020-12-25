#include <iostream>

using namespace std;

void SwapPointers(int *&a, int *&b) {
    int* tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 10, b = 20;
    int *p = &a, *q = &b;
    SwapPointers(p, q);
    cout << "After swap: " << *p << " " << *q << endl;
    return 0;
}