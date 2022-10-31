#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(Reverse, EvenSize) {
  std::string test_string = "abcd";
  std::cout << "test_string: " << test_string << std::endl;

  Reverse(test_string);
  EXPECT_EQ(test_string, "dcba");
}

TEST(Reverse, EvenSize2) {
  std::string test_string = "abcd";
  std::cout << "test_string: " << test_string << std::endl;

  Reverse(test_string);
  EXPECT_EQ(test_string, "dcba");
}