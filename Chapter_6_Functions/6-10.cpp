#include <iostream>

using namespace std;

void SwapValues(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a, b;
    cout << "Please enter two integers to swap: " << endl;
    cin >> a >> b;
    SwapValues(&a, &b);
    cout << "This is the result after the swap: " << a << " "<< b << endl;
    return 0;
}