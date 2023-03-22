#ifndef INI_INIFILE
#define INI_INIFILE
#include <iostream>
#include <string>
#include <list>
#include "section.hpp"

namespace ini {
    class inifile {
    private:
        std::string var_filepath;
        std::list <ini::section> sections;

    public:
        inifile();
        inifile(const std::string&);
        inifile(const inifile&);
        ~inifile();

        void load(const std::string&);
        void save() const;
        void save(const std::string&) const;

        const std::string& filepath() const;
        const std::string& value(const std::string&, const std::string&) const;

        void addSection(const std::string&);
        void modSectionID(const std::string&, const std::string&);
        void delSection(const std::string&);
        void addKey(const std::string&, const std::string&, const std::string&);
        void modKeyID(const std::string&, const std::string&, const std::string&);
        void modKeyValue(const std::string&, const std::string&, const std::string&);
		void delKey(const std::string&, const std::string&);

        friend std::ostream& operator<< (std::ostream&, const inifile&);
    };
}

#endif
