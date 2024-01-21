#include <cstdlib>
#include <iostream>

using namespace std;

void hist(/* (1) */) {
  int n;
  int hist[256] = /* (2) */;
  while (*src != /* (3) */) {
    hist[/* (4) */]++;
  }
  for (int i = 0; i < 256; i++) {
    if (hist[i] != 0) {
      cout << /* (5) */ << endl;
    }
  }
}

auto main() -> int {
  char const* src = "aaabbc111223ABBCCC";
  hist(src);
  return 0;
}
