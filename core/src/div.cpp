#include "div.hpp"
#include <SFML/System/Vector2.hpp>
#include <print>

namespace sfGUI {
Div::Div(Div *parent_ptr) {
    m_parent_ptr = parent_ptr;
    m_elem_ptr = {0, 0};
    m_padding = 0.0f;
    m_properties.color = sf::Color(0, 0, 0, 0);
}

Div::~Div() {
    for (const auto elem : m_elements) {
        delete elem;
    }
    m_elements.clear();
}

void Div::update() {
    for (const auto elem : m_elements) {
        elem->update();
    }
}

void Div::draw(sf::RenderWindow &win) {
    if (m_properties.color.a > 0) {
        sf::RectangleShape bg_rect = sf::RectangleShape(m_properties.size);
        bg_rect.setFillColor(m_properties.color);
        bg_rect.setPosition(m_properties.position);
        win.draw(bg_rect);
    }
    for (const auto elem : m_elements) {
        sf::Vector2f max_point = elem->get_position() + elem->get_size();
        if (max_point.x > m_properties.size.x || max_point.y > m_properties.size.y) {
            std::println("Error: Element too big!: curr/max x: {}/{}, curr/max y: {}/{}", max_point.x, m_properties.size.x, max_point.y, m_properties.size.y);
            continue;
        }
        elem->draw(win);
    }
}

void Div::add_element(Element *elem) {
    this->m_elements.push_back(elem);
    elem->set_position(m_elem_ptr + get_position() + sf::Vector2f({m_padding, m_padding}));
    elem->set_parent_div(this);
    sf::Vector2f elem_size = elem->get_size();
    if (m_elem_ptr.x + elem_size.x < m_properties.size.x) {
        move_ptr_x(elem_size.x);
    } else {
        m_elem_ptr.x = 0;
        move_ptr_y(elem_size.y);
    }
}

void Div::move_ptr_x(float x) {
    this->m_elem_ptr.x += x;
    if (m_elem_ptr.x < 0) m_elem_ptr.x = 0;
    if (m_elem_ptr.x > m_properties.size.x) m_elem_ptr.x = m_properties.size.x;
}

void Div::move_ptr_y(float y) {
    this->m_elem_ptr.y += y;
    if (m_elem_ptr.y < 0) m_elem_ptr.y = 0;
    if (m_elem_ptr.y > m_properties.size.y) m_elem_ptr.y = m_properties.size.y;
}

sf::Vector2f Div::get_element_ptr() const { return m_elem_ptr; }

Div* Div::get_parent_ptr() const { return this->m_parent_ptr; }

void Div::set_padding(float padding) {
    this->m_padding = padding;
}
float Div::get_padding() const { return this->m_padding; }
}
