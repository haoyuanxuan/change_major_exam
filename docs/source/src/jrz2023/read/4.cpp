#include <iostream>

using namespace std;

template <class T>
class CL {
 private:
  T a[10];
  int num;

 public:
  CL() {
    num = 0;
  }
  void set(int i, T val) {
    a[i] = val;
    num++;  //?
  }
  T Re(int i) {
    return a[i];
  }
  void out() {
    cout << '{';
    for (int i = 0; i < num - 1; i++) {
      cout << a[i] << ", ";
    }
    cout << a[num - 1] << '}' << endl;
  }
};

int main() {
  CL<int> a;
  CL<double> b;
  CL<char> c;
  for (int i = 0; i < 5; i++) {
    a.set(i, i), b.set(i, i * 1.1), c.set(i, i + 'A');
  }
  a.out();
  b.out();
  c.out();
  cout << "int  2..... is: " << a.Re(2) << endl;
  cout << "char  3..... is: " << c.Re(3) << endl;
  /* 之后的部分忘记了 */
}