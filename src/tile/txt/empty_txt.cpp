#include "empty_txt.h"


void Empty_txt::display() const {
    std::cout << *this;
}

// Overloading the '<<' operator to print the object
std::ostream& operator<<(std::ostream& os, const Empty_txt& e) {
    os << " ";
    return os;
}