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
		dragging = false;
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
						case sf::Event::MouseButtonPressed:
								if(event.mouseButton.button == sf::Mouse::Left) {
										dragging = true;
										mousePoint = sf::Mouse::getPosition(*window);
								}
								break;
						case sf::Event::MouseButtonReleased:
								if(event.mouseButton.button == sf::Mouse::Left) {
										dragging = false;
								}
								break;
						case sf::Event::MouseMoved:
								if(dragging) {
										mousePoint = sf::Mouse::getPosition(*window);
								}
								break;
						default:
								break;
				}
		}
}

// update the application, quadtree & boids
void Application::update() {
		if(dragging) {
				softbody.dragObject(mousePoint);
		}
		softbody.update();
}

// return the state of the window
bool Application::isRunning() {
		return window->isOpen();
}

void Application::createSoftBodyObject() {

		softbody = SoftBodyObject(sf::Vector2f(400, 400));

}
