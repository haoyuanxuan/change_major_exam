#include <iostream>

using namespace std;

int solve(int num[], int& s, int len) {
  static int sum = 0;
  for (int i = 0; i < len; i++) {
    sum += num[i];
    s   += num[i];
  }
  return sum;
}

int main() {
  int A[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  int B[4]    = {0};
  int sum;
  for (int i = 0; i < 4; i++) {
    sum = solve(A[i], B[i], 4);
    cout << B[i] << endl;
  }
  cout << sum << endl;
}
