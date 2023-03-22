#include <stdexcept>
#include <string>
#include <list>
#include "ini/inifile.hpp"
#include "ini/section.hpp"
#include "ini/key.hpp"

// auxiliary function prototypes
static const ini::section& find_section(const std::list <ini::section>&, const std::string&);
static const ini::key&     find_key(const ini::section&, const std::string&);

// main function implementation
const std::string& ini::inifile::value(const std::string& section_id, const std::string& key_id) const {
	const ini::section& selected_section = find_section(sections, section_id);
	const ini::key&	    selected_key	 = find_key(selected_section, key_id);

	return selected_key.value();
}

// auxiliary function implementations
static const ini::section& find_section(const std::list <ini::section>& sections, const std::string& section_id) {
	for (auto& index: sections)
		if (index.id() == section_id)
			return index;

	std::out_of_range section_id_error("Invalid section id.");
	throw section_id_error;
}

static const ini::key& find_key(const ini::section& section, const std::string& key_id) {
	for (auto const& index: section.keys())
        	if (index.id() == key_id)
            		return index;

	std::out_of_range key_id_error("Invalid key id.");
	throw key_id_error;
}
