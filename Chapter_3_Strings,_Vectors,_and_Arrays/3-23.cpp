#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> a{1,2,3,4,5,6,7,8,9,10};
    for (auto it = a.begin(); it != a.end(); it++) {
        *it = *it * 2;
        cout << *it << endl;
    }
    return 0;
}