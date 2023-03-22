#ifndef VISU_MAN_FLOW
#define VISU_MAN_FLOW

#include <vector>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Time.hpp>
#include "point.hpp"

namespace vs {
    namespace man {
        class flow {
        private:
            sf::Time offset;
            unsigned current;
            std::vector <vs::point> cvec;

        public:
            flow();
            flow(const rapidxml::xml_node<>*);

            float getLambda() const;
            unsigned getVolume() const;
            unsigned getBrightness() const;
            sf::Color getBinColor(const unsigned) const;

            void update(const sf::Time&);
        };
    }
}

#endif // VISU_MAN_FLOW
