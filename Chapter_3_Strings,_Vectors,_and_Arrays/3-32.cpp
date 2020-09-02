#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[10] = {};
    for (auto i : a)
        b[i] = i;
    for (auto j : b)
        cout << j << " ";
    cout << endl;

    vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> d(c);
    for (auto k : d)
        cout << k << " ";
    cout << endl;
    return 0;
}