#include <iostream>

using namespace std;

template <typename T>
void my_swap(T* a, T* b) {
  T temp = *a;
  *a      = *b;
  *b      = temp;
}

template <typename T>
void recursion(T a[], int f, int n) {
  if (f > n) {
    return;
  }
  int min = f;
  for (int i = f + 1; i <= n; i++) {
    if (a[i] < a[min]) {
      min = i;
    }
  }
  my_swap(&a[f], &a[min]);
  recursion(a, f + 1, n);
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