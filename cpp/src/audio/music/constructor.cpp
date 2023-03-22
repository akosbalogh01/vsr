#include "man/settings.hpp"
#include "consts.hpp"
#include "music.hpp"

vs::music::music(const std::string& fpath): meta(fpath) {
    using namespace vs::man;
    maxvol = 100;//std::stoi(settings::smap[settings::AVOLMAX]);
    curvol = 10;//std::stoi(settings::smap[settings::AVOL0]);
    maxbr = vs::gfx::brightness::bm;
    curbr = vs::gfx::brightness::b0;
    sound.setVolume(curvol);

    buffered = false;
}

vs::music::music(const std::string& fpath, const rapidxml::xml_node<>* root): meta(fpath), ctrl(root) {
    using namespace vs::man;
    maxvol = std::stoi(settings::smap[settings::AVOLMAX]);
    curvol = std::stoi(settings::smap[settings::AVOL0]);
    maxbr = vs::gfx::brightness::bm;
    curbr = vs::gfx::brightness::b0;
    sound.setVolume(curvol);

    buffered = false;
}

vs::music::music(const vs::music& other): meta(other.meta) {
    buffered = false;
    maxvol = other.maxvol;
    curvol = other.curvol;
    maxbr = other.maxbr;
    curbr = other.curbr;
    this->buffer = sf::SoundBuffer();
    this->sound = sf::Sound();
    this->ctrl = other.ctrl;
}

vs::music::music(vs::music&& other): meta(other.meta) {
    maxvol = other.maxvol;
    curvol = other.curvol;
    maxbr = other.maxbr;
    curbr = other.curbr;
    buffered = false;
    this->ctrl = other.ctrl;
}

vs::music::~music() {
    dropBuffer();
}
