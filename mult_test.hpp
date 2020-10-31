#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "seven_mock_op.hpp"
#include "zero_mock_op.hpp"
#include "neg_mock_op.hpp"

TEST(MultTest, BothZero) {
    ZeroOpMock call;
    double* op1 = new double(call.evaluate());
    double* op2 = new double(0);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(MultTest, BothZeroString) {
    double* op1 = new double(0);
    double* op2 = new double(0);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(),"0.000000 * 0.000000");
}

TEST(MultTest, PosNum) {
    SevenOpMock call;	
    double* op1 = new double(call.evaluate());
    double* op2 = new double(call.evaluate());
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), 49);
}
TEST(MultTest, PosNumString) {
    SevenOpMock call;
    double* op1 = new double(call.evaluate());
    double* op2 = new double(call.evaluate());
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(),"7.000000 * 7.000000");
}

TEST(MultTest, BothNeg) {
    NegOpMock call;
    double* op1 = new double(call.evaluate());
    double* op2 = new double(-5);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), 35);
}
TEST(MultTest, BothNegString) {
    double* op1 = new double(-6);
    double* op2 = new double(-5);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(),"-6.000000 * -5.000000");
}

TEST(MultTest, NegAndPos) {
    double* op1 = new double(6);
    double* op2 = new double(-5);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), -30);
}
TEST(MultTest, NegAndPosString) {
    double* op1 = new double(6);
    double* op2 = new double(-5);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(),"6.000000 * -5.000000");
}

TEST(MultTest, PosAndZero) {
    ZeroOpMock call;
    double* op1 = new double(call.evaluate());
    double* op2 = new double(5);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(MultTest, PosAndZeoString) {
    ZeroOpMock call;
    double* op1 = new double(call.evaluate());
    double* op2 = new double(5);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(),"0.000000 * 5.000000");
}

#endif //__MULT_TEST_HPP__
