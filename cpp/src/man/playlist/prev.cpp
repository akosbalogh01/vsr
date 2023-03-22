#include "man/playlist.hpp"

void vs::man::playlist::prev(const bool paused) {
    if (current == 0) {
        std::cout << "Playlist restart" << std::endl;
        reset();
        if (!paused) playing->play();
    }
    else if (songlist.size() <= bufsize) {
        current--;
        playing->copyData(songlist[current]);
        std::cout << "Start prev song: " << playing->getMeta() << std::endl;
        if (!paused) playing->play();
    }
    else {
        unsigned range = (bufsize / 2);
        dropBuffer(current + range);
        current--;
        playing->copyData(songlist[current]);
        std::cout << "Start prev song: " << playing->getMeta() << std::endl;
        if (!paused) playing->play();
        initBuffer(current - range);
    }
}
