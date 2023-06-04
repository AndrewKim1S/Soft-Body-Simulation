#pragma once

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <cassert>

#include "PointMass.h"
#include "Spring.h"


const int timeStep = 20;

class Application {

		// application states
		enum State {
				RUN,
				PAUSE
		};

		public:
				Application();
				Application(int width, int length);
				~Application();
				void run();
				void render();
				void pollEvents();
				void update();
				bool isRunning();

				void createSoftBodyObject();
				
		private:
				sf::RenderWindow* window;
				sf::Event event;
				sf::Clock clock;

				int width;
				int height;

				State state;

				std::vector<PointMass> points;
				std::vector<Spring> springs;


				bool stepNext;
};
