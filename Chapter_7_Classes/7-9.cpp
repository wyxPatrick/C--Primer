#include <iostream>
#include <string>

using namespace std;

struct Person {
    string GetName() const {return name;}
    string GetAddress() const {return address;}

    string name;
    string address;
};

istream &read(istream &is, Person &individual) {
    is >> individual.name >> individual.address;
    return is;
}

ostream &print(ostream &os, const Person &individual) {
    os << individual.name << " " << individual.address;
    return os;
}

int main() {
    return 0;
}