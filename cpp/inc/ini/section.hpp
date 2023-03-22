#ifndef INI_SECTION
#define INI_SECTION
#include <iostream>
#include <list>
#include <string>
#include "key.hpp"

namespace ini {
    class section {
    private:
        std::string var_id;
        std::list <key> list_keys;

    public:
        explicit section(const std::string&);

	const std::string& id() const;
	const std::list <ini::key>& keys() const;

        void setID(const std::string&);
        void addKey(const std::string&, const std::string&);
        void delKey(const std::string&);
        void modKeyID(const std::string&, const std::string&);
        void modKeyValue(const std::string&, const std::string&);
        bool operator== (const ini::section&);
        friend std::ostream& operator<< (std::ostream&, const section&);
    };
}

#endif
