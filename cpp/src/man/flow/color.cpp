#include "man/flow.hpp"

sf::Color vs::man::flow::getBinColor(const unsigned bin) const {
    if ((current == (cvec.size() - 1)) || (sf::Time(offset - cvec[current].getStamp()).asMilliseconds() <= 32)) {
        return cvec[current].getBinColor(bin);
    }
    else {
        unsigned dt = sf::Time(cvec[current+1].getStamp() - cvec[current].getStamp()).asMilliseconds();
        unsigned xt = sf::Time(offset - cvec[current].getStamp()).asMilliseconds();
        sf::Color nc = cvec[current+1].getBinColor(bin);
        sf::Color pc = cvec[current].getBinColor(bin);
        float dr = ((float) nc.r - pc.r)/dt;
        float dg = ((float) nc.g - pc.g)/dt;
        float db = ((float) nc.b - pc.b)/dt;
        float da = ((float) nc.a - pc.a)/dt;

        unsigned nr = pc.r + xt*dr;
        unsigned ng = pc.g + xt*dg;
        unsigned nb = pc.b + xt*db;
        unsigned na = pc.a + xt*da;
        return sf::Color(nr, ng, nb, na);
    }
}
