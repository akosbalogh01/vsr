#include "consts.hpp"
#include "man/settings.hpp"
#include "man/bars.hpp"

vs::man::bars::bars(const vs::man::bars& other): renderable(other.target) {
    for (auto ob: other.barv) {
        barv.push_back(ob);
    }
}

vs::man::bars::bars(vs::t::rtarget w): renderable(w) {
    barv = std::vector<vs::bar>(vs::gfx::ledcount, vs::bar(w));

    for (unsigned i = 0; i < vs::gfx::ledcount; ++i) {
        barv[i].setColor(vs::gfx::color::bg);
    }
}

vs::man::bars::~bars() {

}
