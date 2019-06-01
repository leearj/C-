// Jaeseung Lee
// Example 9
// Completed 1/15/2016

#include "Chromosome.h"

Chromosome::Chromosome(std::string d) : data(d){}

std::string Chromosome::getData() const {
	return data;
}

Chromosome Chromosome::mutate() const {
	Chromosome temp(data);
	int index = rand()%(temp.data.length()-1);
	if (rand() % 2 == 0)
		if (temp.data[index] == 122)
			temp.data[index] = 97;
		else
			temp.data[index] = ++temp.data[index];
	else
		if (temp.data[index] == 97)
			temp.data[index] = 122;
		else
			temp.data[index] = --temp.data[index];
	return temp;
}

Chromosome Chromosome::crossover(const Chromosome& c) const {
	Chromosome temp(data);
	for (int i = rand()%temp.data.length(); i < temp.data.length(); ++i)
		temp.data[i] = c.data[i];
	return temp;
}

int Chromosome::fitness(const std::string& target) const {
	int diff = 0;
	for (int i = 0; i < data.size(); i++) {
		int change = std::abs(data[i] - target[i]);
		if (change > 13)
			change = 26 - change;
		diff += change;
	}
	return diff;
}

std::ostream& operator<<(std::ostream& os, const Chromosome& c) {
	os << c.getData();
	return os;
}