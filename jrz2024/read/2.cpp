#include <iostream>

using namespace std;

int x = 6;

int main() {
  int x = 5;
  {
    int x = 2;
    cout << "1:" << x++ << '\n';
    cout << "2:" << ::x << '\n';
    cout << "3:" << x << '\n';
    if (x / 4) {
      cout << "True!";
    } else {
      cout << "False!";
    }
  }
  cout << "4:" << x;
  return 0;
}