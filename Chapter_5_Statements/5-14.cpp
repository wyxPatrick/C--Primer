#include <iostream>
#include <string>

using namespace std;

int main() {
    string word, duplicated_word, max_duplicated_word;
    unsigned cnt = 0, max_cnt = 0;
    while(cin >> word) {
        if (word == duplicated_word) {
            ++cnt;
        }
        else {
            if (cnt > max_cnt) {
                max_duplicated_word = duplicated_word;
                max_cnt = cnt;
            }
            duplicated_word = word;
            cnt = 1;
        }
    }
    if (cnt > max_cnt) {
        max_duplicated_word = duplicated_word;
        max_cnt = cnt;
    }
    if (max_cnt > 1) {
        cout << "The maximum number of duplicates " << max_duplicated_word << " is " << max_cnt << endl;
    }
    else {
        cout << "No word was repeated." << endl;
    }
    return 0;
}