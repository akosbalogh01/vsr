#include <string>
#include <iostream>
#include "graphics.hpp"
#include "point.hpp"

sf::Color rgba(const std::string& str) {
    unsigned r, g, b, a;
    sscanf(str.c_str(), "RGBA(%d, %d, %d, %d)", &r, &g, &b, &a);
    return sf::Color(r, g, b, a);
}

vs::point::point(const rapidxml::xml_node<>* root) {
    if (root != NULL) {
        stamp = std::stoi(root->first_attribute("timestamp")->value());
        volume = std::stoi(root->first_attribute("volume")->value());
        brightness = std::stoi(root->first_attribute("brightness")->value());

        rapidxml::xml_node<>* bin = root->first_node("bin");
        sf::Color prevclr = sf::Color::White;
        while (bin != NULL) {
            unsigned i = std::stoi(bin->first_attribute("index")->value());
            sf::Color color = rgba(bin->first_attribute("color")->value());

            if (bins.size() == 0) {
                for (unsigned j = 0; j <= i; ++j) bins.push_back(color);
            }
            else {
                unsigned dw = i - bins.size();
                double dr = ((double) color.r - prevclr.r)/dw;
                double dg = ((double) color.g - prevclr.g)/dw;
                double db = ((double) color.b - prevclr.b)/dw;
                double da = ((double) color.a - prevclr.a)/dw;

                for (unsigned j = 0; j < dw; ++j) {
                    unsigned nr = prevclr.r + (j * dr);
                    unsigned ng = prevclr.g + (j * dg);
                    unsigned nb = prevclr.b + (j * db);
                    unsigned na = prevclr.a + (j * da);
                    bins.push_back(sf::Color(nr, ng, nb, na));
                }
            }

            prevclr = color;
            bin = bin->next_sibling();
        }

        while (bins.size() < vs::gfx::ledcount) {
            bins.push_back(prevclr);
        }
    }
    else {
        stamp = 0;
        volume = 100;
        brightness = 100;
        for (unsigned i = 0; i < vs::gfx::ledcount; ++i) bins.push_back(sf::Color::White);
    }
}
