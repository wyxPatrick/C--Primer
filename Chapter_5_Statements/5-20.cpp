#include <iostream>
#include <string>

using namespace std;

int main() {
    string buf, last;
    while (cin >> buf && !buf.empty()) {
        if (buf == last) {
            cout << buf << " occurs twice in succession." << endl;
            return 0;
        }
        last = buf;
    }
    cout << "No word was repeated." << endl;
    return 0;
}