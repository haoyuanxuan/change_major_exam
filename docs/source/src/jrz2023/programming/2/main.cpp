#include "my_list.hpp"

#include <iostream>
#include <string>

auto main() -> int {
  std::string s1[] = {"John", "Bat-man", "Doctor", "John"};
  std::string s2[] = {"Doctor", "Smith", "Komeji", "Smith"};
  std::string s3[] = {"Komeji", "Satori", "Momo", "Satori"};

  MyList list1(s1, 4);
  MyList list2(s2, 4);
  MyList list3;

  std::cout << list1 << '\n';
  std::cout << list2 << '\n';
  std::cout << list3 << '\n';

  list3  = list2;
  list1 += list2;
  list1  = list1 + list3;

  std::cout << list1 << '\n';
  std::cout << list2 << '\n';
  std::cout << list3 << '\n';
}