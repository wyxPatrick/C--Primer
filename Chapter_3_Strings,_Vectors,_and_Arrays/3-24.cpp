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
        auto beg = a.begin(), end = a.end() - 1;
        if (beg == end) {
            cout << *beg << endl;
        }
        while (beg != end) {
            cout << *beg + *(beg+1) << endl;
            beg++;
        }
        beg = a.begin();
        end = a.end()-1;
        while (beg < end) {
            cout << *beg + *end << endl;
            beg++;
            end--;
        }
        if (beg == end) {
            cout << *beg << endl;
        }
    }
    return 0;
}