#include <stdexcept>
#include <string>
#include <fstream>
#include <list>
#include "ini/inifile.hpp"
#include "ini/section.hpp"
#include "ini/key.hpp"

// auxiliary type definitions and functions
typedef enum {SECTION, KEY, COMMENT, UNDEFINED} line_type;
static line_type type_of(const std::string&);
static inline void new_section(std::list <ini::section>&, const std::string&);
static inline void new_key(ini::section&, const std::string&);

// main function implementation
void ini::inifile::load(const std::string& filepath) {
    var_filepath = filepath;

    std::string line;
    std::ifstream input(filepath);
    if (input.is_open()) {
        while (std::getline(input, line)) {
            switch (type_of(line)) {
                case SECTION:
                    new_section(sections, line);
                    break;

                case KEY:
                    if (sections.size() != 0) new_key(sections.back(), line);
                    else {
                        std::invalid_argument corrupt_file_error("Inifile '" + var_filepath + "' is corrupted.");
                        throw corrupt_file_error;
                    }
                    break;

				case COMMENT:
					//to do
					break;


				case UNDEFINED:
					//to do
					break;
            }
        }

        input.close();
    }
    else {
        std::invalid_argument filepath_error("Invalid filepath.");
        throw filepath_error;
    }
}

// auxiliary function implementations
static line_type type_of(const std::string& param) {
    if (param.front() == '[' && param.back() == ']') return SECTION;
    else if (param.find('=') != std::string::npos) return KEY;
    else if (param.front() == '#') return COMMENT;
    else return UNDEFINED;
}

static inline void new_section(std::list <ini::section>& sections, const std::string& line) {
    std::string new_section_id = line.substr(1, line.length() - 2);
    ini::section* new_section = new ini::section(new_section_id);

    sections.push_back(*new_section);
}

static inline void new_key(ini::section& section, const std::string& line) {
    std::size_t equation_pos = line.find('=');

    std::string new_key_id      = line.substr(0, equation_pos);
    std::string new_key_val     = line.substr(equation_pos + 1, std::string::npos);

    section.addKey(new_key_id, new_key_val);
}
