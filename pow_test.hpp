#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "pow.hpp"
#include "op.hpp"
#include "base.hpp"
#include "sub.hpp"

TEST(PowTest, PowEvaluateNonZero)
{
        Base* Op1 = new Op(5);
        Base* Op2 = new Op(3);
        Base* test = new Pow(Op1,Op2);
        EXPECT_EQ(125, test->evaluate());
}

TEST(PowTest, PowEvaluateNegNumbers)
{
        Base* Op1 = new Op(-5);
        Base* Op2 = new Op(-3);
        Base* test = new Pow(Op1,Op2);
        EXPECT_EQ(-.008, test->evaluate());
}

TEST(PowTest, PowStringifyNonZero)
{
        Base* Op1 = new Op(5);
        Base* Op2 = new Op(3);
        Base* test = new Pow(Op1,Op2);
        EXPECT_EQ("5.000000 ** 3.000000", test->stringify());
}

TEST(PowTest, PowEvaluateSubAndOp)
{
        Base* Op1 = new Op(5);
	Base* Op2 = new Op(3);
        Base* Sub1 = new Sub(Op1,Op2); //Sub1 == 2
        Base* test = new Pow(Sub1,Op2);
        EXPECT_EQ(8, test->evaluate());
}

TEST(PowTest, PowEvaluateOnlyZeros)
{
	Base* Op1 = new Op(0);
	Base* Op2 = new Op(0);
	Base* test = new Pow(Op1,Op2);
	EXPECT_EQ(1, test->evaluate());
}

TEST(PowTest, PowStringifySubAndOp)
{
	Base* Op1 = new Op(1);
	Base* Op2 = new Op(2);
	Base* Sub1 = new Sub(Op1,Op2);
	Base* test = new Pow(Sub1,Op2);
	EXPECT_EQ("1.000000 - 2.000000 ** 2.000000",test->stringify());
}

#endif //__POW_TEST_HPP__
