#ifndef VISU_MAN_DEBUG
#define VISU_DEBUG

#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"
#include "parents.hpp"

namespace vs {
    namespace man {
        class debug: public player {
        public:
            typedef enum {
                FRAME = 0,
                EVENT = 1,
                UPDATE = 2,
                RENDER = 3,
                TRANSMIT = 4,
                _SIZE
            } dclock;

        private:
            sf::RenderWindow overlay;
            sf::Font font;
            sf::Text text;
            sf::Clock runtime;
            sf::Time timers[dclock::_SIZE];
            unsigned prev[dclock::_SIZE];

            void drawText(const unsigned x, const unsigned y, const std::string& str);

        public:
            debug() = delete;
            explicit debug(const vs::t::mptr);
            ~debug();

            void closeOverlay();
            void toggleOverlay(const sf::Event&);
            void renderOverlay();

            void signal(const dclock);
        };
    }
}

#endif // VISU_DEBUG
