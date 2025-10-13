#include "rectangle.hpp"
#include "sfgui.hpp"
#include "div.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <print>

#include "classes.hpp"
#include "button.hpp"

void close_window(sf::RenderWindow &win) {
    win.close();
    exit(0);
}

int main() {
    sf::Vector2u window_size = {800, 600};

    sf::RenderWindow win = sf::RenderWindow(sf::VideoMode(window_size), "sfml");

    sfGUI::init(win);
    while (win.isOpen()) {
        while (const auto event = win.pollEvent()) {
            if (event->is<sf::Event::Closed>()) close_window(win);
            if (event->is<sf::Event::Resized>()) window_size = win.getSize();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) close_window(win);

        win.clear(sf::Color(30, 30, 30, 255));
        {
            sfGUI::start_render(window_size);

            sfGUI::Div* div = sfGUI::get_main_div();

            div->set_padding(20.0f);
            div->set_size({float(window_size.x), float(window_size.y)});

            static float margin = 0.0f;

            sfGUI::Button* rect = new sfGUI::Button();
            rect->set_position({4.0f, 4.0f});
            rect->set_color(sf::Color::Blue);
            rect->set_size({200.0f, 200.0f});
            rect->set_margin(margin);
            rect->set_label("hello, world!");
            rect->set_label_size(20);
            rect->set_radius(20.0f);
            sfGUI::Rectangle_Properties* idle = rect->get_idle_properties();
            idle->color = sf::Color::Yellow;
            idle->radius = 10.0f;
            sfGUI::Rectangle_Properties* clicked = rect->get_click_properties();
            clicked->label = "Clicked!";
            rect->set_callback([](){std::println("someting important: ");});
            sfGUI::add_element(rect);

            sfGUI::end_render();
            sf::FloatRect bounds = rect->get_global_bounds();
            sf::RectangleShape debug_rect = sf::RectangleShape(bounds.size);
            debug_rect.setPosition(bounds.position);
            debug_rect.setFillColor(sf::Color::Magenta);
            // win.draw(debug_rect);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) margin += 0.01f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) margin -= 0.01f;
        }
        win.display();
    }
}
