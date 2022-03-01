#include <iostream>
#include <forward_list>

auto remove_odds(std::forward_list<int>& flist) {
    auto is_odd = [] (int i) { return i & 0x1; };
    flist.remove_if(is_odd);
}

int main() {
    std::forward_list<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    remove_odds(data);
    for (auto i : data)
        std::cout << i << " ";
    return 0;
}