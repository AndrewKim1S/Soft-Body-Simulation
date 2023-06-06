#include "Application.h"


// Constructor
Application::Application() {

}

// Constructor
Application::Application(int width, int length) {
		// Create window
		window = new sf::RenderWindow(sf::VideoMode(width, length), "Flocking Simulation");
		window->setPosition(sf::Vector2i(300, 75));
		this->width = width;
		this->height = length;

		clock.restart();

		state = State::RUN;

		createSoftBodyObject();

		stepNext = false;
}

// Deconstructor
Application::~Application() {
		delete window;
}

// main run function to update, render, and poll events
void Application::run() {
		// check state of application
		switch(state) {
				case State::RUN:
						if(clock.getElapsedTime().asMilliseconds() > 10) {
								pollEvents();
								render();
								/*
								if(stepNext) {
										stepNext = false;
								} else {
										return;
								}
								std::cout << "Updating ------------------" << std::endl;
								*/
								update();
								clock.restart();
						} else {
								return;
						}
						break;
				case State::PAUSE:
						pollEvents();
						break;
				default:
						break;
		}
}

// Draw all the boids and quadtree to the window
void Application::render() {

		window->clear(sf::Color(32, 32, 32));
		softbody.render(window);
		window->display();
}

// poll events from the user
void Application::pollEvents() {
		// check event 
		while(window->pollEvent(event)) {
				switch(event.type) {
						// close window 
						case sf::Event::Closed:
								window->close();
								break;
						case sf::Event::KeyPressed:
								// close window when escape
								if(event.key.code == sf::Keyboard::Escape) {
										window->close();
								}
								// toggle pause when P
								else if(event.key.code == sf::Keyboard::P) {
										if(state == State::PAUSE) {
												state = State::RUN;
										} 
										else {
												state = State::PAUSE;
										}
								}
								else if(event.key.code == sf::Keyboard::N) {
										stepNext = true;
								}

						default:
								break;
				}
		}
}

// update the application, quadtree & boids
void Application::update() {
		softbody.update();
}

// return the state of the window
bool Application::isRunning() {
		return window->isOpen();
}

void Application::createSoftBodyObject() {

		softbody = SoftBodyObject(sf::Vector2f(400, 400));

		/*
		// Spring - Vertical
		points.emplace_back(PointMass(sf::Vector2f(500, 500), 1));
		// points[0].setFixedPoint(true);
		points.emplace_back(PointMass(sf::Vector2f(500, 650), 1));
		springs.emplace_back(Spring(&points[0], &points[1]));
		springs[0].setDefaultDistance(100);
		*/

		/*
		// Spring - Angled
		// points[0].setFixedPoint(true);
		points.emplace_back(PointMass(sf::Vector2f(500, 500), 1));
		points.emplace_back(PointMass(sf::Vector2f(560, 350), 1));
		springs.emplace_back(Spring(&points[0], &points[1]));
		springs[0].setDefaultDistance(100);
		*/

		// Triangle
		/*
		points.emplace_back(PointMass(sf::Vector2f(400, 400), 1));
		points.emplace_back(PointMass(sf::Vector2f(550, 400), 1));
		points.emplace_back(PointMass(sf::Vector2f(475, 529.9), 1));
		springs.emplace_back(Spring(&points[0], &points[1]));
		springs.emplace_back(Spring(&points[0], &points[2]));
		springs.emplace_back(Spring(&points[1], &points[2]));
		springs[0].setDefaultDistance(50);
		*/

		// Square
		/*
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
		*/
}
