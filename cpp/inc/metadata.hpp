#ifndef VISU_META
#define VISU_META

#include <string>
#include <iostream>

namespace vs {
    class metadata {
    private:
        std::string filepath;
        std::string title;
        std::string artist;
        std::string album;
        std::string genre;

    public:
        metadata() = delete;
        explicit metadata(const std::string&);

        const std::string& getTitle() const;
        const std::string& getArtist() const;
        const std::string& getAlbum() const;
        const std::string& getGenre() const;
        const std::string& getFile() const;

        friend std::ostream& operator<< (std::ostream&, const vs::metadata&);
    };
}

#endif //VISU_META
