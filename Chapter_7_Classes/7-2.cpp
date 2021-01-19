#include <iostream>
#include <string>

struct Sales_data {
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main() {
    Sales_data total, current;
    double price = 0;
    if (std::cin >> total.bookNo >> total.units_sold >> price) {
        int cnt = 1;
        total.revenue = total.units_sold * price;
        while (std::cin >> current.bookNo >> current.units_sold >> price) {
            current.revenue = current.units_sold * price;
            if (total.bookNo == current.bookNo) {
                total.units_sold += current.units_sold;
                total.revenue += current.revenue;
                ++cnt;
            }
            else {
                std::cout << total.bookNo << " " << cnt << std::endl;
                total.bookNo = current.bookNo;
                total.units_sold = current.units_sold;
                cnt = 1;
            }
        }
        std::cout << total.bookNo << " " << cnt << std::endl;
    }
    else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
    return 0;
}