#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "rectangle.hpp"
#include <SFML/Window/Mouse.hpp>
#include <functional>

namespace sfGUI {
class Button : public Rectangle {
private:
    Rectangle_Properties m_properties = Rectangle_Properties();

protected:
    Rectangle_Properties m_idle_properties = Rectangle_Properties();
    Rectangle_Properties m_hover_properties = Rectangle_Properties();
    Rectangle_Properties m_click_properties = Rectangle_Properties();

    bool m_was_pressed = false;

    std::function<void()> m_callback = [](){};
    sf::Mouse::Button m_click_button = sf::Mouse::Button::Left;

    void set_properties(Rectangle_Properties&);

public:
    virtual void update() override;
    virtual void draw(sf::RenderWindow&) override;

    [[nodiscard]] Rectangle_Properties* get_idle_properties();
    [[nodiscard]] Rectangle_Properties* get_hover_properties();
    [[nodiscard]] Rectangle_Properties* get_click_properties();

    virtual void set_radius(float) override;
    virtual void set_label(std::string) override;
    virtual void set_label_size(unsigned int) override;
    virtual void set_label_color(sf::Color) override;

    virtual void set_rotation(const float) override;
    virtual void set_scaling(const sf::Vector2f) override;
    virtual void set_origin(const sf::Vector2f) override;
    
    virtual void set_position(const sf::Vector2f) override;
    virtual void set_size(const sf::Vector2f) override;
    virtual void set_color(const sf::Color) override;
    virtual void set_margin(const float) override;
    virtual void set_margins(const float, const float, const float, const float) override;

    void set_callback(const std::function<void()>);

    void set_mouse_button(const sf::Mouse::Button);

    
};
}

#endif // BUTTON_HPP
//
