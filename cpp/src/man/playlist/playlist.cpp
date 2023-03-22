#include <iostream>
#include "man/audio.hpp"
#include "man/playlist.hpp"

void vs::man::playlist::reset() {
    std::cout << "Reset playlist" << std::endl;

    unsigned i;
    for (i = 0; i < songlist.size(); ++i) {
        songlist[i].dropBuffer();
    }
    for (i = 0; i < bufsize; ++i) {
        songlist[i].initBuffer();
    }

    current = 0;
}

void vs::man::playlist::initBuffer(unsigned i) {
    if ((i >= 0) && (i < songlist.size())) {
        songlist[i].initBuffer();
    }
}

void vs::man::playlist::dropBuffer(unsigned i) {
    if ((i >= 0) && (i < songlist.size())) {
        songlist[i].dropBuffer();
    }
}
