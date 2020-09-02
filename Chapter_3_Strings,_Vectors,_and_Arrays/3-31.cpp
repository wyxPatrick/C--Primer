#include <iostream>

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : a)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}