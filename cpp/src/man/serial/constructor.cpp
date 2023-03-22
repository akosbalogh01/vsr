#include "man/serial.hpp"

vs::man::serial::serial() {
    init();
}

vs::man::serial::~serial() {
    disable();
}
