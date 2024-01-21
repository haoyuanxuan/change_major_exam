#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  for (int i = 0; i < 13; i++) {
    if (i % 5 == 0) {
      continue;
    }
    std::cout << std::setw(2) << i;
    if (i % 2 == 0) {
      std::cout << '\n';
    }
    if (i % 10 == 0) {
      break;
    }
  }
}