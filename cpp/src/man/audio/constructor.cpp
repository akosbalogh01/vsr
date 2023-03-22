#include "man/settings.hpp"
#include "man/audio.hpp"

vs::man::audio::audio(vs::t::mptr m, const std::string& xmlpath): player(m), pman(m, xmlpath)  {
    vcoef = std::stoi(vs::man::settings::smap[vs::man::settings::AVOLC]);
    paused = true;
    autoplay = true;
}
