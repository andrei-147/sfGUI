#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "classes.hpp"

namespace sfGUI {

struct Element_Properties {
    sf::Vector2f position = {0.0f,0.0f};
    sf::Vector2f size = {0.0f, 0.0f};
    sf::Color    color = sf::Color::Black;
    float        margin = 0.0f;
    float        margin_top = 0.0f;
    float        margin_bottom = 0.0f;
    float        margin_left = 0.0f;
    float        margin_right = 0.0f;
};

class Element {

protected:
    virtual Element_Properties& properties() = 0;
    virtual const Element_Properties& properties() const = 0;
    Div* m_div_parent = nullptr;

public:
    Element() = default;
    virtual ~Element() = default;

    virtual void update() {}
    virtual void draw(sf::RenderWindow&) {}

    virtual void set_position(const sf::Vector2f);
    [[nodiscard]] sf::Vector2f get_position() const;

    virtual void set_size(const sf::Vector2f);
    [[nodiscard]] sf::Vector2f get_size() const;

    virtual void set_color(const sf::Color);
    [[nodiscard]] sf::Color get_color() const;

    virtual void set_margin(const float);
    [[nodiscard]] float get_margin() const;

    virtual void set_margins(const float top, const float bottom, const float left, const float right);
    [[nodiscard]] float get_margin_top() const;
    [[nodiscard]] float get_margin_bottom() const;
    [[nodiscard]] float get_margin_left() const;
    [[nodiscard]] float get_margin_right() const;

    void set_parent_div(Div*);
};
}

#endif // ELEMENT_HPP
