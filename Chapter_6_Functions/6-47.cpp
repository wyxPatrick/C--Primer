#include <iostream>
#include <vector>

using namespace std;

// #define NDEBUG

void PrintVector(vector<int>::iterator beg, vector<int>::iterator end) {
#ifndef NDEBUG
    cout << "In function: " << __func__ << ", " << "vector size: " << end - beg << endl;
#endif
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