#include <iostream>
#include <string>

using namespace std;

class A {
 public:
  A(string s = "A101") : aid(s) {}

  virtual void out() {
    cout << "Aid:" << aid << endl;
  }

 private:
  string aid;
};

class B : public A {
 public:
  B(string s = "B201") : bid(s) {}

  virtual void out() {
    A::out();
    cout << "Bid:" << bid << endl;
  }

 private:
  string bid;
};

class C : public A {
 public:
  C(string s = "C301") : A(s) {}

  virtual void out() {
    A::out();
    b.out();
  }

 private:
  B b;
};

int main() {
  A sa("A102");
  B sb("B202");
  C sc("C302");
  A* str[3] = {&sa, &sb, &sc};
  for (int i = 0; i < 3; i++) {
    str[i]->out();
  }
  return 0;
}