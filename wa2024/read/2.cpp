#include <iostream>

using namespace std;

int fun1(int* arr, int j) {
  int n       = 0;
  n          += *(arr + j);
  *(arr + j)  = 0;
  return n;
}

int fun2(int arr[], int k) {
  int sum = 0;
  sum     = 2 * arr[k];
  return sum;
}

int main() {
  int a = 0;
  int b = 0;

  int Arr[10];
  for (int i = 0; i < 10; i++) {
    Arr[i] = i;
  }

  for (int j = 0; j < 10; j += 2) {
    a += fun1(Arr, j);
  }
  cout << "a = " << a << endl;

  for (int k = 1; k < 10; k += 2) {
    b += fun2(Arr, k);
  }
  cout << "b = " << b << endl;

  for (int i = 0; i < 10; i++) {
    cout << Arr[i] << " ";
  }
}