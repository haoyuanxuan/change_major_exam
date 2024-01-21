#include <cstring>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void fill_impl(T (*array)[5], int order, int offset) {
  int i     = 0;
  int j     = 0;
  int count = 0;
  while (true) {
    for (; j < order && array[i][j] == 0; ++j) {
      array[i][j] = offset + count;
      ++count;
    }
    if (count == order * order) {
      break;
    }
    ++i;
    --j;

    for (; i < order && array[i][j] == 0; ++i) {
      array[i][j] = offset + count;
      ++count;
    }
    if (count == order * order) {
      break;
    }
    --i;
    --j;

    for (; j > -1 && array[i][j] == 0; --j) {
      array[i][j] = offset + count;
      ++count;
    }
    if (count == order * order) {
      break;
    }
    --i;
    ++j;

    for (; i > -1 && array[i][j] == 0; --i) {
      array[i][j] = offset + count;
      ++count;
    }
    if (count == order * order) {
      break;
    }
    ++i;
    ++j;
  }
}

void fill(int (*num)[5], char (*ch)[5], int m) {
  fill_impl(num, m, 1);
  fill_impl(ch, m, 'a');
}

template <typename T>
void print_impl(T (*array)[5], int order) {
  for (int i = 0; i < order; ++i) {
    for (int j = 0; j < order; ++j) {
      std::cout << array[i][j] << '\t';
    }
    std::cout << '\n';
  }
}

void print(int (*num)[5], char (*ch)[5], int m) {
  print_impl(num, m);
  print_impl(ch, m);
}

int main() {
  int m;
  cin >> m;
  int num[5][5] = {};
  char ch[5][5] = {};
  fill(num, ch, m);
  print(num, ch, m);
  return 0;
}