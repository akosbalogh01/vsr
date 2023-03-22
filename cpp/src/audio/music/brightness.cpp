#include "music.hpp"

void vs::music::setMaxBrightness(const unsigned bmax) {
    if ((bmax >= 0) && (bmax <= 100)) {
        maxbr = bmax;
    }
}

void vs::music::modBrightness() {
    curbr = ctrl.getBrightness();
    curbr *= ((float) maxbr/100);
}

unsigned vs::music::getMaxBrightness() const {
    return maxbr;
}

unsigned vs::music::getModBrightness() const {
    return curbr;
}
