#include <iostream>

using namespace std;

void ErrorMsg(initializer_list<int> li) {
    int sum = 0;
    for (auto beg = li.begin(); beg != li.end(); ++beg) {
        sum += *beg;
    }
    cout << "The sum is: " << sum << endl;
}

int main() {
    initializer_list<int> lst = {1, 2, 3, 4, 5};
    ErrorMsg(lst);
    return 0;
}