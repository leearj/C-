//Lee Jaeseung with Andrew Trang
//HW5
//Due 3-12-2016

#include "Point.h"

using namespace std;
Point::Point() {
	x = 0;
	y = 0;
}
Point::Point(double d1, double d2) : x(d1), y(d2) {
}
double& Point::getX() {
	return x;
}
double& Point::getY() {
	return y;
}
void Point::setX(double num) {
	x = num;
}
void Point::setY(double num) {
	y = num;
}