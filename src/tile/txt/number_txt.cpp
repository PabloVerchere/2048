#include "number_txt.h"



Number_txt::Number_txt(int v): Number(v) {}



void Number_txt::display() const {
    setColor();
    std::cout << *this;
    resetColor();
}


void Number_txt::setColor() const {
    if (getValue() == 2) {
        std::cout << "\033[0;32m"; // Green
    }
    else if (getValue() == 4) {
        std::cout << "\033[92m"; // Green H
    }
    else if (getValue() == 8) {
        std::cout << "\033[35m";  // Purple
    }
    else if (getValue() == 16) {
        std::cout << "\033[95m";  // Purple H
    } 
    else if (getValue() == 32) {
        std::cout << "\033[36m";  // Cyan
    }
    else if (getValue() == 64) {
        std::cout << "\033[96m";  // Cyan H
    }
    else if (getValue() == 128) {
        std::cout << "\033[31m";  // Red
    }
    else if (getValue() == 256) {
        std::cout << "\033[91m";  // Red H
    }
    else if (getValue() == 512) {
        std::cout << "\033[33m";  // Yellow
    }
    else if (getValue() == 1024) {
        std::cout << "\033[93m";  // Yellow H
    }
    else if (getValue() == 2048) {
        std::cout << "\033[37m";  // White
    }
    else {
        std::cout << "\e[0;97m";  // White H
    }

/*
\e[0;97m	White
*/
}

void Number_txt::resetColor() const {
    std::cout << "\033[0m"; // Reset to default text color
}




// Overloading the '<<' operator to print the object
std::ostream& operator<<(std::ostream& os, const Number_txt& n) {
    os << n.getValue();
    return os;
}