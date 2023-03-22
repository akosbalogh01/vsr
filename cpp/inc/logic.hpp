#ifndef VISU_LOGIC
#define VISU_LOGIC

#include <vector>
#include "man/settings.hpp"
#include "man/window.hpp"
#include "man/audio.hpp"
#include "man/event.hpp"
#include "man/serial.hpp"
#include "man/debug.hpp"
#include "parents.hpp"
#include "music.hpp"

namespace vs {
    class logic: public pausable, public player {
    private:
        bool started;
        man::settings sman;
        man::window   wman;
        man::event    eman;
        man::audio    aman;
        man::serial   tman;
        man::debug    dman;

    public:
        logic() = delete;
        logic(const logic&) = delete;
        explicit logic(const int, const char**, vs::t::mptr);

        bool isRunning() const;

        bool pollEvent(sf::Event&);
        void procEvent(const sf::Event&);

        void eventTimestamp(const sf::Event&);
        void eventPaused(const sf::Event&);
        void togglePaused();

        void update();
        void render();
    };
}

#endif // VISU_LOGIC
