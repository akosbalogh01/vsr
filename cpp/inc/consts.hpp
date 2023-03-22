#ifndef VISU_CONSTS
#define VISU_CONSTS

#include <complex>
#include <memory>
#include <stdexcept>
#include <windows.h>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "music.hpp"

namespace vs {
    namespace t {
        typedef std::shared_ptr<vs::music> mptr;
        typedef sf::RenderWindow* const rtarget;
        typedef std::complex<float> cx;
    }

    namespace path {
        const std::string font = "Roboto-Regular.ttf";
    }

    namespace gfx {
        const unsigned framelimit = 60;
        const unsigned ledcount = 128;

        namespace color {
            const sf::Color accent = sf::Color(12, 12, 12);
            const sf::Color bg = sf::Color(32, 32, 32);
            const sf::Color text = sf::Color(128, 128, 128);
            const sf::Color frame = sf::Color::Black;
        }

        namespace layout {
            const unsigned theight = 15;
            const unsigned bheight = 400;
            const unsigned frame = 1;
            const unsigned x1 = 10;
            const unsigned y1 = 10;
            const float xt = 0.06f;
            const float yt = 0.8f;
        }

        namespace brightness {
            const unsigned bm = 100;
            const unsigned b0 = 100;
            const unsigned coeff = 5;
        }
    }

    namespace except {
        const std::invalid_argument playlist_file("Playlist file not found.");
        const std::invalid_argument playlist_empty("Playlist file empty.");
    }
}

#endif // VISU_CONSTS
