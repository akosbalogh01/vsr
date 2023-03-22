#include "man/flow.hpp"

void vs::man::flow::update(const sf::Time& t) {
    offset = t;

    int ctrl = -1;
    for (unsigned i = 0; i < cvec.size(); ++i) {
        if (t >= cvec[i].getStamp()) {
            ++ctrl;
        }
        else break;
    }

    current = ctrl;
}
