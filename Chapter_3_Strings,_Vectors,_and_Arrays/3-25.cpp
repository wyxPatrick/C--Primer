#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<unsigned> scores(11, 0);
    unsigned grade;
    int i;
    while (cin >> grade) {
        if (grade <= 100) {
            auto beg = scores.begin();
            i = 0;
            while (i < grade/10){
                i++;
                beg++;
            }
            (*beg)++;
        }
    }
    for (auto s : scores)
        cout << s << endl;
    return 0;
}