#include "Particle.h"

Particle::Particle() : position(Point()), velocity(Point()), radius(0), mass(0) {
}

Particle::Particle(Point p, double m) : position(p), velocity(Point()), radius(rand()%15), mass(m){
}

Point& Particle::getPos() {
	return position;
}
Point& Particle::getVel() {
	return velocity;
}
double& Particle::getRadius() {
	return radius;
}
double& Particle::getMass() {
	return mass;
}
void Particle::setPos(double x, double y) {
	position.setX(x);
	position.setY(y);
}
void Particle::setVel(double x, double y) {
	position.setX(x);
	position.setY(y);
}
void Particle::setRadius(double r) {
	radius = r;
}
void Particle::setMass(double m) {
	mass = m;
}

