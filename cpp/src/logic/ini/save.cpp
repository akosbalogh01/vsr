#include <stdexcept>
#include <fstream>
#include "ini/inifile.hpp"
#include "ini/section.hpp"
#include "ini/key.hpp"

void ini::inifile::save() const {
    save(var_filepath);
}

void ini::inifile::save(const std::string& filepath) const {
    std::ofstream output;
    output.open(filepath);
    if (output.is_open()) {
        output << *this;
        output.close();
    }
    else {
        std::invalid_argument filepath_error("Invalid filepath.");
        throw filepath_error;
    }
}
