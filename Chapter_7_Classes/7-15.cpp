#include <iostream>
#include <string>

using namespace std;

struct Person;
istream &read(istream &is, Person &individual);

struct Person {
    Person() : name(""), address("") { }
    Person(std::istream &is) {read(is, *this);}
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