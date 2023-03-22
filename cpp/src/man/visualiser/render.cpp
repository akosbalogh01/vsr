#include "man/visualiser.hpp"

void vs::man::visualiser::render() {
    if (en) {
        vmap[current]->render();
    }
}
