// completed on 2016-02-12
// EX5
// Jaeseung Lee with Andrew Trang

#ifndef RAT_H
#define RAT_H

#include <iostream>
#include <string>
#include <sstream>

class RatTester;

class rat
{
	friend class RatTester;

private:
	int num;
	int den;
	void reduce();

public:
	rat(); //3a default init to 0/1
	rat(int num); //3b makes the frac to n/1
	rat(int num, int den); //3c creates n/d , if()
	int getNum() const;
	int getDen() const;
	rat reciprocal() const;
	rat operator+(const rat& right) const;
	rat operator-(const rat& right) const;
	rat operator*(const rat& right) const;
	rat operator/(const rat& right) const;
	bool operator==(const rat& right) const;
	bool operator!=(const rat& right) const;
	bool operator<(const rat& right) const;
	bool operator<=(const rat& right) const;
	bool operator>(const rat& right) const;
	bool operator>=(const rat& right) const;
	std::string str() const;
};
#endif