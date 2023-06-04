#include "Spring.h"


Spring::Spring() {

}

Spring::Spring(PointMass *p1, PointMass *p2) {
		this->p1 = p1;
		this->p2 = p2;
		sf::Vector2f p1Pos = p1->getPosition();
		sf::Vector2f p2Pos = p2->getPosition();
		this->distance = sqrt((p1Pos.x - p2Pos.x) * (p1Pos.x - p2Pos.x) + 
				(p1Pos.y - p2Pos.y) * (p1Pos.y - p2Pos.y));
}

Spring::~Spring() {

}

void Spring::setDefaultDistance(float distance) {
		this->distance = distance;
}

// 0 degrees is straight down, right is -90, left is 90
void Spring::update() {

		float dx = (p1->getPosition().x - p2->getPosition().x);
		float dy = (p1->getPosition().y - p2->getPosition().y);

		float difference = sqrt((dx * dx) + (dy * dy));
		
		// Use Hooke's Law to find force of the spring F = xk
		float forceMagnitude = (difference - distance);

		
		float thetap1 = atan2(dx, dy);
		float thetap2 = atan2(-dx, -dy);

		// std::cout << "dif - dis" << difference - distance << std::endl;
		// std::cout << "angle 1: " << thetap1 << ", angle 2: " << thetap2 << std::endl;

		float xForce1;
		float yForce1;
		float xForce2;
		float yForce2;

		// Spring is extended
		if(forceMagnitude > 0) {
				xForce1 = -1 * forceMagnitude * sin(thetap1);
				yForce1 = -1 * forceMagnitude * cos(thetap1);
				xForce2 = -1 * forceMagnitude * sin(thetap2);
				yForce2 = -1 * forceMagnitude * cos(thetap2);
		} 
		// Spring is compressed
		else {
				xForce1 = forceMagnitude * sin(thetap2);
				yForce1 = forceMagnitude * cos(thetap2);
				xForce2 = forceMagnitude * sin(thetap1);
				yForce2 = forceMagnitude * cos(thetap1);
		}

		forceMagnitude *= springConstant;

		if(std::max(abs(xForce1), 0.01f) == 0.01f) {
				xForce1 = 0.f;
		}
		if(std::max(abs(yForce1), 0.01f) == 0.01f) {
				yForce1 = 0.f;
		}
		if(std::max(abs(xForce2), 0.01f) == 0.01f) {
				xForce2 = 0.f;
		}
		if(std::max(abs(yForce2), 0.01f) == 0.01f) {
				yForce2 = 0.f;
		}

		xForce1 *= springConstant;
		yForce1 *= springConstant;
		xForce2 *= springConstant;
		yForce2 *= springConstant;

		xForce1 += p1->getVelocity().x * -dampeningConstant;
		yForce1 += p1->getVelocity().y * -dampeningConstant;
		xForce2 += p2->getVelocity().x * -dampeningConstant;
		yForce2 += p2->getVelocity().y * -dampeningConstant;
		// std::cout << "p1 Velocity: " << p1->getVelocity().x << ", " << p1->getVelocity().y << std::endl;
		//std::cout << "p2 Velocity: " << p2->getVelocity().x << ", " << p2->getVelocity().y << std::endl;

		// std::cout << "force P1: " << xForce1 << ", " << yForce1 << std::endl;
		// std::cout << "force P2: " << xForce2 << ", " << yForce2 << std::endl;

		//p1->setSpringForce(0, forceMagnitude);
		//p2->setSpringForce(0, -forceMagnitude);
		p1->setSpringForce(xForce1, yForce1);
		p2->setSpringForce(xForce2, yForce2);
}

void Spring::render(sf::RenderWindow* window) {
		sf::Vertex line[] = {
				sf::Vertex(p1->getPosition(), sf::Color::White),
				sf::Vertex(p2->getPosition(), sf::Color::White)
		};
		window->draw(line, 2, sf::Lines);
}
