#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data total, current;
    double price = 0;
    if (cin >> total.bookNo >> total.units_sold >> price) {
        int cnt = 1;
        total.revenue = total.units_sold * price;
        while (cin >> current.bookNo >> current.units_sold >> price) {
            current.revenue = current.units_sold * price;
            if (total.bookNo == current.bookNo) {
                total.units_sold += current.units_sold;
                total.revenue += current.revenue;
                ++cnt;
            }
            else {
                cout << total.bookNo << " " << cnt << endl;
                total.bookNo = current.bookNo;
                total.units_sold = current.units_sold;
                cnt = 1;
            }
        }
        cout << total.bookNo << " " << cnt << endl;
    }
    else {
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }
    return 0;
}