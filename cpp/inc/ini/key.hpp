#ifndef INI_KEY
#define INI_KEY
#include <iostream>
#include <string>

namespace ini {
    class key {
    private:
        std::string var_id;
        std::string var_value;

    public:
        key(const std::string&, const std::string&);
        key(const key&);
        ~key();

        const std::string& id() const;
        const std::string& value() const;

        void setID(const std::string&);
        void setValue(const std::string&);

        bool operator== (const ini::key&) const;
        bool operator!= (const ini::key&) const;
        friend std::ostream& operator<< (std::ostream&, const key&);
    };
}

#endif
