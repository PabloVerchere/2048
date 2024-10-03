#ifndef EMPTY_TXT_H
#define EMPTY_TXT_H


#include <iostream>

#include "empty.h"


class Empty_txt: public Empty {
    public:
        Empty_txt() {};
        ~Empty_txt() {};

        virtual void display() const override; // abstract method

        friend std::ostream& operator<<(std::ostream& os, const Empty_txt& e);
};

#endif