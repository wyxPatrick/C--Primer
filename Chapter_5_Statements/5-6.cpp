#include <iostream>
#include <vector>

using namespace std;

int main() {
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade = 98;
    string lettergrade;
    lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
    cout << lettergrade << endl;
    return 0;
}