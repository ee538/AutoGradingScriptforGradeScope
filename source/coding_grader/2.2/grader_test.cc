#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

TEST(IndexOfFirstSpace, EmptyString) {
  std::string test_string = "";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(IndexOfFirstSpace(test_string), -1);
}

TEST(IndexOfFirstSpace, NoSpace) {
  std::string test_string = "ThisIsATest";
  std::cout << "test_string: " << test_string << std::endl;
  EXPECT_EQ(IndexOfFirstSpace(test_string), -1);
}

TEST(IndexOfFirstSpace, StringWithMultipleSpaces) {
  std::string test_string = "This is a test";
  std::cout << "test_string: " << test_string << std::endl;
  EXPECT_EQ(IndexOfFirstSpace(test_string), 4);
}
TEST(IndexOfFirstSpace, StringWithSingleSpace) {
  std::string test_string = "ThisIs aTest";
  std::cout << "test_string: " << test_string << std::endl;
  EXPECT_EQ(IndexOfFirstSpace(test_string), 6);
}

TEST(IndexOfFirstSpace, SpaceInTheBeginning) {
  std::string test_string = " This Is a Test";
  std::cout << "test_string: " << test_string << std::endl;
  EXPECT_EQ(IndexOfFirstSpace(test_string), 0);
}

TEST(IndexOfFirstSpace, SpaceInTheEnd) {
  std::string test_string = "ThisIsATest ";
  std::cout << "test_string: " << test_string << std::endl;
  EXPECT_EQ(IndexOfFirstSpace(test_string), 11);
}
//-----------------------------------------------------------------------------
TEST(SeparateFirstAndLastNames, Empty) {
  std::string full_name = "";
  std::string first_name;
  std::string last_name;

  std::cout << "full_name: " << full_name << std::endl;
  SeparateFirstAndLastNames(full_name, first_name, last_name);
  EXPECT_TRUE(first_name.empty());
  EXPECT_TRUE(last_name.empty());
}
TEST(SeparateFirstAndLastNames, NoSpace) {
  std::string full_name = "TommyTrojan";
  std::string first_name;
  std::string last_name;

  std::cout << "full_name: " << full_name << std::endl;
  SeparateFirstAndLastNames(full_name, first_name, last_name);
  EXPECT_EQ(first_name, "TommyTrojan");
  EXPECT_TRUE(last_name.empty());
}

TEST(SeparateFirstAndLastNames, SingleSpace) {
  std::string full_name = "Tommy Trojan";
  std::string first_name;
  std::string last_name;

  std::cout << "full_name: " << full_name << std::endl;
  SeparateFirstAndLastNames(full_name, first_name, last_name);
  EXPECT_EQ(first_name, "Tommy");
  EXPECT_EQ(last_name, "Trojan");
}

TEST(SeparateFirstAndLastNames, MultipleSpaces) {
  std::string full_name = "Tommy Trojan Second";
  std::string first_name;
  std::string last_name;

  std::cout << "full_name: " << full_name << std::endl;

  SeparateFirstAndLastNames(full_name, first_name, last_name);
  EXPECT_EQ(first_name, "Tommy");
  EXPECT_EQ(last_name, "Trojan Second");
}
//-----------------------------------------------------------------------------
TEST(NumberOfVowels, NoVowels) {
  std::string test_string = "XkCBDjk";
  std::cout << "test_string: " << test_string << std::endl;
  EXPECT_EQ(NumberOfVowels(test_string), 0);
}

TEST(NumberOfVowels, AllVowels) {
  std::string test_string = "aieou";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(NumberOfVowels(test_string), 5);
}

TEST(NumberOfVowels, MultipleVowelsCombined) {
  std::string test_string = "This is a test";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(NumberOfVowels(test_string), 4);
}

TEST(NumberOfVowels, MultipleVowelsCombinedChangeCase) {
  std::string test_string = "ThiS Is A test";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(NumberOfVowels(test_string), 4);
}

TEST(NumberOfConsonants, NonLettersCombinedWithVowels) {
  std::string test_string = " __+098234BC ao";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(NumberOfVowels(test_string), 2);
}
//-----------------------------------------------------------------------------
TEST(NumberOfConsonants, NoConsonants) {
  std::string test_string = "aieou";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(NumberOfConsonants(test_string), 0);
}
TEST(NumberOfConsonants, AllConsonants) {
  std::string test_string = "XkCBDjk";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(NumberOfConsonants(test_string), 7);
}

TEST(NumberOfVowels, MultipleConsonantsCombinedChangeCase) {
  std::string test_string = "ThiS Is A test";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(NumberOfConsonants(test_string), 7);
}

TEST(NumberOfConsonants, MultipleConsonantsCombined) {
  std::string test_string = "This is a test";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(NumberOfConsonants(test_string), 7);
}

TEST(NumberOfConsonants, NonLetters) {
  std::string test_string = " __+098234";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(NumberOfConsonants(test_string), 0);
}

TEST(NumberOfConsonants, NonLettersCombinedWithConsonants) {
  std::string test_string = " __+098234BC ao";
  std::cout << "test_string: " << test_string << std::endl;

  EXPECT_EQ(NumberOfConsonants(test_string), 2);
}
//-----------------------------------------------------------------------------
TEST(Reverse, Empty) {
  std::string test_string = "";
  std::cout << "test_string: " << test_string << std::endl;

  Reverse(test_string);
  EXPECT_EQ(test_string, "");
}

TEST(Reverse, SingleSize) {
  std::string test_string = "a";
  std::cout << "test_string: " << test_string << std::endl;

  Reverse(test_string);
  EXPECT_EQ(test_string, "a");
}

TEST(Reverse, OddSize) {
  std::string test_string = "abc";
  std::cout << "test_string: " << test_string << std::endl;

  Reverse(test_string);
  EXPECT_EQ(test_string, "cba");
}

TEST(Reverse, EvenSize) {
  std::string test_string = "abcd";
  std::cout << "test_string: " << test_string << std::endl;

  Reverse(test_string);
  EXPECT_EQ(test_string, "dcba");
}
