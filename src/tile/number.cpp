#include "number.h"


Number::Number(): Tile() {};
Number::~Number() {};


int Number::getValue() const {
    return value;
}

void Number::setValue(int v) {
    value = v;
}