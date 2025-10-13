#include "button.hpp"
#include "rectangle.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <print>

namespace sfGUI {
void Button::set_properties(Rectangle_Properties &properties) {
    Rectangle::set_position(properties.position);
    Rectangle::set_size(properties.size);
    Rectangle::set_radius(properties.radius);
    Rectangle::set_color(properties.color);
    Rectangle::set_margin(properties.margin);
    Rectangle::set_margins(properties.margin_top, properties.margin_bottom, properties.margin_left, properties.margin_right);
    Rectangle::set_rotation(properties.angle);
    Rectangle::set_scaling(properties.scale);
    Rectangle::set_origin(properties.origin);
    Rectangle::set_label(properties.label);
    Rectangle::set_label_color(properties.label_color);
    Rectangle::set_label_size(properties.label_size);
}

void Button::update() {}

void Button::draw(sf::RenderWindow &win) {
    bool mouse_pressed = sf::Mouse::isButtonPressed(m_click_button);
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(win);
    sf::Vector2f mouse_pos_f = sf::Vector2f({float(mouse_pos.x), float(mouse_pos.y)});
    std::string props = "idle";
    set_properties(m_idle_properties);
    Rectangle::update();
    sf::FloatRect bounds = Rectangle::get_global_bounds();
    if (bounds.contains(mouse_pos_f)) {
        if (mouse_pressed) {
            props = "clicked";
            set_properties(m_click_properties);
        } else {
            props = "hover";
            set_properties(m_hover_properties);
        }
    } else {
        set_properties(m_idle_properties);
        if (m_was_pressed) {
            m_callback();
        }
    }
    std::println("properties = {} -- mpos: {{ {}, {} }} -- mclicked: {} -- bounds size: {{ {}, {} }}", props, mouse_pos.x, mouse_pos.y, mouse_pressed, bounds.size.x, bounds.size.y);
    Rectangle::update();
    Rectangle::draw(win);
}

Rectangle_Properties* Button::get_idle_properties() { return &this->m_idle_properties; }
Rectangle_Properties* Button::get_hover_properties() { return &this->m_hover_properties; }
Rectangle_Properties* Button::get_click_properties() { return &this->m_click_properties; }

void Button::set_radius(float radius) {
    this->m_click_properties.radius = radius;
    this->m_hover_properties.radius = radius;
    this->m_idle_properties.radius  = radius;
}

void Button::set_label(std::string label) {
    this->m_click_properties.label = label;
    this->m_hover_properties.label = label;
    this-> m_idle_properties.label = label;
}

void Button::set_label_size(unsigned int label_text_size) {
    this->m_click_properties.label_size = label_text_size;
    this->m_hover_properties.label_size = label_text_size;
    this-> m_idle_properties.label_size = label_text_size;
}

void Button::set_label_color(sf::Color label_color) {
    this->m_click_properties.label_color = label_color;
    this->m_hover_properties.label_color = label_color;
    this-> m_idle_properties.label_color = label_color;
}

void Button::set_rotation(const float angle) {
    this->m_click_properties.angle = angle;
    this->m_hover_properties.angle = angle;
    this-> m_idle_properties.angle = angle;
}

void Button::set_scaling(const sf::Vector2f scale) {
    this->m_click_properties.scale = scale;
    this->m_hover_properties.scale = scale;
    this-> m_idle_properties.scale = scale;
}

void Button::set_origin(const sf::Vector2f origin) {
    this->m_click_properties.origin = origin;
    this->m_hover_properties.origin = origin;
    this-> m_idle_properties.origin = origin;
}

void Button::set_position(const sf::Vector2f pos) {
    this->m_click_properties.position = pos;
    this->m_hover_properties.position = pos;
    this-> m_idle_properties.position = pos;
}

void Button::set_size(const sf::Vector2f size) {
    this->m_click_properties.size = size;
    this->m_hover_properties.size = size;
    this-> m_idle_properties.size = size;
}

void Button::set_color(const sf::Color col) {
    this->m_click_properties.color = col;
    this->m_hover_properties.color = col;
    this-> m_idle_properties.color = col;
}

void Button::set_margin(const float margin) {
    this->m_click_properties.margin = margin;
    this->m_hover_properties.margin = margin;
    this-> m_idle_properties.margin = margin;
}

void Button::set_margins(const float top, const float bottom, const float left, const float right) {
    this->m_click_properties.margin_top = top;
    this->m_hover_properties.margin_top = top;
    this-> m_idle_properties.margin_top = top;

    this->m_click_properties.margin_bottom = bottom;
    this->m_hover_properties.margin_bottom = bottom;
    this-> m_idle_properties.margin_bottom = bottom;

    this->m_click_properties.margin_left = left;
    this->m_hover_properties.margin_left = left;
    this-> m_idle_properties.margin_left = left;

    this->m_click_properties.margin_right = right;
    this->m_hover_properties.margin_right = right;
    this-> m_idle_properties.margin_right = right;
}

void Button::set_callback(const std::function<void()> callback) { this->m_callback = callback; }

void Button::set_mouse_button(const sf::Mouse::Button button) { this->m_click_button = button; }
}
