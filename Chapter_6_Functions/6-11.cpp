#include <iostream>

using namespace std;

void reset(int &i) {
    i = 0;
}

int main() {
    int num;
    cout << "Let's try a number to reset: " << endl;
    cin >> num;
    reset(num);
    cout << "After reset: " << num << endl;
    return 0;
}