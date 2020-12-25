#include <iostream>

using namespace std;

int CompareValues(int plain_value, int* pointer_value) {
    if (plain_value > *pointer_value) {
        return plain_value;
    }
    else {
        return *pointer_value;
    }
}

int main() {
    int a = 10, b = 20;
    int result = CompareValues(a, &b);
    cout << "The larger value is: " << result << endl;
    return 0;
}