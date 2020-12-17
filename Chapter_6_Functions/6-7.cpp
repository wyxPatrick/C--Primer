#include <iostream>

using namespace std;

int foo() {
    static int count = 0;
    return count++;
}

int main() {
    for (int i = 0; i != 10; ++i) {
        cout << foo() << endl;
    }
    return 0;
}