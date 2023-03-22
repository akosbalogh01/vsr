#include "man/visualiser.hpp"

void vs::man::visualiser::update() {
    if (en) {
        vmap[current]->update();
    }
}
