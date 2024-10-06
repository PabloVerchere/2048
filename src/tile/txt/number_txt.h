#ifndef NUMBER_TXT_H
#define NUMBER_TXT_H


#include <iostream>

#include "../number.h"



class Number_txt: public Number {
    public:
        Number_txt(int v);


        void display() const;
};

std::ostream& operator<<(std::ostream& os, const Number_txt& n);

#endif