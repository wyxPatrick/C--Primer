#include <iostream>

int main() {
    int a, b;
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> a >> b;
    if (a < b)
    {
        while (a <= b)
        {
            std::cout << a << std::endl;
            ++a;
        }
        return 0;
    }
    else
    {
        while (b <= a)
        {
            std::cout << b << std::endl;
            ++b;
        }
    }
    
}