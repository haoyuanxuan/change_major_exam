#include <iostream>

using namespace std;

int const text_size = 80;

int main() {
  char letters[27]     = {};
  char text[text_size] = {};
  cin.getline(text, text_size);
  for (int i = 0; i < strlen(text); ++i) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      ++letters[text[i] - 'a' + 1];
    } else if (text[i] >= 'A' && text[i] <= 'Z') {
      ++letters[text[i] - 'A' + 1];
    }
  }
  for (int i = 1; i <= 26; ++i) {
    if (letters[i] != 0) {
      cout << static_cast<char>(i + 'a' - 1) << '\t'
           << static_cast<int>(letters[i]) << endl;
    }
  }
}