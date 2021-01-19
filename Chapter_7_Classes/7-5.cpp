#include <iostream>
#include <string>

using namespace std;

struct Person {
    string GetName() const {return name;}
    string GetAddress() const {return address;}

    string name;
    string address;
};

int main() {
    return 0;
}