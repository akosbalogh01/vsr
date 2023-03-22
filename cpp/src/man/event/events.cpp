#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "man/event.hpp"

void vs::man::event::add(const sf::Event::EventType type, const fpair& functions) {
    eventmap.insert(std::pair<sf::Event::EventType, fpair>(type, functions));
}

void vs::man::event::exec(const sf::Event event) {
    std::pair <emap::iterator, emap::iterator> match;
    match = eventmap.equal_range(event.type);

    for (emap::iterator i = match.first; i != match.second; ++i) {
        fpair f = i->second;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            f.second(event);
        } else {
            f.first(event);
        }
    }
}

/*
void vs::man::event::exec(const sf::Event event) {
    std::pair <emap::iterator, emap::iterator> match;
    match = eventmap.equal_range(event.type);

    for (emap::iterator i = match.first; i != match.second; ++i) {
        efun f;
        fpair f 2= i->second;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            f = (*i).second.second;
        } else {
            f = (*i).second.first;
        }

        f(event);
    }
}

void vs::man::event::exec(const sf::Event event) {
    std::pair <emap::iterator, emap::iterator> match;
    match = eventmap.equal_range(event.type);

    for (emap::iterator i = match.first; i != match.second; ++i) {
        const efun f = (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) ? ((*i).second.second) : ((*i).second.first);
        f(event);
    }
}
*/
