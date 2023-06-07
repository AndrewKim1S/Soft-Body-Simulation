#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

const float radius = 5;
const float dampening = 0.8;
const float gravity = 0.009;
const float windowWidth = 900;
const float windowLength = 1500;

class PointMass{

		public:
				PointMass();
				PointMass(sf::Vector2f pos, float mass);
				~PointMass();

				void update(float dt);
				void render(sf::RenderWindow* window);
				void wallCollision();
				sf::Vector2f getPosition();
				void setSpringForce(float x, float y);
				void setForce(float x, float y);

				void debugInfo();

				void setFixedPoint(bool fixed);
				sf::Vector2f getVelocity();

		private:
				sf::Vector2f position;
				sf::Vector2f prevPosition;
				sf::Vector2f velocity;

				sf::Vector2f springForce;
				sf::Vector2f outsideForce;

				float mass;

				bool fixedPoint;
};
