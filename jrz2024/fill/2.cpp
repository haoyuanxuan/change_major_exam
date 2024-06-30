#include <iostream>

using namespace std;

template <typename T>
void my_swap(/* (1) */) {
  T temp = *a;
  *a     = *b;
  *b     = temp;
}

template <typename T>
void recursion(T a[], int f, int n) {
  if (/* (2) */) {
    return;
  }
  int min = f;
  for (int i = f + 1; i <= n; i++) {
    if (/* (3) */) {
      min = i;
    }
  }
  my_swap(/* (4) */);
  /* (5) */
}

int main() {
  int a[10]   = {1, 4, 2, 7, 5, 4, 8, 4, 6, 3};
  double b[3] = {4.9, 25.6, 8.7};
  recursion(a, 0, 9);
  for (int i = 0; i < 10; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  recursion(b, 0, 2);
  for (int i = 0; i < 3; i++) {
    cout << b[i] << ' ';
  }
  return 0;
}