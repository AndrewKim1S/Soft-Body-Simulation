#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "PointMass.h"
#include "math.h"

const float springConstant = 0.0005;
const float dampeningConstant = 0.005;

class Spring{

		public:
				Spring();
				Spring(PointMass *p1, PointMass *p2);
				~Spring();

				void setDefaultDistance(float distance);
				void update();
				void render(sf::RenderWindow* window);

		private:
				float distance;
				PointMass *p1;
				PointMass *p2;
};
