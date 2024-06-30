#include <iostream>

using namespace std;

int mys(int a[], int n) {
  static int x  = 0;
  int b         = a[n] / 3;
  x            += b;
  return x % 4;
}

int main() {
  int a[] = {0, 1, 4, 5};
  for (int i = 0; i < 4; i++) {
    cout << mys(a, i) << endl;
  }
  return 0;
}