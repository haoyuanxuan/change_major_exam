#include <iostream>

using namespace std;

int func(int m, int& n) {
  int b         = 0;
  static int c  = 4;
  b            += 2;
  c            += 1;
  n            += m + b + c;
  return n;
}

int main() {
  int a  = 4;
  int y  = 2;
  int* p = &y;
  std::cout << func(a, *p) << '\n';
  std::cout << func(a, *p) << '\n';
  std::cout << func(a, *p) << '\n';
  std::cout << func(a, *p) << '\n';
  cout << y;
  return 0;
}