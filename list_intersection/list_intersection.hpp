#include <iterator>
#include <iostream>

template<class List>
std::pair<int,int> find_intersection(List l1, List l2) {
    auto ret = std::make_pair(0,0);

    int size1 = l1.size();
    int size2 = l2.size();

    auto it1 = l1.begin();
    auto it2 = l2.begin();


    if (size1 != size2) {
        ret.first += size1 > size2 ? size1-size2 : 0;
        ret.second += size1 < size2 ? size2-size1 : 0;
        std::advance(size1 > size2 ? it1 : it2, size1 > size2 ? ret.first : ret.second);
    }
    auto res = it1;
    int buff = 0;
    while (it1 != l1.end()) {
        if (*it1 != *it2) {
            res = l1.end();
            ret.first += buff + 1;
            ret.second += buff + 1;
            buff = 0;
        }
        else
            buff++;

        it1++;
        it2++;
    }

    return ret;
}
