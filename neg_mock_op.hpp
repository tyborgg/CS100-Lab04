#include "base.hpp"

using namespace std;

class NegOpMock: public Base {
    public:
        NegOpMock() { };

        virtual double evaluate() { return -7; }
        virtual string stringify() { return "-7"; }
};
