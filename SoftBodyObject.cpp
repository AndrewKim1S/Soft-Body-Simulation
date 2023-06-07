#include "SoftBodyObject.h"

SoftBodyObject::SoftBodyObject() {

}


SoftBodyObject::SoftBodyObject(sf::Vector2f position) {
		center.x = 0;
		center.y = 0;

		points.emplace_back(PointMass(sf::Vector2f(300, 300), 1)); // 0
		points.emplace_back(PointMass(sf::Vector2f(325, 300), 1));
		points.emplace_back(PointMass(sf::Vector2f(350, 300), 1));
		points.emplace_back(PointMass(sf::Vector2f(375, 300), 1));
		
		points.emplace_back(PointMass(sf::Vector2f(300, 325), 1)); // 4
		points.emplace_back(PointMass(sf::Vector2f(300, 350), 1));
		points.emplace_back(PointMass(sf::Vector2f(300, 375), 1));
		points.emplace_back(PointMass(sf::Vector2f(300, 400), 1)); // 7
		points.emplace_back(PointMass(sf::Vector2f(300, 425), 1));
		
		points.emplace_back(PointMass(sf::Vector2f(325, 325), 1)); // 9
		points.emplace_back(PointMass(sf::Vector2f(325, 350), 1));
		points.emplace_back(PointMass(sf::Vector2f(325, 375), 1)); // 11
		points.emplace_back(PointMass(sf::Vector2f(325, 400), 1));
		points.emplace_back(PointMass(sf::Vector2f(325, 425), 1));
		
		points.emplace_back(PointMass(sf::Vector2f(350, 325), 1)); // 14
		points.emplace_back(PointMass(sf::Vector2f(350, 350), 1));
		points.emplace_back(PointMass(sf::Vector2f(350, 375), 1));
		points.emplace_back(PointMass(sf::Vector2f(350, 400), 1)); // 17
		points.emplace_back(PointMass(sf::Vector2f(350, 425), 1));
		
		points.emplace_back(PointMass(sf::Vector2f(375, 325), 1)); // 19
		points.emplace_back(PointMass(sf::Vector2f(375, 350), 1));
		points.emplace_back(PointMass(sf::Vector2f(375, 375), 1));
		points.emplace_back(PointMass(sf::Vector2f(375, 400), 1)); // 22
		points.emplace_back(PointMass(sf::Vector2f(375, 425), 1));
	

		springs.emplace_back(Spring(&points[0], &points[1]));
		springs.emplace_back(Spring(&points[0], &points[4]));
		springs.emplace_back(Spring(&points[0], &points[9]));
		
		springs.emplace_back(Spring(&points[1], &points[2]));
		springs.emplace_back(Spring(&points[1], &points[9]));
		springs.emplace_back(Spring(&points[1], &points[14]));
		
		springs.emplace_back(Spring(&points[2], &points[3]));
		springs.emplace_back(Spring(&points[2], &points[14]));
		springs.emplace_back(Spring(&points[2], &points[19]));
	
		// diagonals
		springs.emplace_back(Spring(&points[1], &points[4]));
		springs.emplace_back(Spring(&points[2], &points[9]));
		springs.emplace_back(Spring(&points[5], &points[9]));
		springs.emplace_back(Spring(&points[3], &points[14]));
		springs.emplace_back(Spring(&points[10], &points[14]));
		springs.emplace_back(Spring(&points[15], &points[19]));
		springs.emplace_back(Spring(&points[6], &points[10]));
		springs.emplace_back(Spring(&points[11], &points[15]));
		springs.emplace_back(Spring(&points[16], &points[20]));
		springs.emplace_back(Spring(&points[7], &points[11]));
		springs.emplace_back(Spring(&points[12], &points[16]));
		springs.emplace_back(Spring(&points[17], &points[21]));
		springs.emplace_back(Spring(&points[8], &points[12]));
		springs.emplace_back(Spring(&points[13], &points[17]));
		springs.emplace_back(Spring(&points[18], &points[22]));
		
		springs.emplace_back(Spring(&points[3], &points[19]));

		springs.emplace_back(Spring(&points[4], &points[5]));
		springs.emplace_back(Spring(&points[4], &points[10]));
		springs.emplace_back(Spring(&points[4], &points[9]));
		
		springs.emplace_back(Spring(&points[9], &points[10]));
		springs.emplace_back(Spring(&points[9], &points[14]));
		springs.emplace_back(Spring(&points[9], &points[15]));
		
		springs.emplace_back(Spring(&points[14], &points[15]));
		springs.emplace_back(Spring(&points[14], &points[19]));
		springs.emplace_back(Spring(&points[14], &points[20]));
		
		springs.emplace_back(Spring(&points[19], &points[20]));

		springs.emplace_back(Spring(&points[5], &points[6]));
		springs.emplace_back(Spring(&points[5], &points[10]));
		springs.emplace_back(Spring(&points[5], &points[11]));
		
		springs.emplace_back(Spring(&points[10], &points[11]));
		springs.emplace_back(Spring(&points[10], &points[15]));
		springs.emplace_back(Spring(&points[10], &points[16]));
		
		springs.emplace_back(Spring(&points[15], &points[16]));
		springs.emplace_back(Spring(&points[15], &points[20]));
		springs.emplace_back(Spring(&points[15], &points[21]));
		
		springs.emplace_back(Spring(&points[20], &points[21]));
		
		springs.emplace_back(Spring(&points[6], &points[7]));
		springs.emplace_back(Spring(&points[6], &points[11]));
		springs.emplace_back(Spring(&points[6], &points[12]));
		
		springs.emplace_back(Spring(&points[11], &points[12]));
		springs.emplace_back(Spring(&points[11], &points[16]));
		springs.emplace_back(Spring(&points[11], &points[17]));
		
		springs.emplace_back(Spring(&points[16], &points[17]));
		springs.emplace_back(Spring(&points[16], &points[21]));
		springs.emplace_back(Spring(&points[16], &points[22]));
		
		springs.emplace_back(Spring(&points[21], &points[22]));
		
		springs.emplace_back(Spring(&points[7], &points[8]));
		springs.emplace_back(Spring(&points[7], &points[12]));
		springs.emplace_back(Spring(&points[7], &points[13]));
		
		springs.emplace_back(Spring(&points[12], &points[13]));
		springs.emplace_back(Spring(&points[12], &points[17]));
		springs.emplace_back(Spring(&points[12], &points[18]));
		
		springs.emplace_back(Spring(&points[17], &points[18]));
		springs.emplace_back(Spring(&points[17], &points[22]));
		springs.emplace_back(Spring(&points[17], &points[23]));
		
		springs.emplace_back(Spring(&points[22], &points[23]));
		
		springs.emplace_back(Spring(&points[8], &points[13]));
		springs.emplace_back(Spring(&points[13], &points[18]));
		springs.emplace_back(Spring(&points[18], &points[23]));



		/*
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
}

void SoftBodyObject::update() {
		for (Spring& s : springs) {
				s.update();
		}
		
		sf::Vector2f avgPosition;
		for (PointMass& p : points) {
				p.update(10);
				avgPosition += p.getPosition();
		}

		avgPosition.x /= points.size();
		avgPosition.y /= points.size();

		center = avgPosition;
		
}

void SoftBodyObject::render(sf::RenderWindow* window) {
		for (Spring& s : springs) {
				s.render(window);
		}
		
		for (PointMass& p : points) {
				p.render(window);
		}
}

void SoftBodyObject::dragObject(sf::Vector2i mousePosition) {
		// std::cout << "mouse: " << mousePosition.x << ", " << mousePosition.y << std::endl;
		// std::cout << "center: " << center.x << ", " << center.y << std::endl;
		
		float xForce = mousePosition.x - points[0].getPosition().x;
		float yForce = mousePosition.y - points[0].getPosition().y;

		xForce *= 0.0004;
		yForce *= 0.0004;

		/*
		for (PointMass& p : points) {
				p.setForce(xForce, yForce);
		}
		*/
		points[0].setForce(xForce, yForce);
}
