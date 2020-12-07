#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> test1 = {0, 1, 1, 2};
    vector<int> test2 = {0, 1, 1, 2, 3, 5, 8};

    for (int i = 0; i != test1.size(); ++i) {
        if (test1[i] != test2[i]) {
            cout << "It is not a prefix." << endl;
            break;
        }
    }
    cout << "It is a prefix." << endl;
    
    return 0;
}