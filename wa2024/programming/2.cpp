#include <iostream>
#include <utility>
double const pi = 3.141592653589793238462643383279502;

class Circle {
 public:
  Circle(int radius = 0) : radius_(radius) {}

  auto area() -> double {
    return radius_ * radius_ * pi;
  }

  void set_radius(int radius) {
    radius_ = radius;
  }
  auto get_radius() const -> int {
    return radius_;
  }

  friend auto operator<(Circle const& lhs, Circle const& rhs) -> bool {
    return lhs.radius_ < rhs.radius_;
  }

 private:
  int radius_;
};

// 冒泡排序的思路是:
// - 从左到右, 每次取两个元素, 如果左元素比右元素大, 则将左元素交换到右边去
// - 这样一次遍历以后, 当前数组中的最大元素将会像气泡一样冒到右边.
// - 由此数组将会分割为左边的未有序部分和右边的有序部分, 一直冒泡直到未有序部分全部冒泡过一次即完成排序.
//
// 例如:
//   3 7 1 4 2 |
//   3 1 4 2 | 7
//   3 1 2 | 4 7
//   1 2 | 3 4 7
//   1 | 2 3 4 7
//   | 1 2 3 4 7
//
// 虽然但是, 冒泡排序完全没有实际用途, 教起来又不如插入排序之类的简单, 完全不清楚为什么要教
void bubble_sort(Circle* array, int size) {
  for (int sorted_size = 0; sorted_size < size; ++sorted_size) {
    int const current_size = size - sorted_size;
    for (int index = 0; index < current_size - 1; ++index) {
      if (array[index + 1] < array[index]) {
        std::swap(array[index], array[index + 1]);  // #include <utility>
      }
    }
  }
}

int main() {
  Circle c1(3);
  Circle c2(4);
  Circle c3(2);
  Circle c4(1);
  Circle circles[4] = {c1, c2, c3, c4};

  bubble_sort(circles, 4);

  for (auto const& circle : circles) {
    std::cout << circle.get_radius() << ' ';
  }
}