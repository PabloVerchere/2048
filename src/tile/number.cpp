#include "number.h"



Number::Number(int v): Tile() {
    value = v;
};



int Number::getValue() const {
    return value;
}


void Number::setValue(int v) {
    value = v;
}