#include "gtest/gtest.h"

//#include "seven_mock_op.hpp"
//#include "neg_mock_op.hpp"
//#include "zero_mock_op.hpp"
//#include "op_test.hpp"
#include "rand_test.hpp"
#include "mult_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
