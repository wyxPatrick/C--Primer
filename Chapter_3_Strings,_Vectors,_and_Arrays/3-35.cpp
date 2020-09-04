#include <iostream>
#include <iterator>

int main() {
    int a[] = {1,2,3};
    int *beg = std::begin(a);
    int *last = std::end(a);
    while (beg != last) {
        *beg = 0;
        ++beg;
    }
    int *b = a, *e = a + 3;
    while (b < e) {
        std::cout << *b << std::endl;
        ++b;
    }
    return 0;
}