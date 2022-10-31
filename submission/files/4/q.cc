#include "q.h"

// Given two integers, returns the result of the operation based on the given
// operator.
float Calculate(int a, int b, Operation operation) {
  switch (operation) {
    case Operation::kAdd:
      return a + b;
      break;
    case Operation::kSubtract:
      return a - b;
      break;
    case Operation::kDivision:
      if (b != 0) {
        return a / b;
      } else {
        return -1;
      }
      break;
    case Operation::kMultiplication:
      return a * b;
      break;
    case Operation::kBitwise_AND:
      return a & b;
      break;
    case Operation::kBitwise_OR:
      return a | b;
      break;
    case Operation::kBitwise_XOR:
      return a ^ b;
      break;
    case Operation::kShift_right:
      return a >> b;
      break;
    case Operation::kShift_left:
      return a << b;
      break;
    default:
      return -1;
  }
}
