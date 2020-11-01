#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "base.hpp"
#include "op.hpp"
#include "pow.hpp"

TEST(SubTest, SubEvaluateNonZero)
{
	Base* Op1 = new Op(5);
	Base* Op2 = new Op(3);
	Base* test = new Sub(Op1,Op2);
	EXPECT_EQ(2, test->evaluate());
}

TEST(SubTest, StringPosNums)
{
	Base* Op1 = new Op(8);
	Base* Op2 = new Op(4);
	Base* test = new Sub(Op1,Op2);
	EXPECT_EQ(test->stringify(),"8.000000 - 4.000000");
}

TEST(SubTest, SubEvaluateZeroAndNeg)
{
        Base* Op1 = new Op(0);
        Base* Op2 = new Op(-73);
        Base* test = new Sub(Op1,Op2);
        EXPECT_EQ(73, test->evaluate());
}

TEST(SubTest, SubStringNegNums)
{
        Base* Op1 = new Op(-30);
        Base* Op2 = new Op(-7);
        Base* test = new Sub(Op1,Op2);
        EXPECT_EQ("-30.000000 - -7.000000", test->stringify());
}

TEST(SubTest, SubEvaluateNegAnswer)
{
        Base* Op1 = new Op(30);
        Base* Op2 = new Op(50);
        Base* test = new Sub(Op1,Op2);
        EXPECT_EQ(-20, test->evaluate());
}

TEST(SubTest, SubEvaluatePowAndOp)
{
	Base* Op1 = new Op(2);
	Base* Op2 = new Op(2);
	Base* Pow1 = new Pow(Op1,Op2); //Pow1 == 4
	Base* test = new Sub(Pow1, Op2);
	EXPECT_EQ(2, test->evaluate());
}

TEST(SubTest, SubStringifyPowAndOp)
{
	Base* Op1 = new Op(3);
	Base* Op2 = new Op(2);
	Base* Pow1 = new Pow(Op1,Op2); //Pow1 = 9
	Base* test = new Sub(Pow1,Op2);
	EXPECT_EQ("3.000000 ** 2.000000 - 2.000000",test->stringify());
}


#endif //__SUB_TEST_HPP__

