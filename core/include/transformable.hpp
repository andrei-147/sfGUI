#ifndef TRANSFORMABLE_HPP
#define TRANSFORMABLE_HPP

#include "element.hpp"

namespace sfGUI {

class Transformable : public Element {

protected:
    sf::Vector2f m_scale;
    sf::Vector2f m_origin;
    float        m_angle;

public:
    Transformable() = default;
    ~Transformable() = default;

    virtual void update() {}
    virtual void draw(sf::RenderWindow&) {}

    void set_rotation(float);
    [[nodiscard]] float get_rotation() const;

    void set_scaling(const sf::Vector2f);
    [[nodiscard]] sf::Vector2f get_scaling() const;

    void set_origin(const sf::Vector2f);
    [[nodiscard]] sf::Vector2f get_origin() const;
};
}

#endif // !TRANSFORMABLE_HPP
