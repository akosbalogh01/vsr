#include <iostream>
#include "metadata.hpp"

const std::string& vs::metadata::getTitle() const {
    return title;
}

const std::string& vs::metadata::getArtist() const {
    return artist;
}

const std::string& vs::metadata::getAlbum() const {
    return album;
}

const std::string& vs::metadata::getGenre() const {
    return genre;
}

const std::string& vs::metadata::getFile() const {
    return filepath;
}

namespace vs {
    std::ostream& operator<<(std::ostream& stream, const vs::metadata& song) {
        stream << "(" << song.getGenre() << ") "<< song.getArtist() << ", " << song.getAlbum() << ": " << song.getTitle();
        return stream;
    }
}
