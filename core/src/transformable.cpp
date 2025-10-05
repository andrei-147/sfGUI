#include "transformable.hpp"
#include <SFML/System/Vector2.hpp>

namespace sfGUI {

void Transformable::set_rotation(float rotation_angle) { this->m_angle = rotation_angle; }
float Transformable::get_rotation() const { return this->m_angle; }

void Transformable::set_scaling(const sf::Vector2f scale) { this->m_scale = scale; }
sf::Vector2f Transformable::get_scaling() const { return this->m_scale; }

void Transformable::set_origin(const sf::Vector2f origin) { this->m_origin = origin; }
sf::Vector2f Transformable::get_origin() const { return this->m_origin; }
}
