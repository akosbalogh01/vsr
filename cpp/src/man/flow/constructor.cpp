#include "man/flow.hpp"

vs::man::flow::flow() {
    cvec.push_back(vs::point());
}

vs::man::flow::flow(const rapidxml::xml_node<>* root) {
    for (const rapidxml::xml_node<>* p = root; p; p = p->next_sibling()) {
        cvec.push_back(vs::point(p));
    }

    if (cvec.size() == 0) {
        assert(0);
    }

    if (cvec[0].getStamp() != sf::milliseconds(0)) {
        vs::point p0 = cvec[0];
        p0.setStamp(sf::milliseconds(0));
        cvec.insert(cvec.begin(), p0);
    }

    current = 0;
}
