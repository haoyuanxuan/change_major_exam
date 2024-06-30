#include <cctype>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

auto to_lower(std::string string) -> std::string {
  for (char& ch : string) {
    ch = std::tolower(ch);
  }
  return string;
}

auto split_case_insensitive_words(std::string const& line)
    -> std::set<std::string> {
  std::set<std::string> words;

  std::stringstream oss(line);
  for (std::string word; oss >> word;) {
    words.insert(to_lower(word));
  }

  return words;
}

int main() {
  std::string line;
  std::getline(std::cin, line);

  for (auto const& word : split_case_insensitive_words(line)) {
    std::cout << word << '\n';
  }
}