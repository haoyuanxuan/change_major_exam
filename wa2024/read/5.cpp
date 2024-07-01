#include <iostream>

using namespace std;

int a[5][5];

int dmp(int x, int y) {
  if (x == 4) {
    return a[x][y];
  }

  int left  = dmp(x + 1, y);
  int right = dmp(x + 1, y + 1);
  cout << left << '-' << right << '\n';
  return a[x][y] + (left > right ? left : right);
}

int main() {
  for (int i = 1; i < 5; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> a[i][j];
    }
  }

  cout << dmp(1, 1) << '\n';
}