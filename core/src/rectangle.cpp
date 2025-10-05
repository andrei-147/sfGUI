#include "rectangle.hpp"
#include "div.hpp"
#include "theme.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

namespace sfGUI {
Rectangle::Rectangle() {
    m_position = {0.0f, 0.0f};
    m_scale = {1.0f, 1.0f};
    m_size = {0.0f, 0.0f};
    m_color = sf::Color::Black;
    m_angle = 0;
    m_origin = {0.0f, 0.0f};
}

void Rectangle::update() {
    sf::Vector2f actual_pos = m_position + m_div_parent->get_position() + sf::Vector2f({m_margin + m_margin_left, m_margin + m_margin_top});
    sf::Vector2f actual_size = m_size - sf::Vector2f({2 * m_margin + m_margin_top + m_margin_bottom, 2 * m_margin + m_margin_left + m_margin_right});
    m_bounding_box = sf::FloatRect(actual_pos, actual_size);

    sf::Vector2f margin_scale = {(actual_size.x / m_size.x) * m_scale.x, (actual_size.y / m_size.y) * m_scale.y};
    m_bounding_box = sf::FloatRect(actual_pos, actual_size);
    m_circle_dl.setRadius(m_radius);
    m_circle_dr.setRadius(m_radius);
    m_circle_ul.setRadius(m_radius);
    m_circle_ur.setRadius(m_radius);
    m_rectangle_h.setSize(actual_size - sf::Vector2f({m_radius * 2, 0}));
    m_rectangle_w.setSize(actual_size - sf::Vector2f({0, m_radius * 2}));

    m_rectangle_h.setPosition(actual_pos);
    m_rectangle_w.setPosition(actual_pos);
    m_circle_ul.setPosition(actual_pos);
    m_circle_dl.setPosition(actual_pos);
    m_circle_ur.setPosition(actual_pos);
    m_circle_dr.setPosition(actual_pos);

    m_circle_dl.setOrigin(sf::Vector2f({0, m_radius * 2 - actual_size.y}));
    m_circle_ur.setOrigin(sf::Vector2f({m_radius * 2 - actual_size.x, 0}));
    m_circle_dr.setOrigin(sf::Vector2f({m_radius * 2, m_radius * 2}) - actual_size);
    m_rectangle_h.setOrigin(sf::Vector2f({-m_radius, 0}));
    m_rectangle_w.setOrigin(sf::Vector2f({0, -m_radius}));
    
    m_rectangle_h.setFillColor(m_color);
    m_rectangle_w.setFillColor(m_color);
    m_circle_dl.setFillColor(m_color);
    m_circle_dr.setFillColor(m_color);
    m_circle_ul.setFillColor(m_color);
    m_circle_ur.setFillColor(m_color);

    m_rectangle_h.setScale(margin_scale);
    m_rectangle_w.setScale(margin_scale);
    m_circle_dl.setScale(margin_scale);
    m_circle_dr.setScale(margin_scale);
    m_circle_ul.setScale(margin_scale);
    m_circle_ur.setScale(margin_scale);

    m_rectangle_h.setRotation(sf::degrees(m_angle));
    m_rectangle_w.setRotation(sf::degrees(m_angle));
    m_circle_dl.setRotation(sf::degrees(m_angle));
    m_circle_dr.setRotation(sf::degrees(m_angle));
    m_circle_ul.setRotation(sf::degrees(m_angle));
    m_circle_ur.setRotation(sf::degrees(m_angle));

    m_text_label.setPosition(actual_pos);
    m_text_label.setOrigin(sf::Vector2f({-m_radius, -m_radius}));
    m_text_label.setScale(margin_scale);
    m_text_label.setRotation(sf::degrees(m_angle));
    m_text_label.setFillColor(m_label_color);
    m_text_label.setFont(sfGUI::Theme::instance().m_theme_font);
    m_text_label.setCharacterSize(m_label_size);
    m_text_label.setOutlineThickness(1.0f);
    m_text_label.setOutlineColor(sf::Color::Black);
    m_text_label.setString(m_label);
}

void Rectangle::draw(sf::RenderWindow &win) {
    win.draw(m_circle_dl);
    win.draw(m_circle_dr);
    win.draw(m_circle_ul);
    win.draw(m_circle_ur);
    win.draw(m_rectangle_h);
    win.draw(m_rectangle_w);
    win.draw(m_text_label);
}

void Rectangle::set_radius(float rad) { this->m_radius = rad; }
float Rectangle::get_radius() const { return this->m_radius; }

sf::FloatRect Rectangle::get_global_bounds() const { return this->m_bounding_box; }

void Rectangle::set_label(std::string label) { this->m_label = label; }
[[nodiscard]] std::string Rectangle::get_label() const { return this->m_label; }

void Rectangle::set_label_size(unsigned int label_size) { this->m_label_size = label_size; }
[[nodiscard]] unsigned int Rectangle::get_label_size() const {return this->m_label_size; }

void Rectangle::set_label_color(sf::Color col) { this->m_label_color = col; }
[[nodiscard]] sf::Color Rectangle::get_label_color() const { return this->m_label_color; }
}
