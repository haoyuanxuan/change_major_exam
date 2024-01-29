#include "set.hpp"

#include <iostream>
#include <string>

auto main() -> int {
  std::string s1[] = {"John", "Bat-man", "Doctor", "John"};
  std::string s2[] = {"Doctor", "Smith", "Komeji", "Smith"};
  std::string s3[] = {"Komeji", "Satori", "Momo", "Satori"};

  Set set1(s1, 4);
  Set set2(s2, 4);
  Set set3;

  std::cout << set1 << '\n';
  std::cout << set2 << '\n';
  std::cout << set3 << '\n';

  set3  = set2;
  set1 += set2;
  set1  = set1 + set3;

  std::cout << set1 << '\n';
  std::cout << set2 << '\n';
  std::cout << set3 << '\n';
}