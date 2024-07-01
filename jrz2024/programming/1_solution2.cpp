#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto to_lower(std::string string) -> std::string {
  for (char& ch : string) {
    ch = std::tolower(ch);
  }
  return string;
}

auto split_case_insensitive_words(std::string const& line)
    -> std::vector<std::string> {
  std::vector<std::string> words;

  std::stringstream oss(line);
  for (std::string word; oss >> word;) {
    words.push_back(to_lower(word));
  }

  std::sort(words.begin(), words.end());
  words.erase(std::unique(words.begin(), words.end()), words.end());
  return words;
}

auto main() -> int {
  std::string line;
  std::getline(std::cin, line);

  for (auto const& word : split_case_insensitive_words(line)) {
    std::cout << word << '\n';
  }
}