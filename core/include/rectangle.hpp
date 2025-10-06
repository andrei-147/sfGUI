#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "theme.hpp"
#include "transformable.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

namespace sfGUI {
struct Rectangle_Properties : public Transformable_Properties {
    float        radius = 0.0f;
    std::string  label = "";
    sf::Color    label_color = sf::Color::Black;
    unsigned int label_size = 0;
};

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
private:
    Rectangle_Properties m_properties = Rectangle_Properties();

    void update_position();
    void update_radius();

public:
    Rectangle();

    void update() override;
    void draw(sf::RenderWindow&) override;

    void set_position(const sf::Vector2f) override;
    void set_size(const sf::Vector2f) override;
    void set_color(const sf::Color) override;
    void set_margin(const float) override;
    void set_margins(const float, const float, const float, const float) override;

    void set_rotation(const float) override;
    void set_origin(const sf::Vector2f) override;
    void set_scaling(const sf::Vector2f) override;

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
