#include "man/bars.hpp"

vs::bar& vs::man::bars::operator[](const unsigned i) {
    return barv[i];
}

const vs::bar& vs::man::bars::operator[](const unsigned i) const {
    return barv[i];
}
