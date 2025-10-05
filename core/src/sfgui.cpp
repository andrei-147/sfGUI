#include "sfgui.hpp"
#include <exception>
#include <print>
#include "div.hpp"

namespace sfGUI {
void init(sf::RenderWindow &win) {
    GUI::instance().set_render_window(win);
}

void start_render(const sf::Vector2u window_size) {
    GUI::instance().clearbuf();
    GUI::instance().set_window_size(window_size);
}

void end_render() {
    GUI::instance().draw();
}

Element* add_element(Element *elem) {
    return GUI::instance().add_element(elem);
}

Element* GUI::add_element(Element *elem) {
    if (auto d = dynamic_cast<Div*>(elem)) {
        std::println("FATAL ERROR: Cannot add a Div using add_element! Try using [begin_div() - end_div()]");
        throw std::exception();
    }
    m_main_div->add_element(elem);
    m_current_element = elem;
    return elem;
}

Div* begin_div() {
    return GUI::instance().add_div();
}

void end_div() {
    GUI::instance().end_div();
}

GUI::~GUI() {
    delete m_main_div;
}

Div* GUI::add_div() {
    Div* tempdiv = new Div(m_main_div);
    m_current_element = (Element*)tempdiv;
    m_main_div->add_element(tempdiv);
    m_main_div = tempdiv;
    return tempdiv;
}

void GUI::end_div() {
    if (m_main_div->get_parent_ptr() == nullptr) return;
    m_main_div = m_main_div->get_parent_ptr();
}

Div* get_main_div() {
    return GUI::instance().get_main_div();
}

Div* GUI::get_main_div() const {
    Div* div = m_main_div;
    while (div->get_parent_ptr() != nullptr) div = div->get_parent_ptr();
    return div;
}

void GUI::clearbuf() {
    delete m_main_div;
    m_main_div = new Div(nullptr);
    m_main_div->set_size({float(m_window_size.x), float(m_window_size.y)});
    m_current_element = m_main_div;
}
void GUI::draw() {
    while (m_main_div->get_parent_ptr() != nullptr) m_main_div = m_main_div->get_parent_ptr();
    m_main_div->update();
    m_main_div->draw(*m_render_window);
}

void GUI::debug() noexcept { std::println("Hello, world!"); }

void GUI::set_render_window(sf::RenderWindow &win) { this->m_render_window = &win; }

void GUI::set_window_size(const sf::Vector2u window_size) { this->m_window_size = window_size; }

sf::Vector2u GUI::get_window_size() const { return this->m_window_size; }

Element* GUI::get_current_element() const { return m_current_element; }
}
