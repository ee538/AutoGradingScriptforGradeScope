#include "q.h"

#include <algorithm>
#include <iostream>
#include <vector>

int CountCharacters(std::string& input, std::vector<char> characters) {
  int result = 0;
  std::vector<char> characters_lower_case(characters.size());

  std::transform(characters.begin(), characters.end(),
                 characters_lower_case.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  for (auto c : input) {
    if (std::find(characters_lower_case.begin(), characters_lower_case.end(),
                  std::tolower(c)) != characters_lower_case.end()) {
      result++;
    }
  }
  return result;
}
