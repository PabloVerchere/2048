#ifndef EMPTY_TXT_H
#define EMPTY_TXT_H


#include <iostream>

#include "../empty.h"



class Empty_txt: public Empty {
    public:
        Empty_txt* clone() const override;

        void display() const;
};

std::ostream& operator<<(std::ostream& os, const Empty_txt&);

#endif