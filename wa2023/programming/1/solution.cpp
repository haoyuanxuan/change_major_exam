#include <iostream>

using namespace std;

template <typename T>
void fill_impl(T (*array)[5], int size, T initial_value) {
  for (int left = 0, right = size - 1, top = 0, bottom = size - 1;
       left <= right && top <= bottom;
       ++left, --right, ++top, --bottom) {
    // 该圈上面部分 {top, left} -> {top, right}
    for (int column = left; column <= right; ++column) {
      array[top][column] = initial_value;
      ++initial_value;
    }

    // 该圈右边部分 {top + 1, right} -> {bottom, right}
    for (int row = top + 1; row <= bottom; ++row) {
      array[row][right] = initial_value;
      ++initial_value;
    }

    // 如果这一圈只有一行/一列内容, 则不用继续
    if (left < right && top < bottom) {
      // 否则继续

      // 该圈下边部分 {bottom, right - 1} -> {bottom, left}
      for (int column = right - 1; column >= left; --column) {
        array[bottom][column] = initial_value;
        ++initial_value;
      }

      // 该圈左边部分 {bottom - 1, left} -> {top - 1, left}
      for (int row = bottom - 1; row > top; --row) {
        array[row][left] = initial_value;
        ++initial_value;
      }
    }
  }
}

void fill(int (*num)[5], char (*ch)[5], int size) {
  fill_impl(num, size, 1);
  fill_impl(ch, size, 'a');
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

void print(int (*num)[5], char (*ch)[5], int size) {
  print_impl(num, size);
  print_impl(ch, size);
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