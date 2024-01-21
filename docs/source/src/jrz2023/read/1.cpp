#include <iostream>
using namespace std;

int v = 5;

int main() {
  int v = 65;
  for (int v = 65; v <= 66; v++) {
    switch (v) {
      case ('A'):
        cout << 'A' << endl;
        break;
      case ('B'):
        cout << 'B' << endl;
      default:
        cout << ::v << endl;
    }
  }
  cout << v << endl;
}