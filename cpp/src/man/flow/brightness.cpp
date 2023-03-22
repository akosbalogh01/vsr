#include "man/flow.hpp"

unsigned vs::man::flow::getBrightness() const {
    if ((current == (cvec.size() - 1)) || (sf::Time(offset - cvec[current].getStamp()).asMilliseconds() <= 32)) {
        return cvec[current].getBrightness();
    }
    else {
        unsigned dt = sf::Time(cvec[current+1].getStamp() - cvec[current].getStamp()).asMilliseconds();
        unsigned xt = sf::Time(offset - cvec[current].getStamp()).asMilliseconds();
        int db = cvec[current+1].getBrightness() - cvec[current].getBrightness();

        float res = ((float) xt/dt)*db;

        return (cvec[current].getBrightness() + res);
    }
}
