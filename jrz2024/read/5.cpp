#include <iostream>

using namespace std;

int main() {
  int YH[7][7];
  for (int i = 1; i <= 6; i++) {
    YH[i][1] = 1;
    YH[i][i] = 1;
  }
  for (int i = 3; i <= 6; i++) {
    for (int j = 2; j < i; j++) {
      YH[i][j] = YH[i - 1][j] + YH[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= i; j++) {
      cout << YH[i][j] << '\t';
    }
    cout << '\n';
  }
  return 0;
}