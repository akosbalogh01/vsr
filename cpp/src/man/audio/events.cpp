#include <iostream>
#include "man/audio.hpp"

void vs::man::audio::eventNextSong(const sf::Event& event) {
    if (event.key.code == sf::Keyboard::Right) {
        nextSong();
    }
}

void vs::man::audio::eventPrevSong(const sf::Event& event) {
    if (event.key.code == sf::Keyboard::Left) {
        prevSong();
    }
}

void vs::man::audio::jumpBack(const sf::Event& event) {
    if (event.key.code == sf::Keyboard::Left) {
        std::cout << "Jump back 10 sec" << std::endl;
        sf::Time t1 = playing->getTime().first;
        if (t1 - sf::seconds(10) > sf::seconds(0)) {
            playing->setOffset(t1 - sf::seconds(10));
        }
        else {
            playing->setOffset(sf::seconds(0));
        }
    }
}

void vs::man::audio::jumpForward(const sf::Event& event) {
    if (event.key.code == sf::Keyboard::Right) {
        std::cout << "Jump forward 10 sec" << std::endl;
        sf::Time t1 = playing->getTime().first;
        sf::Time t2 = playing->getTime().second;
        if (t1 + sf::seconds(10) < t2) {
            playing->setOffset(t1 + sf::seconds(10));
        }
    }
}

void vs::man::audio::toggleAutoplay(const sf::Event& event) {
    if (event.key.code == sf::Keyboard::Space) {
        if (autoplay) {
            std::cout << "Autoplay disabled"  << std::endl;
            autoplay = false;
        }
        else {
            std::cout << "Autoplay enabled"  << std::endl;
            autoplay = true;
        }
    }
}
