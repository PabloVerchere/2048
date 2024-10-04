#include "number_txt.h"


void Number_txt::display() const {
    std::cout << *this;
}

// Overloading the '<<' operator to print the object
std::ostream& operator<<(std::ostream& os, const Number_txt& n) {
    os << n.getValue();
    return os;
}