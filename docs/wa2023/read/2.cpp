#include <iostream>

class B {
 public:
  static int count;

  B() {
    count++;
  }

  ~B() {
    count--;
  }

  void show() {
    std::cout << count << '\n';
  }
};

int B::count = 0;

void func() {
  B a;
  B* pointer = new B[5];
  a.show();
  delete[] pointer;
  a.show();
}

B x;

int main() {
  B a;
  B* b = new B;
  x.show();
  func();
  delete b;
  x.show();
}