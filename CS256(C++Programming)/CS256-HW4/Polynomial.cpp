//Lee Jaeseung with Andrew Trang
//HW4
//Completed 2016 02 17

#include <sstream>
#include <cmath>

#include "Polynomial.h"

Polynomial::Polynomial() :size(1), coeff(new double[1]) {
	coeff[0] = 0;
}
Polynomial::Polynomial(double contents[], int size) : size(size), coeff(new double[size]) {
	for (int i = 0; i < size; ++i)
		coeff[i] = contents[i];
}
Polynomial::Polynomial(const Polynomial &other) {
	size = other.size;
	coeff = new double[size];
	for (int i = 0; i < size; ++i)
		coeff[i] = other.coeff[i];
}
Polynomial::Polynomial(int temp) : size(1), coeff(new double[1]) {
	coeff[0] = temp;
}
Polynomial::Polynomial(double temp) : size(1), coeff(new double[1]) {
	coeff[0] = temp;
}
Polynomial& Polynomial::operator=(const Polynomial &other) {
	if (this == &other)
		return *this;
	delete[] coeff;
	size = other.size;
	coeff = new double[size];
	for (int i = 0; i < size; ++i)
		coeff[i] = other.coeff[i];
	return *this;
}
Polynomial::~Polynomial() {
	delete coeff;
}
int Polynomial::getSize() const {
	return size;
}
int Polynomial::degree() const {
	int degree = 0;
	for (int i = 0; i < size; ++i)
		if (coeff[i] != 0)
			degree = i;
	return degree;
}
std::string Polynomial::str() const {
	std::stringstream temp;
	bool first = true;
	for (int i = 0; i < size; ++i)
		if (coeff[size - i - 1] != 0) {
			if (i != 0 && !first)
				temp << " ";
			if (coeff[size - i - 1] < 0 && first)
				temp << "-";
			else if (coeff[size - i - 1] < 0 && !first)
				temp << "- ";
			else if (coeff[size - i - 1] > 0 && !first)
				temp << "+ ";
			if (fabs(coeff[size - i - 1]) != 1)
				temp << fabs(coeff[size - i - 1]);
			if (size - i - 1 > 1)
				temp << "x^" << size - i - 1;
			else if (size - i - 1 == 1)
				temp << "x";
			if (first)
				first = false;
		}
	return temp.str();
}
double Polynomial::solve(double x) const {
	double val = 0;
	for (int i = 0; i < size; ++i)
		val += coeff[i] * pow(x, i);
	return val;
}
double& Polynomial::operator[](const int x) {
	if (x >= size) {
		double *temp = new double[x + 1];
		for (int i = 0; i < x + 1; ++i) {
			temp[i] = 0;
			for (int i = 0; i < size; ++i)
				temp[i] = coeff[i];
		}
		size = x + 1;
		delete[] coeff;
		coeff = temp;
	}
	return coeff[x];
}
Polynomial Polynomial::operator+(const Polynomial other) const {
	Polynomial temp;
	delete[] temp.coeff;
	temp.size = size > other.size ? size : other.size;
	temp.coeff = new double[temp.size];
	for (int i = 0; i < temp.size; ++i)
		temp.coeff[i] = 0;
	for (int i = 0; i < size; ++i)
		temp.coeff[i] = coeff[i];
	for (int i = 0; i < other.size; ++i)
		temp.coeff[i] += other.coeff[i];
	return temp;
}
Polynomial Polynomial::operator-(const Polynomial other) const {
	Polynomial temp;
	delete[] temp.coeff;
	temp.size = size > other.size ? size : other.size;
	temp.coeff = new double[temp.size];
	for (int i = 0; i < temp.size; ++i)
		temp.coeff[i] = 0;
	for (int i = 0; i < size; ++i)
		temp.coeff[i] = coeff[i];
	for (int i = 0; i < other.size; ++i)
		temp.coeff[i] -= other.coeff[i];
	return temp;
}
Polynomial Polynomial::operator*(const Polynomial other) const {
	Polynomial copy;
	copy.size = size + other.size - 1;
	delete[] copy.coeff;
	copy.coeff = new double[copy.size];
	for (int i = 0; i < copy.size; ++i)
		copy.coeff[i] = 0;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < other.size; ++j)
			copy.coeff[i + j] += coeff[i] * other.coeff[j];
	return copy;
}
Polynomial Polynomial::operator*(double x) const {
	Polynomial copy(*this);
	for (int i = 0; i < size; ++i)
		copy.coeff[i] *= x;
	return copy;
}
void Polynomial::operator+=(const Polynomial other) {
	Polynomial temp(*this);
	*this = temp + other;
}
void Polynomial::operator-=(const Polynomial other) {
	Polynomial temp(*this);
	*this = temp - other;
}
void Polynomial::operator*=(const Polynomial other) {
	Polynomial temp(*this);
	*this = temp * other;
}
bool Polynomial::operator==(const Polynomial other) const {
	if (size != other.size)
		return false;
	for (int i = 0; i < size; ++i)
		if (coeff[i] != other.coeff[i])
			return false;
	return true;
}
bool Polynomial::operator!=(const Polynomial other) const {
	return !operator==(other);
}
std::ostream& operator<<(std::ostream& os, Polynomial& s) {
	os << s.str();
	return os;
}