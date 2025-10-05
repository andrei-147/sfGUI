#ifndef DIV_HPP
#define DIV_HPP

#include "transformable.hpp"
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace sfGUI {

class Div : public Transformable {

protected:
    Div* m_parent_ptr;
    std::vector<Element*> m_elements;
    sf::Vector2f m_elem_ptr;
    float m_padding;
    sf::Color m_background_color;

public:
    Div() = delete;
    Div(Div*);
    ~Div();

    void update() override;
    void draw(sf::RenderWindow&) override;

    Div* get_parent_ptr() const;

    void move_ptr_x(float);
    void move_ptr_y(float);

    void add_element(Element*);

    [[nodiscard]] sf::Vector2f get_element_ptr() const;
    
    void set_padding(float);
    [[nodiscard]] float get_padding() const;
};
}

#endif // !DIV_HPP

