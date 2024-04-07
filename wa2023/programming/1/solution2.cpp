#include <iostream>

using namespace std;

struct Direction {
 public:
  int row;
  int column;
};

Direction directions[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

template <typename T>
void fill_impl(T (*array)[5], int size, T initial_value) {
  T const impossible_value = initial_value - 1;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      array[i][j] = impossible_value;  // 初始化为一个不可能值
    }
  }

  for (int i = 0, j = 0, direction_index = 0, filled_count = 0;
       filled_count < size * size;
       ++filled_count) {
    array[i][j] = initial_value;
    ++initial_value;

    // 按当前方向继续下去, 超出边界或值已经被设置
    if (i + directions[direction_index].row < 0
        || i + directions[direction_index].row >= size
        || j + directions[direction_index].column < 0
        || j + directions[direction_index].column >= size
        || array[i + directions[direction_index].row]
                [j + directions[direction_index].column]
               != impossible_value) {
      direction_index = (direction_index + 1) % 4;
    }

    i += directions[direction_index].row;
    j += directions[direction_index].column;
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