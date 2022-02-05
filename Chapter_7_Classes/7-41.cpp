#include <string>
#include <iostream>

class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    Sales_data() : Sales_data("", 0, 0.0) {
        std::cout << "Sales_data() is called." << std::endl;
    }
    Sales_data(const std::string& no) : Sales_data(no, 0, 0.0) {
        std::cout << "Sales_data(const std::string& no) is called." << std::endl;
    }
    Sales_data(const std::string& no, unsigned us, double price) : bookNo(no), units_sold(us), revenue(price * us) {
        std::cout << "Sales_data(const std::string& no, unsigned us, double price) is called." << std::endl;
    }
    Sales_data(std::istream& is) : Sales_data() {
        std::cout << "Sales_data(std::istream& is) is called." << std::endl;
        read(is, *this);
    }
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

inline
double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

int main() {
    Sales_data d1;
    Sales_data d2("0-201-78345-X");
    Sales_data d3("0-201-78345-X", 5, 2.5);
    Sales_data d4(std::cin);

    print(std::cout, d1) << std::endl;
    print(std::cout, d2) << std::endl;
    print(std::cout, d3) << std::endl;
    print(std::cout, d4) << std::endl;

    Sales_data total(std::cin);
    if (std::cin) {
        Sales_data trans(std::cin);
        while (std::cin) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
            read(std::cin, trans);
        }
        print(std::cout, total) << std::endl;
    }
    else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    return 0;
}