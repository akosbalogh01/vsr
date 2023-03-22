#include "music.hpp"

unsigned vs::music::getMaxVolume() const {
    return maxvol;
}

unsigned vs::music::getModVolume() const {
    return sound.getVolume();
}

void vs::music::setMaxVolume(const unsigned vmax) {
    if ((vmax >= 0) && (vmax <= 100)) {
        maxvol = vmax;
    }
}

void vs::music::modVolume() {
    curvol = ctrl.getVolume();
    curvol *= ((float) maxvol/100);
    sound.setVolume(curvol);
}

