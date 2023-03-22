#include "man/visualiser.hpp"

const std::vector<uint8_t> vs::man::visualiser::leds() const {
    return vmap.at(current)->leds();
}
