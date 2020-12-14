#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        try {
            if (b == 0) {
                throw runtime_error("The second number must be non-zero.");
            }
            cout << "The result of dividing the first number by the second is: " << a / b << endl;
        }
        catch (runtime_error err) {
            cout << err.what() << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n') {
                break;
            }
        }
    }

    return 0;
}