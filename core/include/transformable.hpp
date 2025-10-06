#ifndef TRANSFORMABLE_HPP
#define TRANSFORMABLE_HPP

#include "element.hpp"
#include <SFML/System/Vector2.hpp>

namespace sfGUI {

struct Transformable_Properties : public Element_Properties {
    sf::Vector2f scale = {1.0f, 1.0f};
    sf::Vector2f origin = {0.0f, 0.0f};
    float        angle = 0.0f;
};

class Transformable : public Element {

private:
    Transformable_Properties m_properties = Transformable_Properties();

public:
    Transformable() = default;
    ~Transformable() = default;

    virtual void update() {}
    virtual void draw(sf::RenderWindow&) {}

    virtual void set_rotation(const float);
    [[nodiscard]] float get_rotation() const;

    virtual void set_scaling(const sf::Vector2f);
    [[nodiscard]] sf::Vector2f get_scaling() const;

    virtual void set_origin(const sf::Vector2f);
    [[nodiscard]] sf::Vector2f get_origin() const;
};
}

#endif // !TRANSFORMABLE_HPP
