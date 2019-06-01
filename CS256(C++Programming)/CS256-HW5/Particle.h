//Lee Jaeseung with Andrew Trang
//HW5
//Due 3-12-2016

#include "Point.h"
#include <stdlib.h>

class Particle {
private:
	Point position, velocity;
	double radius, mass;

public:
	Particle();
	Particle(Point x, double m);
	Point& getPos();
	Point& getVel();
	double& getRadius();
	double& getMass() ;
	void setPos(double x, double y);
	void setVel(double x, double y);
	void setRadius(double r);
	void setMass(double m);
};