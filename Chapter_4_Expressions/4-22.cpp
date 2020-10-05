#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {100, 80, 70, 50};
    for (auto &grade : v) {
        string finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade < 60) ? "fail" : "low pass";
        cout << finalgrade << endl;

        string final;
        if (grade > 90) {
            final = "high pass";
        }
        else if (grade < 90 && grade > 75) {
            final = "pass";
        }
        else if (grade < 60) {
            final = "fail";
        }
        else {
            final = "low pass";
        }
        cout << final << endl;
    }
    return 0;
}