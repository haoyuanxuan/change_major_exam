#include <iostream>

using namespace std;

void fun(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      *(arr + n * i + j) = *(arr + n * j + i)
          = *(arr + n * i + j) * *(arr + n * j + i);
    }
  }
}

int main() {
  int Arr[4][4] = {};
  int count     = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      Arr[i][j] = count++;
    }
  }

  fun(&Arr[0][0], 4);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << Arr[i][j] << "\t";
    }
    cout << endl;
  }
}
