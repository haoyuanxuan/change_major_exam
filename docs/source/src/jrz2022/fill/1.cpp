#include <iostream>

using namespace std;

void find(int* a, int n, int i, int& pk) {
  if (i < /* (1) */) {
    if (a[i] < /* (2) */) {
      pk = i;
    }
    find(a, n, /* (3) */, pk);
  }
}

auto main() -> int {
  int a[] = {4, 2, 6, 1, 7, 3};
  int n   = 0;
  find(a, /* (4) */, 0, n);
  cout << /* (5) */ << endl;
}