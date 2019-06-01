//Lee Jaeseung with Andrew Trang
//HW4
//Completed 2016 02 17

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>

class PolyTester;

class Polynomial
{
	friend class PolyTester;

private:
	int size;
	double *coeff;
public:
	Polynomial();
	Polynomial(double contents[], int size);
	Polynomial(const Polynomial &other);
	Polynomial(int temp);
	Polynomial(double temp);
	Polynomial& operator=(const Polynomial &other);
	~Polynomial();
	int getSize() const;
	int degree() const;
	std::string str() const;
	double solve(double x) const;
	double& operator[](const int x);
	Polynomial operator+(const Polynomial other) const;
	Polynomial operator-(const Polynomial other) const;
	Polynomial operator*(const Polynomial other) const;
	Polynomial operator*(double x) const;
	void operator+=(const Polynomial other);
	void operator-=(const Polynomial other);
	void operator*=(const Polynomial other);
	bool operator==(const Polynomial other) const;
	bool operator!=(const Polynomial other) const;
	friend std::ostream& operator<<(std::ostream& os, Polynomial& s);
};
#endif