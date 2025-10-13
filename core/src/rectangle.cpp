#include "rectangle.hpp"
#include "div.hpp"
#include "theme.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <print>

namespace sfGUI {
Rectangle::Rectangle() {}
Rectangle::~Rectangle() {}

const Element_Properties& Rectangle::properties() const {
    return static_cast<const Element_Properties&>(m_properties);
}

const Transformable_Properties& Rectangle::transformable_properties() const {
    return m_properties;
}

Element_Properties& Rectangle::properties() {
    return static_cast<Element_Properties&>(m_properties);
}

Transformable_Properties& Rectangle::transformable_properties() {
    return m_properties;
}

void Rectangle::update() {
    sf::Vector2f actual_pos = m_properties.position + m_div_parent->get_position() + sf::Vector2f({m_properties.margin + m_properties.margin_left, m_properties.margin + m_properties.margin_top});
    sf::Vector2f actual_size = m_properties.size - sf::Vector2f({2 * m_properties.margin + m_properties.margin_top + m_properties.margin_bottom, 2 * m_properties.margin + m_properties.margin_left + m_properties.margin_right});
    m_bounding_box = sf::FloatRect(actual_pos, actual_size);

    m_rectangle_h.setPosition(actual_pos);
    m_rectangle_w.setPosition(actual_pos);
    m_circle_ul.setPosition(actual_pos);
    m_circle_dl.setPosition(actual_pos);
    m_circle_ur.setPosition(actual_pos);
    m_circle_dr.setPosition(actual_pos);
    m_text_label.setPosition(actual_pos);
    m_text_label.setFont(sfGUI::Theme::instance().m_theme_font);

    m_circle_dl.setOrigin(m_properties.origin + sf::Vector2f({0, m_properties.radius * 2 - actual_size.y}));
    m_circle_ur.setOrigin(m_properties.origin + sf::Vector2f({m_properties.radius * 2 - actual_size.x, 0}));
    m_circle_dr.setOrigin(m_properties.origin + sf::Vector2f({m_properties.radius * 2, m_properties.radius * 2}) - actual_size);
    m_rectangle_h.setOrigin(m_properties.origin + sf::Vector2f({-m_properties.radius, 0}));
    m_rectangle_w.setOrigin(m_properties.origin + sf::Vector2f({0, -m_properties.radius}));
    m_text_label.setOrigin(m_properties.origin + sf::Vector2f({-m_properties.radius, -m_properties.radius}));

    m_circle_dl.setRadius(m_properties.radius);
    m_circle_dr.setRadius(m_properties.radius);
    m_circle_ul.setRadius(m_properties.radius);
    m_circle_ur.setRadius(m_properties.radius);
    m_rectangle_h.setSize(actual_size - sf::Vector2f({m_properties.radius * 2, 0}));
    m_rectangle_w.setSize(actual_size - sf::Vector2f({0, m_properties.radius * 2}));

    m_rectangle_h.setFillColor(m_properties.color);
    m_rectangle_w.setFillColor(m_properties.color);
    m_circle_dl.setFillColor(m_properties.color);
    m_circle_dr.setFillColor(m_properties.color);
    m_circle_ul.setFillColor(m_properties.color);
    m_circle_ur.setFillColor(m_properties.color);

    sf::Vector2f margin_scale = {(actual_size.x / m_properties.size.x) * m_properties.scale.x, (actual_size.y / m_properties.size.y) * m_properties.scale.y};

    m_rectangle_h.setScale(margin_scale);
    m_rectangle_w.setScale(margin_scale);
    m_circle_dl.setScale(margin_scale);
    m_circle_dr.setScale(margin_scale);
    m_circle_ul.setScale(margin_scale);
    m_circle_ur.setScale(margin_scale);
    m_text_label.setScale(margin_scale);

    m_rectangle_h.setRotation(sf::degrees(m_properties.angle));
    m_rectangle_w.setRotation(sf::degrees(m_properties.angle));
    m_circle_dl.setRotation(sf::degrees(m_properties.angle));
    m_circle_dr.setRotation(sf::degrees(m_properties.angle));
    m_circle_ul.setRotation(sf::degrees(m_properties.angle));
    m_circle_ur.setRotation(sf::degrees(m_properties.angle));
    m_text_label.setRotation(sf::degrees(m_properties.angle));

    m_text_label.setFillColor(m_properties.label_color);
    m_text_label.setString(m_properties.label);
    m_text_label.setCharacterSize(m_properties.label_size);
}

void Rectangle::draw(sf::RenderWindow &win) {
    sf::Vector2f actual_pos = m_properties.position + m_div_parent->get_position() + sf::Vector2f({m_properties.margin + m_properties.margin_left, m_properties.margin + m_properties.margin_top});
    sf::Vector2f actual_size = m_properties.size - sf::Vector2f({2 * m_properties.margin + m_properties.margin_top + m_properties.margin_bottom, 2 * m_properties.margin + m_properties.margin_left + m_properties.margin_right});
    if (m_properties.radius) {
        if (m_properties.radius * 2 < actual_size.x && m_properties.radius * 2 < actual_size.y) {
            win.draw(m_circle_dl);
            win.draw(m_circle_ur);
        }
        if (m_properties.radius * 2 != actual_size.x || m_properties.radius * 2 != actual_size.y) win.draw(m_circle_dr);
        win.draw(m_circle_ul);
    }
    if (m_properties.radius * 2 < actual_size.x) win.draw(m_rectangle_h);
    if (m_properties.radius * 2 < actual_size.y && m_properties.radius) win.draw(m_rectangle_w);
    win.draw(m_text_label);
    //std::println("I'm being drawn with pos: {{ {}, {} }} and size: {{ {}, {} }}", m_properties.position.x, m_properties.position.y, m_properties.size.x, m_properties.size.y);
}

void Rectangle::set_radius(float rad) { this->m_properties.radius = rad; }
void Rectangle::set_label(std::string label) { this->m_properties.label = label; }
void Rectangle::set_label_size(unsigned int label_size) { this->m_properties.label_size = label_size; }
void Rectangle::set_label_color(sf::Color col) { this->m_properties.label_color = col; }

sf::FloatRect Rectangle::get_global_bounds() const { return this->m_bounding_box; }

float Rectangle::get_radius() const { return this->m_properties.radius; }
std::string Rectangle::get_label() const { return this->m_properties.label; }
unsigned int Rectangle::get_label_size() const {return this->m_properties.label_size; }
sf::Color Rectangle::get_label_color() const { return this->m_properties.label_color; }
}
