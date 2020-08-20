#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    string temp;
    vector<string> v;
    while (cin >> temp) {
        v.push_back(temp);
    }
    return 0;
}