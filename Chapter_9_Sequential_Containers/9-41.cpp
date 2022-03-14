#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int main() {
    vector<char> v{'p', 'a', 't', 'r', 'i', 'c', 'k'};
    string str(v.cbegin(), v.cend());
    cout << str << endl;

    return 0;
}