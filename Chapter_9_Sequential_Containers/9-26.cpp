#include <iostream>
#include <vector>
#include <list>

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    std::vector<int> vec(ia, std::end(ia));
    std::list<int> lst(vec.begin(), vec.end());

    for (auto it = lst.begin(); it != lst.end(); )
        if (*it & 0x1)
            it = lst.erase(it);
        else
            ++it;

    for (auto it = vec.begin(); it != vec.end(); )
        if (!(*it & 0x1))
            it = vec.erase(it);
        else
            ++it;

    std::cout << "list: ";
    for (auto i : lst)
        std::cout << i << " ";
    std::cout << "\nvector: ";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}