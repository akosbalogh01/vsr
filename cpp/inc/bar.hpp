#ifndef VISU_BAR
#define VISU_BAR

#include "SFML/Graphics.hpp"
#include "parents.hpp"

namespace vs {
    class bar : public renderable {
    private:
        unsigned maxheight, curheight;
        sf::VertexArray quad;
        float prev;
        const float alpha = 0.95f;

    public:
        bar() = delete;
        bar(const bar&);
        bar(const bar&&);
        bar(vs::t::rtarget const);

        void setColor(const sf::Color&);
        void setHeight(const unsigned, const bool = true);
        void setVertices(const sf::Vector2f&, const sf::Vector2f&);
        void setPosition(const sf::Vector2f&);
        void setWidth(const float width);

        const sf::Color& getColor() const;
        unsigned getHeight() const;
        void render() override;
    };
}

#endif // VISU_BAR
