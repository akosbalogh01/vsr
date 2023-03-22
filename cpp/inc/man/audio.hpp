#ifndef VISU_MAN_AUDIO
#define VISU_MAN_AUDIO

#include <vector>
#include <string>
#include "SFML/Window/Event.hpp"
#include "SFML/Audio.hpp"
#include "man/playlist.hpp"
#include "parents.hpp"

namespace vs {
    namespace man {
        class audio: public pausable, public player {
        private:
            unsigned vcoef;
            bool autoplay;
            man::playlist pman;

        public:
            audio() = delete;
            audio(const audio&) = delete;
            explicit audio(vs::t::mptr, const std::string&);

            void eventPaused(const sf::Event&);
            void togglePaused();
            void setMaxVolume(const sf::Event&);
            void setMaxBrightness(const sf::Event&);
            void toggleAutoplay(const sf::Event&);
            void eventPrevSong(const sf::Event&);
            void prevSong();
            void eventNextSong(const sf::Event&);
            void nextSong();
            void jumpBack(const sf::Event&);
            void jumpForward(const sf::Event&);
            void stopPlayback();

            bool getAutoplay() const;
        };
    }
}

#endif // VISU_AUDIO
