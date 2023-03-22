#ifndef VISU_MAN_SETTINGS
#define VISU_MAN_SETTINGS

#include <map>
#include <string>
#include "ini/inifile.hpp"

namespace vs {
    namespace man {
        class settings {
            private:
                ini::inifile file;

            public:
                typedef enum {
                    WINWIDTH,
                    WINHEIGHT,
                    WFULLSCREEN,
                    ABUFSIZE,
                    AVOLMAX,
                    AVOL0,
                    AVOLC,
                    COMBAUDRATE,
                    COMBYTESIZE,
                    COMPORTID
                } setlist;

                settings() = delete;
                explicit settings(const std::string&);

                static std::map <setlist, std::string> smap;
        };
    }
}

#endif // VISU_MAN_SETTINGS
