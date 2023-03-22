#include "music.hpp"

const std::string& vs::music::getTitle() const {
    return meta.getTitle();
}

const std::string& vs::music::getArtist() const {
    return meta.getArtist();
}

const std::string& vs::music::getAlbum() const {
    return meta.getAlbum();
}

const std::string& vs::music::getGenre() const {
    return meta.getGenre();
}

const std::string& vs::music::getFile() const {
    return meta.getFile();
}

const vs::metadata& vs::music::getMeta() const {
    return meta;
}

void vs::music::setMetadata(const vs::metadata& meta) {
    dropBuffer();
    this->meta = meta;
}
