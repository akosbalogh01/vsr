#include <iostream>
#include <string>
#include "ini/key.hpp"

ini::key::key(const std::string& param_key_id, const std::string& param_key_val) {
    var_id      = param_key_id;
    var_value   = param_key_val;
}

ini::key::key(const ini::key& param) {
    this->var_id    = param.var_id;
    this->var_value = param.var_value;
}

ini::key::~key() {
    var_id.clear();
    var_value.clear();
}

const std::string& ini::key::id() const {
    return var_id;
}

const std::string& ini::key::value() const {
    return var_value;
}

void ini::key::setID(const std::string& param) {
    var_id = param;
}

void ini::key::setValue(const std::string& param) {
    var_value = param;
}

bool ini::key::operator!= (const ini::key& param) const {
    return !(*this == param);
}

bool ini::key::operator== (const ini::key& param) const {
    if (this->id()    != param.id())    return false;
    if (this->value() != param.value()) return false;
    return true;
}

namespace ini {
    std::ostream& operator<< (std::ostream& output_stream, const ini::key& param) {
        output_stream << param.var_id << '=' << param.var_value;
        return output_stream;
    }
}
