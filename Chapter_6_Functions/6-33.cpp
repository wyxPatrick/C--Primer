#include <iostream>
#include <vector>

using namespace std;

void PrintVector(vector<int>::iterator beg, vector<int>::iterator end) {
    if (beg != end) {
        cout << *beg << endl;
        PrintVector(++beg, end);
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    PrintVector(v.begin(), v.end());
    return 0;
}