#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int m;
  cin >> m;
  int num[5][5] = {};
  char ch[5][5] = {};
  fill(num, ch, m);
  print(num, ch, m);
  return 0;
}