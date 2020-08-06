#include <iostream>

int main() {
    int i = 42;
    int *p1 = 0;
    int *p2 = &i;

    p1 = p2;
    std::cout << "Value of pointer p1: " << p1 << std::endl;
    *p1 = 10;
    std::cout << "Vlue to which pointer p1 points: " << *p1 << std::endl;
    
    return 0;
}