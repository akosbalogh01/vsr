#ifndef VISU_MAN_PLAYLIST
#define VISU_MAN_PLAYLIST

#include <string>
#include <vector>
#include "parents.hpp"
#include "music.hpp"

namespace vs {
    namespace man {
        class playlist: public player {
        private:
            unsigned current, bufsize;
            std::vector <music> songlist;

        public:
            playlist() = delete;
            playlist(const playlist&) = delete;
            explicit playlist(const vs::t::mptr&, const std::string&);

            void reset();
            void initBuffer(const unsigned);
            void dropBuffer(const unsigned);

            void next(const bool = false);
            void prev(const bool = false);
        };
    }
}

#endif // VISU_PLAYLIST
