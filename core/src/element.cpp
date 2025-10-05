#include "element.hpp"
#include "div.hpp"
#include <algorithm>

namespace sfGUI {
void Element::set_position(const sf::Vector2f position) { this->m_position = position; }
sf::Vector2f Element::get_position() const { return this->m_position + (m_div_parent != nullptr ? m_div_parent->get_position() : sf::Vector2f({0, 0})); }

void Element::set_size(const sf::Vector2f size) { this->m_size = size; }
sf::Vector2f Element::get_size() const { return this->m_size; }

void Element::set_color(const sf::Color color) { this->m_color = color; }
sf::Color Element::get_color() const { return this->m_color; }

void Element::set_margin(const float margin) { this->m_margin = std::max(margin, 0.0f); }
float Element::get_margin() const { return this->m_margin; }

void Element::set_margins(
    const float margin_top = -1,
    const float margin_bottom = -1,
    const float margin_left = -1,
    const float margin_right = -1
) {
    this->m_margin_top = std::max(margin_top, 0.0f);
    this->m_margin_bottom = std::max(margin_bottom, 0.0f);
    this->m_margin_left = std::max(margin_left, 0.0f);
    this->m_margin_right = std::max(margin_right, 0.0f);
}

float Element::get_margin_top() const { return this->m_margin_top; }
float Element::get_margin_bottom() const { return this->m_margin_bottom; }
float Element::get_margin_left() const { return this->m_margin_left; }
float Element::get_margin_right() const { return this->m_margin_right; }

void Element::set_parent_div(Div *div_ptr) {
    m_div_parent = div_ptr;
}
}
