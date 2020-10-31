#include "base.hpp"

using namespace std;

class SevenOpMock: public Base {
    public:
        SevenOpMock() { }

        virtual double evaluate() { return 7;}
        virtual string stringify() { return "7"; }
};
