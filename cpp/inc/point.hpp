#ifndef VISU_CTRLPOINT
#define VISU_CTRLPOINT

#include <vector>
#include <memory>
#include "xml/rapidxml.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Color.hpp"

namespace vs {
    class point {
    private:
        unsigned stamp, volume, brightness;
        std::vector <sf::Color> bins;

    public:
        point(const rapidxml::xml_node<>* = NULL);

        sf::Time getStamp() const;
        unsigned getVolume() const;
        unsigned getBrightness() const;
        sf::Color getBinColor(const unsigned) const;

        void setStamp(const sf::Time&);
    };
}

#endif // VISU_CTRLPOINT
