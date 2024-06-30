#include <iostream>

using namespace std;

int const text_size = 80;

int main() {
  char letters[27]     = {};
  char text[text_size] = {};
  cin.getline(/* (1) */);
  for (int i = 0; i < strlen(text); ++i) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      ++letters[/* (2) */];
    } else if (/* (3) */) {
      ++letters[text[i] - 'A' + 1];
    }
  }
  for (int i = 1; i <= 26; ++i) {
    if (letters[i] != 0) {
      cout << static_cast<char>(/* (4) */) << '\t'
           << /* (5) */ << endl;
    }
  }
}