#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    int a[] = {1,2,3};
    int b[] = {1,2,3};
    int *a_beg = std::begin(a);
    int *b_beg = std::begin(b);
    int *a_last = std::end(a);
    int *b_last = std::end(b);
    while (a_beg != a_last && b_beg != b_last) {
        if (*a_beg != *b_beg) {
            cout << "Two arrays are not equal." << endl;
            break;
        }
        ++a_beg;
        ++b_beg;
    }
    cout << "Two arrays are equal." << endl;

    vector<int> va{1,2,3};
    vector<int> vb{1,2,3};
    vector<int>::iterator ita, itb;
    ita = va.begin();
    itb = vb.begin();
    while (ita != va.cend() && itb != vb.cend()) {
        if (*ita != *itb) {
            cout << "Two vectors are not equal." << endl;
            break;
        }
        ++ita;
        ++itb;
    }
    cout << "Two vectors are equal." << endl;
    return 0;
}