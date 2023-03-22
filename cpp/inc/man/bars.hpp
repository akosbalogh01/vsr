#ifndef VISU_MAN_BARS
#define VISU_MAN_BARS

#include <vector>
#include "parents.hpp"
#include "bar.hpp"

namespace vs {
    namespace man {
        class bars: public renderable {
        private:
            std::vector <vs::bar> barv;

        public:
            bars() = delete;
            bars(const bars&);
            bars(vs::t::rtarget);
            ~bars();

            void render() override;

            vs::bar& operator[](const unsigned);
            const vs::bar& operator[](const unsigned) const;
        };
    }
}

#endif // VISU_MAN_BARS
