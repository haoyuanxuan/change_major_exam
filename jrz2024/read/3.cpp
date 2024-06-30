#include <iostream>

using namespace std;

void fun(int& x, int y) {
  x = y % 9;
  y = x % 3;
  x++;
  cout << x << '\t' << y << endl;
}

int main() {
  int x = 1, y = 10;
  fun(y, x);
  cout << x << '\t' << y << endl;
  fun(x, x);
  cout << x << '\t' << y << endl;
}