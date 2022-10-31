#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CountCharacters, CharactersExistCaseInsensitive) {
  std::string input = "This is a test";
  std::vector<char> characters = {'t', 'h'};

  std::cout << "input: " << input << std::endl;

  std::cout << "characters: " << std::endl;
  for (auto c : characters) {
    std::cout << "c: " << c << std::endl;
  }

  EXPECT_EQ(CountCharacters(input, characters), 4);
}

TEST(CountCharacters, CharactersNotInInput) {
  std::string input = "This is a test";
  std::vector<char> characters = {'z', 'x'};

  std::cout << "input: " << input << std::endl;
  std::cout << "characters: " << std::endl;
  for (auto c : characters) {
    std::cout << "c: " << c << std::endl;
  }

  EXPECT_EQ(CountCharacters(input, characters), 0);
}

TEST(CountCharacters, EmptyCharacters) {
  std::string input = "This is a test";
  std::vector<char> characters = {};

  std::cout << "input: " << input << std::endl;
  std::cout << "characters: " << std::endl;
  for (auto c : characters) {
    std::cout << "c: " << c << std::endl;
  }

  EXPECT_EQ(CountCharacters(input, characters), 0);
}

TEST(CountCharacters, EmptyInput) {
  std::string input = "";
  std::vector<char> characters = {'A', 'b'};

  std::cout << "input: " << input << std::endl;
  std::cout << "characters: " << std::endl;
  for (auto c : characters) {
    std::cout << "c: " << c << std::endl;
  }

  EXPECT_EQ(CountCharacters(input, characters), 0);
}
