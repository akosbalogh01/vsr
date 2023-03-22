#include "consts.hpp"
#include "man/debug.hpp"

void vs::man::debug::signal(const vs::man::debug::dclock t) {
    prev[t] = runtime.getElapsedTime().asMicroseconds() - timers[t].asMicroseconds();
    timers[t] = runtime.getElapsedTime();
}

void vs::man::debug::closeOverlay() {
    overlay.close();
}
