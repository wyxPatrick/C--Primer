#include <string>
#include <forward_list>

void find_and_insert(std::forward_list<std::string>& list, std::string const& to_find, std::string const& to_add) {
    auto prev = list.before_begin();
    for (auto curr = list.begin(); curr != list.end(); prev = curr++) {
        if (*curr == to_find) {
            list.insert_after(curr, to_add);
            return;
        }
    }
    list.insert_after(prev, to_add);
}