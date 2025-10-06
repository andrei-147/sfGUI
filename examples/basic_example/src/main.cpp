#include "sfgui.hpp"
#include "div.hpp"
#include <SFML/Graphics.hpp>

#include "classes.hpp"
#include "rectangle.hpp"

int main() {
    sf::Vector2u window_size = {800, 600};

    sf::RenderWindow win = sf::RenderWindow(sf::VideoMode(window_size), "sfml");

    sfGUI::init(win);
    while (win.isOpen()) {
        while (const auto event = win.pollEvent()) {
            if (event->is<sf::Event::Closed>()) win.close();
            if (event->is<sf::Event::Resized>()) window_size = win.getSize();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) win.close();

        win.clear(sf::Color(30, 30, 30, 255));
        {
            sfGUI::start_render(window_size);

            sfGUI::Div* div = sfGUI::get_main_div();

            div->set_padding(20.0f);

            static float margin = 0.0f;

            sfGUI::Rectangle* rect = new sfGUI::Rectangle();
            rect->set_color(sf::Color::Yellow);
            rect->set_size({200.0f, 200.0f});
            rect->set_radius(25.0f);
            rect->set_margin(margin);
            rect->set_label("hello, world!");
            rect->set_label_size(20);
            sfGUI::add_element(rect);

            sfGUI::end_render();

            sf::RectangleShape rect_a = sf::RectangleShape(rect->get_global_bounds().size);
            rect_a.setPosition(rect->get_global_bounds().position);
            rect_a.setFillColor(sf::Color::Magenta);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)) win.draw(rect_a);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) margin += 0.001f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) margin -= 0.001f;
        }
        win.display();
    }
}
