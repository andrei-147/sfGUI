#ifndef SFGUI_HPP
#define SFGUI_HPP

#include "classes.hpp"

#include <SFML/Graphics.hpp>

namespace sfGUI {
void init(sf::RenderWindow&);

void start_render(const sf::Vector2u);
void end_render();

Div* begin_div();
void end_div();

Div* get_main_div();

Element* add_element(Element*);

class GUI {
public:
    static GUI& instance() {
        static GUI g;
        return g;
    }

private:
    sf::RenderWindow *m_render_window;
    sf::Vector2u m_window_size;
    Div* m_main_div;
    Element* m_current_element = nullptr;

public:
    GUI() = default;
    ~GUI();
    GUI(const GUI&) = delete;
    GUI& operator=(const GUI&) = delete;

    void clearbuf();
    void draw();

    void debug() noexcept;
    void set_render_window(sf::RenderWindow&);

    void set_window_size(const sf::Vector2u);
    [[nodiscard]] sf::Vector2u get_window_size() const;

    Div* add_div();
    void end_div();

    Div* get_main_div() const;

    Element* add_element(Element*);

    Element* get_current_element() const;
};
};

#endif // SFGUI_HPP
