#ifndef VISU_MAN_VISUALISER
#define VISU_MAN_VISUALISER

#include <map>
#include <memory>
#include <SFML/Window/Event.hpp>
#include "parents.hpp"

namespace vs {
    namespace man {
        class visualiser: public renderable, public player {
        public:
            typedef enum {
                GLOW,
                FADE,
                PULSE,
                WAVE,
                RAINBOW,
                FOURIER
            } vtype;

        private:
            bool en;
            vtype current;
            std::map<vtype, std::unique_ptr<vs::visualisable>> vmap;

        public:
            visualiser() = delete;
            visualiser(const visualiser&) = delete;
            explicit visualiser(vs::t::rtarget, vs::t::mptr);

            void update() override;
            void render() override;

            void selectVisualisation(const sf::Event&);
            void toggleEnabled(const sf::Event&);
            const std::vector<uint8_t> leds() const;
        };
    }
}

#endif // VISU_MAN_VISUALISER
