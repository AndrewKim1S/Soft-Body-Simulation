#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

const float radius = 5;
const float dampening = 0.8;

class PointMass{

		public:
				PointMass();
				PointMass(sf::Vector2f pos, float mass);
				~PointMass();

				void update(float dt);
				void render(sf::RenderWindow* window);
				sf::Vector2f getPosition();
				void setSpringForce(float x, float y);
				
				void debugInfo();

				void setFixedPoint(bool fixed);
				sf::Vector2f getVelocity();

		private:
				sf::Vector2f position;
				sf::Vector2f prevPosition;
				sf::Vector2f velocity;

				sf::Vector2f springForce;

				float mass;

				bool fixedPoint;
};
