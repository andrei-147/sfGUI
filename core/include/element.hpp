#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <SFML/Graphics.hpp>
#include "classes.hpp"

namespace sfGUI {
class Element {

protected:
    sf::Vector2f m_position;            // relative position to parent div
    sf::Vector2f m_size;
    sf::Color    m_color;
    float        m_margin = 0;
    float        m_margin_top = 0;      // override for m_margin
    float        m_margin_bottom = 0;   // override for m_margin
    float        m_margin_left = 0;     // override for m_margin
    float        m_margin_right = 0;    // override for m_margin
    Div*         m_div_parent = nullptr;

public:
    Element() = default;
    ~Element() = default;

    virtual void update() {}
    virtual void draw(sf::RenderWindow&) {}

    void set_position(const sf::Vector2f);
    [[nodiscard]] sf::Vector2f get_position() const;

    void set_size(const sf::Vector2f);
    [[nodiscard]] sf::Vector2f get_size() const;

    void set_color(const sf::Color);
    [[nodiscard]] sf::Color get_color() const;

    void set_margin(const float);
    [[nodiscard]] float get_margin() const;

    void set_margins(const float, const float, const float, const float);
    [[nodiscard]] float get_margin_top() const;
    [[nodiscard]] float get_margin_bottom() const;
    [[nodiscard]] float get_margin_left() const;
    [[nodiscard]] float get_margin_right() const;

    void set_parent_div(Div*);
};
}

#endif // ELEMENT_HPP
