#include "bar.hpp"

void vs::bar::setColor(const sf::Color& color) {
    for (unsigned i = 0; i < 4; ++i) {
        quad[i].color = color;
    }
}

const sf::Color& vs::bar::getColor() const {
    return quad[0].color;
}

void vs::bar::setHeight(const unsigned height, const bool filtering) {
    if (height <= vs::gfx::layout::bheight) {
        if (filtering) {
            prev = alpha*prev + (1 - alpha)*height;
            quad[2].position = quad[1].position + sf::Vector2f(0, -1.0f * prev);
            quad[3].position = quad[0].position + sf::Vector2f(0, -1.0f * prev);
            curheight = prev;
        }
        else {
            quad[2].position = quad[1].position + sf::Vector2f(0, -1.0f * height);
            quad[3].position = quad[0].position + sf::Vector2f(0, -1.0f * height);
            curheight = height;
        }
    }
}

unsigned vs::bar::getHeight() const {
    return curheight;
}

void vs::bar::setVertices(const sf::Vector2f& pos, const sf::Vector2f& maxsize) {
    this->maxheight = maxsize.y;

    quad[0].position = pos;
    quad[1].position = pos + sf::Vector2f(maxsize.x, 0);
    quad[2].position = pos + sf::Vector2f(maxsize.x, -maxsize.y);
    quad[3].position = pos + sf::Vector2f(0, -maxsize.y);
}

void vs::bar::setPosition(const sf::Vector2f& pos) {
    int width  = quad[1].position.x - quad[0].position.x;
    int height = quad[3].position.y - quad[0].position.y;

    quad[0].position = pos;
    quad[1].position = pos + sf::Vector2f(width, 0);
    quad[2].position = pos + sf::Vector2f(width, height);
    quad[3].position = pos + sf::Vector2f(0, height);
}

void vs::bar::setWidth(const float width) {
    int cw = quad[1].position.x - quad[0].position.x;
    int dw = ceil(width - cw);

    quad[1].position.x += dw;
    quad[2].position.x += dw;
}

void vs::bar::render() {
    target->draw(quad);
}







