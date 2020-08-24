#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> a;
    int num;
    while (cin >> num) {
        a.push_back(num);
    }
    if (!a.empty()) {
        for (unsigned i = 1; i < a.size(); i++) {
            cout << a[i-1] + a[i] << endl;
        }

        unsigned l = 0, r = a.size()-1;
        while (l < r) {
            cout << a[l] + a[r] << endl;
            l++;
            r--;
        }
        if (l == r) {
            cout << a[l] << endl;
        }
    }
    return 0;
}