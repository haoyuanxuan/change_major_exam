#include <iostream>
#include <string>

using namespace std;

template <typename T>
class A {
 public:
  A(T input_value) {
    this->value_ = input_value;
    count_++;
  }

  ~A() {
    count_--;
  }

  static int show_number() {
    cout << "Count is: " << count_ << '\n';
    return count_;
  }

  T show_value() {
    cout << value_ << '\n';
    return value_;
  }

 private:
  static int count_;

  T value_;
};

template <typename T>
int A<T>::count_ = 0;

int main() {
  A<int> a1(92), a2(93), a3(95);
  A<int>::show_number();
  A<std::string> s1("92");
  A<std::string>* s = new A<std::string>("93");
  A<std::string>::show_number();
  delete s;
  A<std::string>::show_number();
  a3.show_value();
  s1.show_value();
  return 0;
}