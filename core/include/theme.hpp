#ifndef THEME_HPP
#define THEME_HPP

#include <SFML/Graphics.hpp>
#include "classes.hpp"

namespace sfGUI {
class Theme {
public:
    static Theme& instance() {
        static Theme t;
        return t;
    }
    sf::Font m_theme_font = sf::Font(std::filesystem::path("assets/JetBrainsMonoNerdFontMono-Regular.ttf"));
};
}

#endif // !THEME_HPP
