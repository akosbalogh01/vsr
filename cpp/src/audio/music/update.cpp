#include "consts.hpp"
#include "fft/fft.hpp"
#include "music.hpp"

void vs::music::update() {
    ctrl.update(sound.getPlayingOffset());
    modVolume();
    modBrightness();
}
