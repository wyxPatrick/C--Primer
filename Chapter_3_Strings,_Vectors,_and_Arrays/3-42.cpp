#include <vector>
#include <iostream>

using namespace std;

int main () {
    vector<int> vec_int = {0, 1, 2, 3, 4, 5};
    int arr_int[6];
    int i = 0;
    for (int num : vec_int) {
        arr_int[i] = num;
        i++;
    }
    for (int a : arr_int) {
        cout << a << endl;
    }
    return 0;
}