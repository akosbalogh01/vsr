#include "metadata.hpp"
#include "graphics.hpp"
#include "man/settings.hpp"

/*
    Internal (private) graphical object functions
*/

void vs::graphics::drawText(const std::string& str, const sf::Vector2f& pos, const unsigned size) {
    text.setString(str);
    text.setPosition(pos);
    text.setCharacterSize(size);

    target->draw(text);
}

void vs::graphics::drawTextCentered(const std::string& str, const sf::Vector2f& pos, const unsigned size) {
    text.setString(str);
    text.setCharacterSize(size);
    sf::FloatRect bounds = text.getGlobalBounds();
    text.setOrigin((unsigned) bounds.width/2, (unsigned) bounds.height/2);
    text.setPosition(pos);

    target->draw(text);
    text.setOrigin(0, 0);
}

void vs::graphics::drawRect(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color) {
    rect.setFillColor(color);
    rect.setSize(size);
    rect.setPosition(pos);
    rect.setOutlineThickness(vs::gfx::layout::frame);
    rect.setOutlineColor(vs::gfx::color::frame);

    target->draw(rect);
}

void vs::graphics::drawMetadata() {
    if (mtimer.getElapsedTime() < sf::seconds(5)) {
        vs::metadata song = playing->getMeta();
        const std::string str = "(" + song.getGenre() + ") " + song.getArtist() + ", " + song.getAlbum() + ": " + song.getTitle();
        drawRect(sf::Vector2f((unsigned) wsize.x * vs::gfx::layout::xt, 0), sf::Vector2f(wsize.x - 2 * ((unsigned) wsize.x * vs::gfx::layout::xt), 50), vs::gfx::color::bg);
        drawText(str, sf::Vector2f((unsigned) wsize.x * vs::gfx::layout::xt + 25, 5), 30);
    }
}

static inline std::string toString(const sf::Time& time) {
    char buf[10];
    unsigned m = time.asSeconds()/60;
    unsigned s = ((int) time.asSeconds()) % 60;

    sprintf(buf, "%d:%02d", m, s);
    return std::string(buf);
}

void vs::graphics::drawTimedata() {
    float xoff = (float) wsize.x * vs::gfx::layout::xt;
    float yoff = (float) wsize.y * vs::gfx::layout::yt;
    sf::Time t1 = playing->getTime().first;
    sf::Time t2 = playing->getTime().second;
    drawTextCentered(toString(t1), sf::Vector2f(floor(xoff/2), floor(yoff)), 25);
    drawTextCentered(toString(t2), sf::Vector2f(floor(wsize.x - xoff/2), floor(yoff)), 25);
    drawRect(sf::Vector2f(xoff, yoff), sf::Vector2f(wsize.x - 2*xoff, vs::gfx::layout::theight), vs::gfx::color::bg);
    drawRect(
        sf::Vector2f(xoff + 2 * vs::gfx::layout::frame, yoff + 2 * vs::gfx::layout::frame),
        sf::Vector2f((wsize.x - 2 * (xoff + 2 * vs::gfx::layout::frame)) * ((double) t1.asSeconds()/t2.asSeconds()), vs::gfx::layout::theight - 4 * vs::gfx::layout::frame),
        vs::gfx::color::accent
    );
}

void vs::graphics::drawCom() {
    float xoff =  (float) (wsize.x - vs::gfx::layout::x1) * vs::gfx::layout::xt;
    float yoff =  (float) (wsize.y - vs::gfx::layout::y1) * vs::gfx::layout::yt;
    float y    = ((float) (wsize.y - vs::gfx::layout::y1) - yoff)/2 + yoff;

    text.setString(vs::man::settings::smap[vs::man::settings::COMPORTID]);
    text.setCharacterSize(20);
    sf::FloatRect bounds = text.getGlobalBounds();
    text.setOrigin(0, (unsigned) bounds.height/2);
    text.setPosition(sf::Vector2f(xoff, y));
    if (sman->enabled()) {
        text.setFillColor(sf::Color::Green);
    }
    else {
        text.setFillColor(sf::Color::Red);
    }

    target->draw(text);
    text.setFillColor(vs::gfx::color::text);
}
