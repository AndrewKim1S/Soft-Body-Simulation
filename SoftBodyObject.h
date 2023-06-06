#pragma once

#include "PointMass.h"
#include "Spring.h"
#include <vector>

class SoftBodyObject {

		public:
				SoftBodyObject();
				SoftBodyObject(sf::Vector2f position);

				void update();
				void render(sf::RenderWindow* window);

		private:
				std::vector<PointMass> points;
				std::vector<Spring> springs;
};
