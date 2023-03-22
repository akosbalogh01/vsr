#include "man/flow.hpp"

unsigned vs::man::flow::getVolume() const {
    if ((current == (cvec.size() - 1)) || (sf::Time(offset - cvec[current].getStamp()).asMilliseconds() <= 32)) {
        return cvec[current].getVolume();
    }
    else {
        unsigned dt = sf::Time(cvec[current+1].getStamp() - cvec[current].getStamp()).asMilliseconds();
        unsigned xt = sf::Time(offset - cvec[current].getStamp()).asMilliseconds();
        int dv = cvec[current+1].getVolume() - cvec[current].getVolume();
        return cvec[current].getVolume() + dv * ((double)xt/dt);
    }
}
