#include <iostream>

#include <string.h>

using namespace std;

class Date {
 public:
  // ...

 private:
  int year;
  int month;
  int day;
};

class Items {
 public:
  // ...

 private:
  char item_name[20];
  int number;
  double price;
};

class Customer {
  // ...
};

auto main() -> int {
  Date d1(2022, 6, 18);
  Customer c1("11000001", d1);
  c1.selectItem("cup", 2, 9.2);
  c1.selectItem("jacket", 1, 50);
  c1.selectItem("steak", 3, 10);
  c1.print();
  return 0;
}
