#include <vector>
#include <iostream>

using namespace std;

int main () {
    int int_arr[] = {0, 1, 2, 3, 4, 5};
    vector<int> ivec(begin(int_arr), end(int_arr));
    for (int i : ivec) {
        cout << i << endl;
    }
    return 0;
}