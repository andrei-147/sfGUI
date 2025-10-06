#include "transformable.hpp"
#include <SFML/System/Vector2.hpp>

namespace sfGUI {

void Transformable::set_rotation(const float rotation_angle) { this->m_properties.angle = rotation_angle; }
float Transformable::get_rotation() const { return this->m_properties.angle; }

void Transformable::set_scaling(const sf::Vector2f scale) { this->m_properties.scale = scale; }
sf::Vector2f Transformable::get_scaling() const { return this->m_properties.scale; }

void Transformable::set_origin(const sf::Vector2f origin) { this->m_properties.origin = origin; }
sf::Vector2f Transformable::get_origin() const { return this->m_properties.origin; }
}
