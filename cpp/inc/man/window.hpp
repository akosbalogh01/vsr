#ifndef VISU_MAN_WINDOW
#define VISU_MAN_WINDOW

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "man/visualiser.hpp"
#include "parents.hpp"
#include "graphics.hpp"
#include "man/serial.hpp"

namespace vs {
    namespace man {
        class window : public pausable, public player {
        private:
            sf::RenderWindow target;
            graphics gui;
            man::visualiser vman;

        public:
            window() = delete;
            window(const vs::man::window&) = delete;
            explicit window(vs::t::mptr, const std::string&, vs::man::serial* const);

            bool pollEvent(sf::Event&);
            bool isOpen() const;

            void windowClose(const sf::Event&);
            void windowResize(const sf::Event&);

            void setBrightness(const sf::Event&);
            void selectVisualisation(const sf::Event&);
            void toggleVisualisation(const sf::Event&);
            void displayMetadata();

            void render();
            void update();

            std::vector<uint8_t> leds() const;
        };
    }
}

#endif // VISU_WINDOW
