#include <stdexcept>
#include <iostream>
#include "ini/inifile.hpp"
#include "ini/section.hpp"
#include "ini/key.hpp"

ini::inifile::inifile() {
    sections.clear();
}

ini::inifile::inifile(const std::string& filepath) {
    load(filepath);
}

ini::inifile::inifile(const ini::inifile& other) {
    load(other.filepath());
}

ini::inifile::~inifile() {
    save();
}

const std::string& ini::inifile::filepath() const {
    return var_filepath;
}

void ini::inifile::addSection(const std::string& new_section_id) {
    ini::section* new_section = new ini::section(new_section_id);
    sections.push_back(*new_section);
}

inline void unkown_section(const std::string& section_id) {
    std::invalid_argument unkown_section("Section '" + section_id + "' not defined.");
    throw unkown_section;
}

void ini::inifile::modSectionID(const std::string& old_section_id, const std::string& new_section_id) {
    for (auto& index: sections) {
        if (index.id() == old_section_id) {
            index.setID(new_section_id);
            return;
        }
    }

    unkown_section(old_section_id);
}

void ini::inifile::delSection(const std::string& section_id) {
    for (auto& index: sections) {
        if (index.id() == section_id) {
            sections.remove(index);
            return;
        }
    }

    unkown_section(section_id);
}

void ini::inifile::addKey(const std::string& section_id, const std::string& new_key_id, const std::string& new_key_value) {
    for (auto& section_index: sections) {
        if (section_index.id() == section_id) {
            section_index.addKey(new_key_id, new_key_value);
            return;
        }
    }

    addSection(section_id);
    auto& last_section = sections.back();
    last_section.addKey(new_key_id, new_key_value);
}

void ini::inifile::modKeyID(const std::string& section_id, const std::string& old_key_id, const std::string& new_key_id) {
    for (auto& section_index: sections) {
        if (section_index.id() == section_id) {
            section_index.modKeyID(old_key_id, new_key_id);
            return;
	}
    }

    unkown_section(section_id);
}

void ini::inifile::modKeyValue(const std::string& section_id, const std::string& key_id, const std::string& new_value) {
    for (auto& section_index: sections) {
        if (section_index.id() == section_id) {
            section_index.modKeyValue(key_id, new_value);
            return;
        }
    }

    unkown_section(section_id);
}

void ini::inifile::delKey(const std::string& section_id, const std::string& key_id) {
   for (auto& section_index: sections) {
       if (section_index.id() == section_id) {
           section_index.delKey(key_id);
           return;
       }
   }

    unkown_section(section_id);
}

namespace ini {
    std::ostream& operator<< (std::ostream& output_stream, const ini::inifile& param) {
        for (auto const& i: param.sections) {
            output_stream << i << std::endl;
        }

        return output_stream;
    }
}
