#include "PointMass.h"


PointMass::PointMass() {

}

PointMass::PointMass(sf::Vector2f pos, float mass) {
		this->position = pos;
		this->prevPosition = pos;
		this->mass = mass;
		fixedPoint = false;
		springForce.x = 0;
		springForce.y = 0;
}

PointMass::~PointMass() {

}

void PointMass::update(float dt) {
		if(fixedPoint) {
				return;
		}

		sf::Vector2f nextPosition;

		// Calculate total force acting on point
		sf::Vector2f force(0, 0);
		force.x += springForce.x;
		force.y += springForce.y;
		// force.y += 0.0008; // gravity

		// Acceleration
		sf::Vector2f acceleration(0,0);
		acceleration.x = force.x / mass;
		acceleration.y = force.y / mass;

		// Verlet Integration
		nextPosition = 2.f * position - prevPosition + acceleration * (dt * dt);
		
		springForce.x = 0;
		springForce.y = 0;

		prevPosition = position;
		position = nextPosition;
}

void PointMass::render(sf::RenderWindow* window) {
		sf::CircleShape c;
		c.setPosition(position.x - radius, position.y - radius);
		c.setRadius(radius);
		c.setFillColor(sf::Color::White);
		window->draw(c);
}

sf::Vector2f PointMass::getPosition() {
		return position;
}

void PointMass::setSpringForce(float x, float y) {
		springForce.x += x;
		springForce.y += y;
}

void PointMass::debugInfo() {
		std::cout << "position: " << position.x << ", " << position.y << std::endl;
		std::cout << "springForce: " << springForce.x << ", " << springForce.y << std::endl;
}

void PointMass::setFixedPoint(bool fixed) {
		fixedPoint = fixed;
}

sf::Vector2f PointMass::getVelocity() {
		return (position - prevPosition)/10.f;
}
