#include <iostream>
#include "music.hpp"

void vs::music::init(const vs::music& other) {
    this->meta = other.meta;
}

void vs::music::initBuffer() {
    if (!buffered) {
        std::cout << "Buffering: " << meta << std::endl;
        buffer.loadFromFile(meta.getFile());
        sound.setBuffer(buffer);
        buffered = true;
    }
}

void vs::music::dropBuffer() {
    if (buffered) {
        if (sound.getStatus() == sf::Sound::Playing) {
            sound.stop();
        }
        std::cout << "Dropping: " << meta << std::endl;
        sound.resetBuffer();
        buffer = sf::SoundBuffer();
        buffered = false;
    }
}

std::pair<const sf::Time, const sf::Time> vs::music::getTime() const {
    sf::Time t1 = sound.getPlayingOffset();
    sf::Time t2 = buffer.getDuration();
    std::pair <sf::Time, sf::Time> t(t1, t2);
    return t;
}

bool vs::music::isOver() const {
    return (sound.getStatus() == sf::SoundSource::Stopped);
}

bool vs::music::isBuffered() const {
    return buffered;
}

bool vs::music::copyData(const vs::music& other) {
    meta = other.meta;
    ctrl = other.ctrl;

    if (other.buffered) {
        buffered = true;
        buffer = other.buffer;
        sound.setBuffer(buffer);
        return true;
    }
    else {
        buffered = false;
        dropBuffer();
        return false;
    }
}

void vs::music::setOffset(const sf::Time& offset) {
    if ((offset >= sf::seconds(0)) && (offset <= buffer.getDuration())) {
        sound.setPlayingOffset(offset);
    }
}

void vs::music::play() {
    sound.play();
}

void vs::music::pause() {
    sound.pause();
}

double vs::music::getSampleRate() const {
    return buffer.getSampleRate() * buffer.getChannelCount();
}

unsigned vs::music::getSampleCount() const {
    return buffer.getSampleCount();
}

unsigned vs::music::getChannelCount() const {
    return buffer.getChannelCount();
}

sf::Color vs::music::getBinColor(const unsigned bin) const {
    return ctrl.getBinColor(bin);
}
