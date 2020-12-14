#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (b == 0) {
        throw runtime_error("The second number must be non-zero.");
    }
    cout << "The result of dividing the first number by the second is: " << a / b << endl;
    return 0;
}