#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

auto add_pre_and_suffix(string name, string const& pre, string const& su) {
    name.insert(0, pre);
    name.insert(name.size(), su);
    return name;
}

int main() {
    string name("wang");
    cout << add_pre_and_suffix(name, "Mr.", ", Jr.") << endl;
    return 0;
}