#include "SoftBodyObject.h"

SoftBodyObject::SoftBodyObject() {

}


SoftBodyObject::SoftBodyObject(sf::Vector2f position) {
		// Square
		points.emplace_back(PointMass(sf::Vector2f(300, 300), 1));
		points.emplace_back(PointMass(sf::Vector2f(450, 300), 1));
		points.emplace_back(PointMass(sf::Vector2f(300, 450), 1));
		points.emplace_back(PointMass(sf::Vector2f(450, 450), 1));
		springs.emplace_back(Spring(&points[0], &points[1]));
		springs.emplace_back(Spring(&points[0], &points[2]));
		springs.emplace_back(Spring(&points[0], &points[3]));
		springs.emplace_back(Spring(&points[1], &points[2]));
		springs.emplace_back(Spring(&points[1], &points[3]));
		springs.emplace_back(Spring(&points[2], &points[3]));
}

void SoftBodyObject::update() {
		for (Spring& s : springs) {
				s.update();
		}
		
		for (PointMass& p : points) {
				p.update(10);
		}
}

void SoftBodyObject::render(sf::RenderWindow* window) {
		for (Spring& s : springs) {
				s.render(window);
		}
		
		for (PointMass& p : points) {
				p.render(window);
		}
}
