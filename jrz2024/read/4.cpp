#include <iostream>

using namespace std;

void fun(int a[], int i, int j) {
  int t = a[i];
  a[i]  = a[j];
  a[j]  = t;
  if (i < j) {
    fun(a, i + 1, j - 1);
  }
}

int main() {
  int a[] = {1, 2, 3, 4, 5};
  fun(a, 0, 4);
  for (int i = 0; i < 5; i++) {
    cout << a[i];
  }
  return 0;
}