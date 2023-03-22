#include "man/audio.hpp"
#include "man/playlist.hpp"

void vs::man::playlist::next(const bool paused) {
    if (current == songlist.size() - 1) {
        std::cout << "Playlist over" << std::endl;
        playing->pause();
        //reset();
    }
    else if (songlist.size() <= bufsize) {
        current++;
        playing->copyData(songlist[current]);
        std::cout << "Start next song: " << playing->getMeta() << std::endl;
        if (!paused) playing->play();
    }
    else {
        unsigned range = (bufsize / 2);
        dropBuffer(current - range);
        current++;
        playing->copyData(songlist[current]);
        std::cout << "Start next song: " << playing->getMeta() << std::endl;
        if (!paused) playing->play();
        initBuffer(current + range);
    }
}
