#include <iostream>

using namespace std;

void print(char const* s, int& num) {
  if (*s == '\0') {
    return;
  }
  num++;
  print(s + 1, num);
  cout << *s;
}

int main() {
  int n      = 0;
  char str[] = "chatgpt";
  print(str, n);
  cout << endl << n;
}