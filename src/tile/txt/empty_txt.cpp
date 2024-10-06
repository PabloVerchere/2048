#include "empty_txt.h"



Empty_txt* Empty_txt::clone() const {
    return new Empty_txt();
}


void Empty_txt::display() const {
    std::cout << *this;
}


// Overloading the '<<' operator to print the object
std::ostream& operator<<(std::ostream& os, const Empty_txt& e) {
    os << "*";
    return os;
}