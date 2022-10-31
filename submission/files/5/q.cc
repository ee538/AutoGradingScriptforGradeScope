#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.
// Creates an empty vector.
MyVector::MyVector() {
  size_ = 0;
  data_ = nullptr;
  error_ = ErrorCode::kNoError;
}

// Creates a vector of the given size.
MyVector::MyVector(int size) {
  size_ = size;
  data_ = new int[size];
  error_ = ErrorCode::kNoError;
}

// Copy constructor.
MyVector::MyVector(const MyVector& rhs) {
  size_ = rhs.size();
  data_ = new int[rhs.size()];
  for (int i = 0; i < rhs.size(); i++) {
    data_[i] = rhs.data_[i];
  }
  error_ = ErrorCode::kNoError;
}

// Destructor.
MyVector::~MyVector() {
  if (data_ != nullptr) {
    delete [] data_;
  }
}

// Inserts the given value at the back of the vector.
void MyVector::push_back(int value) {
  error_ = ErrorCode::kNoError;

  int* new_data = new int[size_ + 1];
  for (int i = 0; i < size_; i++) {
    new_data[i] = data_[i];
  }
  delete [] data_;
  data_ = new_data;
  data_[size_] = value;
  size_++;
}

// Removes and returns a value from the backs of the vector.
// Returns -1 if error and sets the error_ variable.
int MyVector::pop_back() {
  error_ = ErrorCode::kNoError;

  if (size_ == 0) {
    error_ = ErrorCode::kPopFromEmptyVector;
    return -1;
  }
  int result = data_[size_ - 1];

  int* new_data = new int[size_ - 1];
  for (int i = 0; i < size_ - 1; i++) {
    new_data[i] = data_[i];
  }

  delete [] data_;
  data_ = new_data;
  size_--;
  return result;
}

// Inserts the given value at the front of the vector.
void MyVector::push_front(int value) {
  error_ = ErrorCode::kNoError;

  int* new_data = new int[size_ + 1];
  new_data[0] = value;
  for (int i = 0; i < size_; i++) {
    new_data[i + 1] = data_[i];
  }
  delete [] data_;
  data_ = new_data;
  size_++;
}

// Removes and returns a value from the front of the vector.
int MyVector::pop_front() {
  error_ = ErrorCode::kNoError;

  if (size_ == 0) {
    error_ = ErrorCode::kPopFromEmptyVector;
    return -1;
  }
  int result = data_[0];

  int* new_data = new int[size_ - 1];
  for (int i = 0; i < size_ - 1; i++) {
    new_data[i] = data_[i + 1];
  }

  delete [] data_;
  data_ = new_data;
  size_--;

  return result;
}

// Inserts the given value after the given index.
void MyVector::insert(int value, int index) {
  error_ = ErrorCode::kNoError;

  if (index < -1 || index > size_ - 1) {
    error_ = ErrorCode::kIndexError;
    return;
  }

  int* new_data = new int[size_ + 1];
  int i = 0;
  for (; i <= index; i++) {
    new_data[i] = data_[i];
  }

  new_data[i] = value;
  i++;

  for (; i < size_ + 1; i++) {
    new_data[i] = data_[i - 1];
  }

  delete [] data_;
  data_ = new_data;
  size_++;
}

// Returns item at the given index. Returns -1 if error and sets error_.
int MyVector::at(int index) {
  error_ = ErrorCode::kNoError;

  if (index < 0 || index > size_ - 1) {
    error_ = ErrorCode::kIndexError;
    return -1;
  }
  return data_[index];
}

// Returns the first index of the given item in the vector. Returns -1 if not
// found, and sets error_.
int MyVector::find(int item) {
  error_ = ErrorCode::kNoError;

  for (int i = 0; i < size_; i++) {
    if (data_[i] == item) {
      return i;
    }
  }
  error_ = ErrorCode::kNotFound;
  return -1;
}

// Returns the value of error_
ErrorCode MyVector::get_error() const { return error_; }

// Returns the value of size_
int MyVector::size() const { return size_; }

// Converts to std::vector. Used for testing.
std::vector<int> MyVector::ConvertToStdVector() {
  error_ = ErrorCode::kNoError;

  std::vector<int> result;
  for (int i = 0; i < size_; i++) {
    result.push_back(data_[i]);
  }
  return result;
}
