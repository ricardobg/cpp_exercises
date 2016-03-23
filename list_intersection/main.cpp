#include <iostream>
#include <sstream>
#include <list>
#include <functional>

#include "list_intersection.hpp"

template <class List, class E> List read_list(
    std::istream& stream,
    std::function<void(List&, const E&)> append_func) {
    List l;
    E el;
    while (stream >> el) {
        append_func(l, el);
    }
    return l;
}

using Element = int;
using List = std::list<Element>;

int main() {
    List l1,l2;
    {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream line1(line);
        l1 = read_list<List, Element>(line1, [](List& l, const Element& el) { l.push_back(el); });
        std::getline(std::cin, line);
        std::istringstream line2(line);
        l2 = read_list<List, Element>(line2, [](List& l, const Element& el) { l.push_back(el); });
    }

    auto ret = find_intersection(l1, l2);
    std::cout << ret.first << std::endl;
    std::cout << ret.second << std::endl;

    return 0;
}
