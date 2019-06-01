// completed on 2016-02-12
// EX5
// Jaeseung Lee with Andrew Trang

#include "rat.h"

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int lcm(int x, int y)
{
	return (x * y) / gcd(x, y);
}

//Constructors
rat::rat() : num(0), den(1) {}; //3a
rat::rat(int n) : num(n), den(1) {}; //3b
rat::rat(int n, int d) : num(n), den(d) 
{ if (d == 0) { num = 0; den = 1; } reduce(); }; //3c

//Getter
int rat:: getNum() const {
	return num;
}
int rat::getDen() const {
	return den;
}
 
//reduce() diving by their GCD. eg) 10/2 -> 5/1
void rat::reduce() {
	int g = gcd(num, den);
	num /= g;
	den /= g;
	if (den < 0) {
		num = -num;
		den = -den;
	}
}

//reciprocal() const
rat rat::reciprocal() const {
	return rat::rat(rat::den, rat::num);
}

rat rat::operator+(const rat& right) const {
	return rat::rat((rat::num*right.den) + (right.num*rat::den), rat::den * right.den);
}
rat rat::operator-(const rat& right) const {
	return rat::rat((rat::num*right.den) - (right.num*rat::den), rat::den * right.den);
}
rat rat::operator*(const rat& right) const {
	return rat::rat(rat::num*right.num, rat::den*right.den);
}
rat rat::operator/(const rat& right) const {
	return rat::rat(rat::num*right.den, rat::den*right.num);
}
bool rat::operator==(const rat& right) const {
	return rat::num*right.den == rat::den*right.num;
}
bool rat::operator!=(const rat& right) const {
	return rat::num*right.den != rat::den*right.num;
}
bool rat::operator<(const rat& right) const {
	return rat::num*right.den < rat::den*right.num;
}
bool rat::operator<=(const rat& right) const {
	return rat::num*right.den <= rat::den*right.num;
}
bool rat::operator>(const rat& right) const {
	return rat::num*right.den > rat::den*right.num;
}
bool rat::operator>=(const rat& right) const {
	return rat::num*right.den >= rat::den*right.num;
}
std::string rat::str() const {
	std::stringstream ss;
	ss << rat::num << "/" << rat::den;
	return ss.str();
}