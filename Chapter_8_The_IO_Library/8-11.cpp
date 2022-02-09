#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::vector;
using std::string;
using std::cin;
using std::istringstream;
using std::getline;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(cin, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto& e : people) {
        std::cout << e.name << ": ";
        for (const auto& p : e.phones)
            std::cout << p << " ";
        std::cout << std::endl;
    }

    return 0;
}