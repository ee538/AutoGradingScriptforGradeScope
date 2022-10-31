#include "q.h"

#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Returns the index of the fist space character in a string.
int IndexOfFirstSpace(std::string& input) {
  for (size_t i = 0; i < input.size(); i++) {
    if (input[i] == ' ') {
      return i;
    }
  }
  return -1;
}

// Given the full_name, it returns the first_name and last_name.
// Note: you should use IndexOfFirstSpace function and cannot use any other
// std:: functions.
void SeparateFirstAndLastNames(std::string& full_name, std::string& first_name,
                               std::string& last_name) {
  auto index_of_first_space = IndexOfFirstSpace(full_name);

  if (index_of_first_space != -1) {
    first_name = full_name.substr(0, index_of_first_space);
    last_name = full_name.substr(index_of_first_space + 1);
  } else {
    first_name = full_name;
  }
}

// Returns the number of vowels (a, e, i, o, u) in a string.
// Your algorithm should be case insensitive.
int NumberOfVowels(std::string& input) {
  std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  int count = 0;
  for (auto e : input) {
    auto l = std::tolower(e);
    if ((l >= 'a' && l <= 'z') &&
        std::find(vowels.begin(), vowels.end(), l) != vowels.end()) {
      count++;
    }
  }
  return count;
}

// Returns the number of consonants (letters that are not a, e, i, o, u) in a
// string.
// Returns the number of vowels (a, e, i, o, u) in a string.
// Your algorithm should be case insensitive.
int NumberOfConsonants(std::string& input) {
  std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  int count = 0;
  for (auto e : input) {
    auto l = std::tolower(e);
    if ((l >= 'a' && l <= 'z') &&
        std::find(vowels.begin(), vowels.end(), l) == vowels.end()) {
      count++;
    }
  }
  return count;
}

// Returns the revers of a string.
// Example input: 'ted', output: 'det'.
// Note: You cannot use any std:: functions.
int Reverse(std::string& input) {
  for (size_t i = 0; i < input.size() / 2; i++) {
    auto temp = input[i];
    input[i] = input[input.size() - 1 - i];
    input[input.size() - 1 - i] = temp;
  }

  return 0;
}
