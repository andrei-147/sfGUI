#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "theme.hpp"
#include "transformable.hpp"
#include <SFML/Graphics/Text.hpp>
#include <string>

namespace sfGUI {
class Rectangle : public Transformable {

protected:
    sf::FloatRect m_bounding_box;
    sf::RectangleShape m_surface_rect;
    sf::RectangleShape m_rectangle_w;
    sf::RectangleShape m_rectangle_h;
    sf::CircleShape m_circle_ul;
    sf::CircleShape m_circle_ur;
    sf::CircleShape m_circle_dl;
    sf::CircleShape m_circle_dr;
    sf::Text m_text_label = sf::Text(Theme::instance().m_theme_font);
    float m_radius = 0.0f;
    std::string m_label = "";
    unsigned int m_label_size = 16;
    sf::Color m_label_color = sf::Color::White;

public:
    Rectangle();

    void update() override;
    void draw(sf::RenderWindow&) override;

    void set_radius(float);
    [[nodiscard]] float get_radius() const;

    void set_label(std::string);
    [[nodiscard]] std::string get_label() const;

    void set_label_size(unsigned int);
    [[nodiscard]] unsigned int get_label_size() const;

    void set_label_color(sf::Color);
    [[nodiscard]] sf::Color get_label_color() const;

    sf::FloatRect get_global_bounds() const;
};
}

#endif // !RECTANGLE_HPP
