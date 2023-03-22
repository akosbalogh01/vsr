#include <stdexcept>
#include <iostream>
#include <string>
#include <list>
#include "ini/section.hpp"
#include "ini/key.hpp"

// auxiliary functions
inline void unkown_key(const std::string& key_id) {
    std::invalid_argument unkown_key("Key '" + key_id + "' not defined.");
    throw unkown_key;
}

ini::section::section(const std::string& section_id) {
    var_id = section_id;
}

const std::string& ini::section::id() const {
	return var_id;
}

const std::list<ini::key>& ini::section::keys() const {
    return list_keys;
}

void ini::section::addKey(const std::string& param_key_id, const std::string& param_key_val) {
    ini::key* new_key = new ini::key(param_key_id, param_key_val);
    list_keys.push_back(*new_key);
}

void ini::section::setID(const std::string& new_id) {
    var_id = new_id;
}

void ini::section::delKey(const std::string& key_id) {
    for (auto& key_index: list_keys) {
        if (key_index.id() == key_id) {
            list_keys.remove(key_index);
            return;
        }
    }

    unkown_key(key_id);
}

void ini::section::modKeyID(const std::string& old_key_id, const std::string& new_key_id) {
    for (auto& key_index: list_keys) {
        if (key_index.id() == old_key_id) {
            key_index.setID(new_key_id);
            return;
        }
    }

    unkown_key(old_key_id);
}

void ini::section::modKeyValue(const std::string& key_id, const std::string& new_value) {
    for (auto& key_index: list_keys) {
        if (key_index.id() == key_id) {
            key_index.setValue(new_value);
            return;
        }
    }

    unkown_key(key_id);
}

bool ini::section::operator== (const ini::section& param) {
    if (this->list_keys.size() != param.list_keys.size()) return false;


    for (std::list <ini::key>::const_iterator v_index = this->list_keys.begin(), p_index = param.list_keys.begin(); v_index != list_keys.end(); ++v_index, ++p_index)
        if (*v_index != *p_index) return false;


    return true;
}

namespace ini {
    std::ostream& operator<< (std::ostream& output_stream, const ini::section& param) {
        output_stream << '[' << param.var_id << ']' << std::endl;

        for (auto const& i: param.list_keys) {
            output_stream << i << std::endl;
        }

        return output_stream;
    }
}
