#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "seven_mock_op.hpp"
#include "zero_mock_op.hpp"
#include "neg_mock_op.hpp"

TEST(DivTest, BothZero) {
    ZeroOpMock call;
    double* op1 = new double(call.evaluate());
    double* op2 = new double(0);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(DivTest, BothZeroString) {
    double* op1 = new double(0);
    double* op2 = new double(0);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"0.000000 / 0.000000");
}

TEST(DivTest, PosNum) {
    SevenOpMock call;	
    double* op1 = new double(call.evaluate());
    double* op2 = new double(call.evaluate());
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), 1);
}
TEST(DivTest, PosNumString) {
    SevenOpMock call;
    double* op1 = new double(call.evaluate());
    double* op2 = new double(call.evaluate());
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"7.000000 / 7.000000");
}

TEST(DivTest, BothNeg) {
    NegOpMock call;
    double* op1 = new double(call.evaluate());
    double* op2 = new double(-14);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), 0.5);
}
TEST(DivTest, BothNegString) {
    double* op1 = new double(-6);
    double* op2 = new double(-5);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"-6.000000 / -5.000000");
}

TEST(DivTest, NegAndPos) {
    double* op1 = new double(10);
    double* op2 = new double(-5);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), -2);
}
TEST(DivTest, NegAndPosString) {
    double* op1 = new double(10);
    double* op2 = new double(-5);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"10.000000 / -5.000000");
}

TEST(DivTest, PosAndZero) {
    ZeroOpMock call;
    double* op1 = new double(call.evaluate());
    double* op2 = new double(5);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(DivTest, PosAndZeoString) {
    ZeroOpMock call;
    double* op1 = new double(call.evaluate());
    double* op2 = new double(5);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"0.000000 / 5.000000");
}

TEST(DivTest, ZeroInDenominator) {
    ZeroOpMock call;
    double* op2 = new double(call.evaluate());
    double* op1 = new double(5);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), -1);
}
TEST(DivTest, ZeroInDenominatorString) {
    ZeroOpMock call;
    double* op2 = new double(call.evaluate());
    double* op1 = new double(5);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"5.000000 / 0.000000");
}


#endif //__DIV_TEST_HPP__
