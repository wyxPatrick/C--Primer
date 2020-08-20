#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int temp;
    vector<int> v;
    while (cin >> temp) {
        v.push_back(temp);
    }
    return 0;
}