#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book_total, book;
    std::cin >> book_total;
    while (std::cin >> book)
    {
        book_total += book;
    }
    std::cout << book_total << std::endl;
    return 0;
}