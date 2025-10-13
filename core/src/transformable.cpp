#include "transformable.hpp"
#include <SFML/System/Vector2.hpp>

namespace sfGUI {

void Transformable::set_rotation(const float rotation_angle) { this->transformable_properties().angle = rotation_angle; }
float Transformable::get_rotation() const { return this->transformable_properties().angle; }

void Transformable::set_scaling(const sf::Vector2f scale) { this->transformable_properties().scale = scale; }
sf::Vector2f Transformable::get_scaling() const { return this->transformable_properties().scale; }

void Transformable::set_origin(const sf::Vector2f origin) { this->transformable_properties().origin = origin; }
sf::Vector2f Transformable::get_origin() const { return this->transformable_properties().origin; }
}
