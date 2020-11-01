#ifndef __DIV_HPP__
#define __DIV_HPP__

#include <iostream>
#include <string>
#include "base.hpp"

using namespace std;

class Div : public Base {
    public:
        double product;
        double* num1;
        double* num2;
        Div(double* op1, double* op2) : Base() {
                this->num1 = op1;
                this->num2 = op2;
		if(*num1 == 0){
			this->product = 0;
		}
		else if(*num2 == 0){
			this->product = -1;
			cout << "Error" << endl;
		}
		else{
                	this->product = *op1 / *op2;
		}
        }
        virtual double evaluate() { return this->product; }
        virtual string stringify() {
                string strNum1 = to_string(*num1);
                string strNum2 = to_string(*num2);
                return strNum1 + " / " + strNum2;
        }
};

#endif //__DIV_HPP__

