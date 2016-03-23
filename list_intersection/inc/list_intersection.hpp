#ifndef LIST_INTERSECTION_HPP
#define LIST_INTERSECTION_HPP

#include <list>
#include <utility>

int get_size(const std::list<int>& list)
{
  int ret = 0;
  for (const auto& v : list) ret++;
  return ret;
}



std::pair<int,int> find_intersection(const std::list<int>& list_one, const std::list<int>& list_two)
{
  std::pair<int,int> offsets(get_size(list_one), get_size(list_two));
  auto it1 = list_one.begin();
  auto it2 = list_two.begin();
  int size = offsets.first;
  if (offsets.first > offsets.second) {
    //Advances first list in first-second times
    size = offsets.second;
    for (int i = 0; i < offsets.first - offsets.second; i++)
      it1++;
  }
  else if (offsets.second > offsets.first) {
    for (int i = 0; i < offsets.second - offsets.first; i++)
      it2++;
  }
  while (size-- > 0) {


    it1++;
    it2++;
  }
  return ret;
}

#endif
