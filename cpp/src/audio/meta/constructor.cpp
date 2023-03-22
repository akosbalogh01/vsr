#include <fstream>
#include <iostream>
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include "metadata.hpp"

vs::metadata::metadata(const std::string& filepath) {
    std::ifstream f(filepath);
    if (f.good()) {
        f.close();

        TagLib::FileRef f(filepath.c_str());
        TagLib::Tag* tag = f.tag();

        this->filepath = filepath;
        title = std::string(tag->title().toCString());
        artist = std::string(tag->artist().toCString());
        album = std::string(tag->album().toCString());
        genre = std::string(tag->genre().toCString());

        std::cout << "Parsed song: " << *this << std::endl;
    }
    else {
        this->filepath = filepath;
    }
}
