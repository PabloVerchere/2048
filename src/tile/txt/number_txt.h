#ifndef NUMBER_TXT_H
#define NUMBER_TXT_H


#include <iostream>

#include "number.h"


class Number_txt: public Number {
    public:
        Number_txt() {};
        ~Number_txt() {};

        virtual void display() const override; // abstract method

        friend std::ostream& operator<<(std::ostream& os, const Number_txt& n);
};

#endif