#ifndef VISU_MUSIC
#define VISU_MUSIC

#include <complex>
#include <string>
#include <memory>
#include <SFML/Audio.hpp>
#include "xml/rapidxml.hpp"
#include "man/flow.hpp"
#include "metadata.hpp"

namespace vs {
    class music {
    private:
        unsigned maxvol, curvol, maxbr, curbr;
        bool buffered;
        vs::metadata meta;
        sf::SoundBuffer buffer;
        sf::Sound sound;
        vs::man::flow ctrl;
        void modVolume();
        void modBrightness();

    public:
        music() = delete;
        music(const std::string&);
        music(const std::string&, const rapidxml::xml_node<>*);
        music(const vs::music&);
        music(vs::music&&);
        ~music();

        void init(const vs::music&);
        void initBuffer();
        void dropBuffer();

        const std::string& getTitle() const;
        const std::string& getArtist() const;
        const std::string& getAlbum() const;
        const std::string& getGenre() const;
        const std::string& getFile() const;
        const vs::metadata& getMeta() const;
        std::pair<const sf::Time, const sf::Time> getTime() const;
        std::vector<float> getSamples() const;

        sf::Color getBinColor(const unsigned) const;
        unsigned getMaxBrightness() const;
        unsigned getModBrightness() const;
        unsigned getMaxVolume() const;
        unsigned getModVolume() const;

        double   getSampleRate() const;
        unsigned getSampleCount() const;
        unsigned getChannelCount() const;

        bool isOver() const;
        bool isBuffered() const;
        bool copyData(const vs::music&);

        void setMetadata(const vs::metadata&);
        void setOffset(const sf::Time&);
        void setMaxVolume(const unsigned);
        void setMaxBrightness(const unsigned);
        void play();
        void pause();
        void update();
    };
}

#endif // VISU_MUSIC
