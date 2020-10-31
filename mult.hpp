#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class Mult : public Base {
    public:
	double product;
	double* num1;
	double* num2;
        Mult(double* op1, double* op2) : Base() { 
		this->num1 = op1;
		this->num2 = op2;
		this->product = *op1 * *op2;
	}
        virtual double evaluate() { return this->product; }
        virtual std::string stringify() {
		string strNum1 = to_string(*num1);
		string strNum2 = to_string(*num2);
		return strNum1 + " * " + strNum2;
	}
};

#endif //__MULT_HPP__
