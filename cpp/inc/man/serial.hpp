#ifndef VISU_MAN_SERIAL
#define VISU_MAN_SERIAL
#include <windows.h>
#include <vector>
#include <SFML/Window/Event.hpp>

namespace vs {
    namespace man {
        class serial {
        private:
            HANDLE shandle;
            bool en;

        public:
            serial();
            ~serial();

            void init();
            void transmit(const uint8_t*, const unsigned);
            void transmit(const std::vector<uint8_t>&);
            void disable();
            bool enabled();

            void toggleEnabled(const sf::Event&);
        };
    }
}

#endif // VISU_MAN_SERIAL
